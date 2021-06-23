/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Loading
*/

#include <fstream>
#include <memory>
#include <mutex>
#include <thread>
#include <atomic>
#include <unordered_map>
#include "Scene/Loading.hpp"

bmb::scene::Loading::Loading(void)
    : Scene() {
    _images["logo"]
    .load("assets/png/logo.png")
    .setColor(bmb::rlib::color::White);
}

bmb::scene::Loading::~Loading(void) {
    unload();
}

void bmb::scene::Loading::load(void) {
    _isLoaded = true;
}

void bmb::scene::Loading::unload(void) {
    _isLoaded = false;
}

void bmb::scene::Loading::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    load();
}

void bmb::scene::Loading::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    (void)cManager;
    (void)audioManager;

    loadTexture(window);
    switchScene(bmb::scene::SCENE_HOW_TO_PLAY);
}

void bmb::scene::Loading::loadTexture(uniqueWindow &window) {
    std::ifstream ifs{CSV_PATH_TEXTURE};
    std::string line;
    std::vector<std::string> names;
    std::vector<std::string> tmp;
    std::vector<std::string> imagePaths;
    std::vector<Image> images;
    std::string status;
    std::mutex mu;
    std::atomic<bool> isImagesLoaded = false;

    if (!ifs.is_open())
        return;
    while (std::getline(ifs, line)) {
        tmp = tools::split(line, ",");
        names.push_back(tmp[0]);
        imagePaths.push_back(tmp[1]);
    }
    ifs.close();

    auto f_load_image = [&imagePaths, &images, &status, &mu, &isImagesLoaded]() {
        for (const auto &it : imagePaths) {
            images.push_back(LoadImage(it.c_str()));
            std::lock_guard<std::mutex> guard(mu);
            status = it;
        }
        isImagesLoaded = true;
    };

    std::thread t{f_load_image};
    while (!isImagesLoaded) {
        window->beginDrawing();
        window->clearBackground(bmb::rlib::color::White);
        _images["logo"].display();
        std::string msg = "Loading: " + status;
        bmb::rlib::EText loading(msg, Vector2f(250, 500), 24, bmb::rlib::color::Black);
        loading.draw();
        window->endDrawing();
    }
    t.join();
    for (size_t i = 0; i < images.size(); i++) {
        bmb::sys->textures()[names[i]] = std::make_shared<Texture>(LoadTextureFromImage(images[i]));
        UnloadImage(images[i]);
    }
    bmb::sys->fonts()["ka1"] = std::make_shared<Font>(LoadFont("assets/font/ka1.ttf"));
}