/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Settings
*/

#include "Scene/Settings.hpp"
#include "encapsulation/Window/EWindow.hpp"

bmb::scene::Settings::Settings(void)
    : Scene() {
    _screenMode["ON"]  = "OFF";
    _screenMode["OFF"] = "ON";
}

bmb::scene::Settings::Settings::~Settings(void) {
    std::cout << "[BMB] : Destroy Scene Settings." << std::endl;
    unload();
}

void bmb::scene::Settings::load(void) {
    float x = 0.f;
    float y = 0.f;

    _isLoaded = true;
    _mainCamera
    .setPosition(Vector3f(0.f, 310.f, 310.f));


    bmb::widget::Button resolution;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (static_cast<float>(_sizeWindow._x)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 10);
    resolution
    .setString(std::to_string(bmb::sys->resolution()._x) + "x" + std::to_string(bmb::sys->resolution()._y))
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(static_cast<float>(_sizeWindow._x), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button fullscreen;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (static_cast<float>(_sizeWindow._x)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 30);
    fullscreen
    .setString(bmb::sys->fullscreen())
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(static_cast<float>(_sizeWindow._x), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button lowerVolumeMusic;
    x = 0.f;
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 50);
    lowerVolumeMusic
    .setString("-")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button upVolumeMusic;
    x = static_cast<float>(_sizeWindow._x) - tools::percentage(static_cast<float>(_sizeWindow._x), 33);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 50);
    upVolumeMusic
    .setString("+")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button lowerVolumeSound;
    x = 0.f;
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 70);
    lowerVolumeSound
    .setString("-")
    .setStringColor(bmb::rlib::color::White)
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button upVolumeSound;
    x = static_cast<float>(_sizeWindow._x) - tools::percentage(static_cast<float>(_sizeWindow._x), 33);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 70);
    upVolumeSound
    .setString("+")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button back;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 90) - (static_cast<float>(_sizeWindow._x)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 90);
    back
    .setString("Back")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 20), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(std::to_string(static_cast<int>(bmb::sys->soundVolume() * 10)).c_str(), 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 70);
    bmb::rlib::EText volumeSound(std::to_string(static_cast<int>(bmb::sys->soundVolume() * 10)), Vector2f(), 60);
    volumeSound.setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(std::to_string(static_cast<int>(bmb::sys->musicVolume() * 10)).c_str(), 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 50);
    bmb::rlib::EText volumeMusic(std::to_string(static_cast<int>(bmb::sys->musicVolume() * 10)), Vector2f(), 60);
    volumeMusic.setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    _buttons["resolution"]       = resolution;
    _buttons["fullscreen"]       = fullscreen;
    _buttons["lowerVolumeSound"] = lowerVolumeSound;
    _buttons["upVolumeSound"]    = upVolumeSound;
    _buttons["lowerVolumeMusic"] = lowerVolumeMusic;
    _buttons["upVolumeMusic"]    = upVolumeMusic;
    _buttons["back"]             = back;
    _texts["volumeSound"]        = volumeSound;
    _texts["volumeMusic"]        = volumeMusic;
}

void bmb::scene::Settings::unload(void) {
    _isLoaded = false;
    _buttons.clear();
    _texts.clear();
}

void bmb::scene::Settings::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    float cursorSize = tools::percentage(static_cast<float>(_sizeWindow._x), 2);
    cManager[0]->getCursor().setSize(Vector2f(cursorSize, cursorSize));
    load();
}

void bmb::scene::Settings::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter toto = cManager[bmb::sys->playerPaused()];
    bmb::event::InputUser input = toto->getInput();

    audioManager.updateMusic("menu");

    toto->move(input);

    if (toto->getCursor().getPosition()._x < 0.f)
        toto->getCursor().setPosition(Vector2f(0.f, toto->getCursor().getPosition()._y));
    if (toto->getCursor().getPosition()._x > _sizeWindow._x - toto->getCursor().getSize()._x)
        toto->getCursor().setPosition(Vector2f(_sizeWindow._x - toto->getCursor().getSize()._x, toto->getCursor().getPosition()._y));
    if (toto->getCursor().getPosition()._y < 0.f)
        toto->getCursor().setPosition(Vector2f(toto->getCursor().getPosition()._x, 0.f));
    if (toto->getCursor().getPosition()._y > _sizeWindow._y - toto->getCursor().getSize()._y)
        toto->getCursor().setPosition(Vector2f(toto->getCursor().getPosition()._x, _sizeWindow._y - toto->getCursor().getSize()._y));

    if (_buttons["back"].isHover(toto->getCursor()) == 1 ||
        _buttons["resolution"].isHover(toto->getCursor()) == 1 ||
        _buttons["fullscreen"].isHover(toto->getCursor()) == 1 ||
        _buttons["lowerVolumeMusic"].isHover(toto->getCursor()) == 1 ||
        _buttons["upVolumeMusic"].isHover(toto->getCursor()) == 1 ||
        _buttons["lowerVolumeSound"].isHover(toto->getCursor()) == 1 ||
        _buttons["upVolumeSound"].isHover(toto->getCursor()) == 1)
        audioManager.playSound("hover", true);

    if (_buttons["lowerVolumeMusic"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (audioManager.getMusicVolume() > 0.1) {
            audioManager.playSound("click", true);
            audioManager.addMusicVolume(-0.1f);
            bmb::sys->musicVolume() = audioManager.getMusicVolume();
            _texts["volumeMusic"].setString(std::to_string(static_cast<int>(bmb::sys->musicVolume() * 10)));
        } else
            audioManager.playSound("limit", true);
    }

    if (_buttons["upVolumeMusic"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (audioManager.getMusicVolume() < 1) {
            audioManager.playSound("click", true);
            audioManager.addMusicVolume(0.1f);
            bmb::sys->musicVolume() = audioManager.getMusicVolume();
            _texts["volumeMusic"].setString(std::to_string(static_cast<int>(bmb::sys->musicVolume() * 10)));
        } else
            audioManager.playSound("limit", true);
    }

    if (_buttons["lowerVolumeSound"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (audioManager.getSoundVolume() > 0.1) {
            audioManager.addSoundVolume(-0.1f);
            bmb::sys->soundVolume() = audioManager.getSoundVolume();
            _texts["volumeSound"].setString(std::to_string(static_cast<int>(bmb::sys->soundVolume() * 10)));
            audioManager.playSound("click", true);
        } else
            audioManager.playSound("limit", true);
    }

    if (_buttons["upVolumeSound"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (audioManager.getSoundVolume() < 1) {
            audioManager.addSoundVolume(0.1f);
            bmb::sys->soundVolume() = audioManager.getSoundVolume();
            _texts["volumeSound"].setString(std::to_string(static_cast<int>(bmb::sys->soundVolume() * 10)));
            audioManager.playSound("click", true);
        } else
            audioManager.playSound("limit", true);
    }

    if (_buttons["resolution"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        bmb::sys->resolution() = getResolution(bmb::sys->resolution());
        window->setSize(bmb::sys->resolution());
        switchScene(bmb::scene::SCENE_SETTINGS);
    }

    if (_buttons["fullscreen"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        bmb::sys->fullscreen() = _screenMode[bmb::sys->fullscreen()];
        window->fullscreen();
        switchScene(bmb::scene::SCENE_SETTINGS);
    }

    if (_buttons["back"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::index->lastValue());
    }

    window->clearBackground(bmb::rlib::color::Black);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    _mainCamera.endMode3D();
    DrawTexture(*bmb::sys->textures()[std::to_string(_sizeWindow._x) + "_" + std::to_string(_sizeWindow._y)], 0, 0, WHITE);
    for (auto it : _texts)
        it.second.draw();
    for (auto it : _buttons)
        it.second.display();
    toto->display();
    window->endDrawing();
}

bmb::rlib::EVector2<int> bmb::scene::Settings::getResolution(const bmb::rlib::EVector2<int> &oldResolution) {
    if (oldResolution == R_800x600)
        return R_1366x728;
    if (oldResolution == R_1366x728)
        return R_1600x1200;
    if (oldResolution == R_1600x1200)
        return R_1920x1080;
    if (oldResolution == R_1920x1080)
        return R_800x600;
    return oldResolution;
}
