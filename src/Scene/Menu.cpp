/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Menu
*/

#include "Scene/Menu.hpp"

bmb::scene::Menu::Menu(void)
    : Scene() {
}

bmb::scene::Menu::~Menu(void) {
    std::cout << "[BMB] : Destroy Scene Menu." << std::endl;
    unload();
}

void bmb::scene::Menu::load(void) {
    float x = 0.f;
    float y = 0.f;

    _timerMove = 0;
    _isLoaded = true;
    _mainCamera
    .setPosition(Vector3f(0.f, 150.f, 325.f))
    .setTarget(Vector3f(0.f, 150.f, 0.f))
    .setCameraMode(CAMERA_ORBITAL);

    bmb::widget::Button play;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 35);
    play
    .setString("Play")
    .setStringColor(bmb::rlib::color::White)
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(static_cast<float>(_sizeWindow._x), 80), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button exit;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 75);
    exit
    .setString("Exit")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(static_cast<float>(_sizeWindow._x), 80), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button settings;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 55);
    settings
    .setString("Settings")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(static_cast<float>(_sizeWindow._x), 80), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText("Bomberman", 80)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 10);
    Vector2f pos = {x, y};
    bmb::rlib::EText title("Bomberman", pos, 60);
    title.setPosition(pos)
    .setColor(bmb::rlib::color::White);

    _buttons["play"]        = play;
    _buttons["exit"]        = exit;
    _buttons["settings"]    = settings;
    _texts["title"]         = title;
    _clock.start();
}

void bmb::scene::Menu::unload(void) {
    _isLoaded = false;
    _buttons.clear();
    _texts.clear();
}

void bmb::scene::Menu::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    cManager[0]->setModeDisplay(bmb::character::CURSOR);
    float cursorSize = tools::percentage(static_cast<float>(_sizeWindow._x), 2);
    cManager[0]->getCursor().setSize(Vector2f(cursorSize, cursorSize));
    load();
}

void bmb::scene::Menu::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter toto = cManager[0];
    bmb::event::InputUser input = toto->getInput();
    audioManager.updateMusic("menu");

    _mainCamera.update();

    toto->move(input);
    if (toto->getCursor().getPosition()._x < 0.f)
        toto->getCursor().setPosition(Vector2f(0.f, toto->getCursor().getPosition()._y));
    if (toto->getCursor().getPosition()._x > _sizeWindow._x - toto->getCursor().getSize()._x)
        toto->getCursor().setPosition(Vector2f(_sizeWindow._x - toto->getCursor().getSize()._x, toto->getCursor().getPosition()._y));
    if (toto->getCursor().getPosition()._y < 0.f)
        toto->getCursor().setPosition(Vector2f(toto->getCursor().getPosition()._x, 0.f));
    if (toto->getCursor().getPosition()._y > _sizeWindow._y - toto->getCursor().getSize()._y)
        toto->getCursor().setPosition(Vector2f(toto->getCursor().getPosition()._x, _sizeWindow._y - toto->getCursor().getSize()._y));

    if (_buttons["play"].isHover(toto->getCursor()) == 1 ||
        _buttons["exit"].isHover(toto->getCursor()) == 1 ||
        _buttons["settings"].isHover(toto->getCursor()) == 1)
        audioManager.playSound("hover", true);

    if (_buttons["play"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_OPTIONS);
    }

    if (_buttons["exit"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_EXIT);
    }

    if (_buttons["settings"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_SETTINGS);
    }

    window->clearBackground(bmb::rlib::color::Black);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    _mainCamera.endMode3D();
    DrawTexture(*bmb::sys->textures()[std::to_string(_sizeWindow._x) + "_" + std::to_string(_sizeWindow._y)], 0, 0, WHITE);
    for (auto it : _texts)
        it.second.draw(*bmb::sys->fonts()["ka1"]);
    for (auto it : _buttons)
        it.second.display();
    toto->display();
    window->endDrawing();
}