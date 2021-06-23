/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Transition
*/

#include "Scene/Transition.hpp"

bmb::scene::Transition::Transition(void)
    : Scene() {}

bmb::scene::Transition::~Transition(void) {
    unload();
}

void bmb::scene::Transition::load(void) {
    float x = 0.f;
    float y = 0.f;

    _isLoaded = true;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText("Transition...", 100)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 50) - 100;
    Vector2f pos = {x, y};
    bmb::rlib::EText text("Loading...");
    text
    .setPosition(pos)
    .setFontSize(100);

    _texts["text"] = text;
}

void bmb::scene::Transition::unload(void) {
    _isLoaded = false;
    _texts.clear();
    _buttons.clear();
}

void bmb::scene::Transition::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    (void)cManager;
    _sizeWindow = window->getSize();
    load();
}

void bmb::scene::Transition::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    (void)cManager;
    (void)audioManager;
    window->clearBackground(bmb::rlib::color::White);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    _mainCamera.endMode3D();
    for (auto it : _texts)
        it.second.draw();
    window->endDrawing();
}