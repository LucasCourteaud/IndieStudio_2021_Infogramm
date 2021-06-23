/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Pause
*/

#include "Scene/Pause.hpp"
#include "encapsulation/Window/EWindow.hpp"

bmb::scene::Pause::Pause(void) {
}

bmb::scene::Pause::Pause::~Pause(void) {
    std::cout << "[BMB] : Destroy Scene Pause." << std::endl;
    unload();
}

void bmb::scene::Pause::load(void) {
    float x = 0.f;
    float y = 0.f;

    _isLoaded = true;
    _mainCamera
    .setPosition(Vector3f(0.f, 310.f, 310.f));

    bmb::widget::Button resume;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 20);
    resume
    .setString("Resume")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(_sizeWindow._x, tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button restart;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 40);
    restart
    .setString("Restart")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(_sizeWindow._x, tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button settings;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 60);
    settings
    .setString("Settings")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(_sizeWindow._x, tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button menu;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (_sizeWindow._x/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 80);
    menu
    .setString("Menu")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(_sizeWindow._x, tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    _buttons["resume"]  = resume;
    _buttons["restart"]  = restart;
    _buttons["settings"] = settings;
    _buttons["menu"]    = menu;
}

void bmb::scene::Pause::unload(void) {
    _isLoaded = false;
    _buttons.clear();
    _texts.clear();
}

void bmb::scene::Pause::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    float cursorSize = tools::percentage(static_cast<float>(_sizeWindow._x), 2);
    for (int i = 0; i < cManager.size(); i++) {
        cManager[i]->setModeDisplay(bmb::character::CURSOR);
        cManager[i]->getCursor().setSize(Vector2f(cursorSize, cursorSize));
    }
    load();
}

void bmb::scene::Pause::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter player = cManager[bmb::sys->playerPaused()];
    bmb::event::InputUser input = player->getInput();

    audioManager.updateMusic("menu");

    player->move(input);
    if (player->getCursor().getPosition()._x < 0)
        player->getCursor().setPosition(Vector2f(0, player->getCursor().getPosition()._y));
    if (player->getCursor().getPosition()._x > window->getSize()._x)
        player->getCursor().setPosition(Vector2f(window->getSize()._x, player->getCursor().getPosition()._y));
    if (player->getCursor().getPosition()._y < 0)
        player->getCursor().setPosition(Vector2f(player->getCursor().getPosition()._x, 0));
    if (player->getCursor().getPosition()._y > window->getSize()._y)
        player->getCursor().setPosition(Vector2f(player->getCursor().getPosition()._x, window->getSize()._y));

    if (_buttons["resume"].isHover(player->getCursor()) == 1 ||
        _buttons["restart"].isHover(player->getCursor()) == 1 ||
        _buttons["settings"].isHover(player->getCursor()) == 1 ||
        _buttons["menu"].isHover(player->getCursor()) == 1)
        audioManager.playSound("hover", true);

    if (input.getButton() == bmb::rlib::control::BUTTON_1 && input.type() == bmb::event::PRESSED) {
        audioManager.playSound("click", true);
        player->getCursor().setPosition(Vector2f(0.f, 0.f));
    }

    if (input.getButton() == bmb::rlib::control::START && input.type() == bmb::event::PRESSED) {
        switchScene(bmb::scene::SCENE_GAME);
        audioManager.playSound("click", true);
    }

    if (_buttons["resume"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_GAME);
    }

    if (_buttons["restart"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        bmb::MapParser::fileToMap("map/" + bmb::sys->map().getName() + ".bmb", bmb::sys->map());
        auto map = bmb::sys->map();
        bmb::sys->restart() = true;
        for (auto it : cManager.get()) {
            it->setModeDisplay(bmb::character::MODEL);
            it->setState(true);
            it->respawn();
            it->resetBombs();
            it->setSpeedBonus(0);
            it->rangeBomb() = DEFAULT_RANGE_EXPLOSION;
            std::vector<std::shared_ptr<bmb::block::Block>> _listSpawn;

            for (int i = 0; i < map.size(); i++)
            for (int j = 0; j < map[i].size(); j++)
                if (map[i][j]->type() == bmb::block::SPAWN)
                    _listSpawn.push_back(map[i][j]);
            for (int i = 0; i < cManager.size(); i++) {
                cManager[i]->setSpawn(_listSpawn[i]->getPosition());
                _listSpawn[i]->getModel().setColor(cManager[i]->getModel().getColor());
                cManager[i]->respawn();
            }
        }
        switchScene(bmb::scene::SCENE_GAME);
    }

    if (_buttons["settings"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_SETTINGS);
    }

    if (_buttons["menu"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        bmb::sys->restart() = true;
        audioManager.playSound("click", true);
        bmb::sys->playerPaused() = 0;
        cManager.reset();
        switchScene(bmb::scene::SCENE_MENU);
    }
    window->clearBackground(bmb::rlib::color::White);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    DrawGrid(100, 10.f);
    _mainCamera.endMode3D();
    for (auto it : _texts)
        it.second.draw();
    for (auto it : _buttons)
        it.second.display();
    player->display();
    window->endDrawing();
}