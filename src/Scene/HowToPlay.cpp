/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** HowToPlay
*/

#include "Scene/HowToPlay.hpp"

bmb::scene::HowToPlay::HowToPlay(void)
    : Scene() {
    _index = 0;
    _images["ps"].load("assets/png/pscontroller.png");
    _images["xbox"].load("assets/png/XBOX_Controller.png");
    _images["infos"].load("assets/png/bonus.png");
}

bmb::scene::HowToPlay::~HowToPlay(void) {
    std::cout << "[BMB] : Destroy Scene HowToPlay." << std::endl;
    unload();
}

void bmb::scene::HowToPlay::load(void) {
    _isLoaded = true;
}

void bmb::scene::HowToPlay::unload(void) {
    _isLoaded = false;
}

void bmb::scene::HowToPlay::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    cManager[0]->setModeDisplay(bmb::character::CURSOR);
    load();
}

void bmb::scene::HowToPlay::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter player = cManager[0];
    bmb::event::InputUser input = player->getInput();
    std::vector<std::string> controller = {"ps", "xbox", "infos"};

    if (input.getButton() == bmb::rlib::control::BUTTON_2 && input.type() == bmb::event::PRESSED) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_MENU);
    }
    if (input.getButton() == bmb::rlib::control::TRIGGER_LEFT_FRONT && input.type() == bmb::event::PRESSED) {
        (_index > 0) ? _index-- : _index = controller.size() - 1;
        audioManager.playSound("click", true);
    }
    if (input.getButton() == bmb::rlib::control::TRIGGER_RIGHT_FRONT && input.type() == bmb::event::PRESSED) {
        (_index < controller.size() - 1) ? _index++ : _index = 0;
        audioManager.playSound("click", true);
    }
    window->clearBackground(bmb::rlib::color::White);
    window->beginDrawing();
    _images[controller[_index]].display();
    window->endDrawing();
}