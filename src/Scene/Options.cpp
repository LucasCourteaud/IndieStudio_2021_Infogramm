/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Options
*/

#include "Scene/Options.hpp"

bmb::scene::Options::Options(void)
    : Scene() {
        _timer["1:00"] = "2:00";
        _timer["2:00"] = "3:00";
        _timer["3:00"] = "1:00";
        _unTimer["1:00"] = "3:00";
        _unTimer["2:00"] = "1:00";
        _unTimer["3:00"] = "2:00";
}

bmb::scene::Options::~Options(void) {
    unload();
}

void bmb::scene::Options::load(void) {
    float x = 0.f;
    float y = 0.f;
    std::string text("");

    _isLoaded = true;
    _mainCamera
    .setPosition(Vector3f(0.f, 310.f, 310.f));

    bmb::widget::Button removePlayer;
    x = 0.f;
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 15);
    removePlayer
    .setString("-")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button addPlayer;
    x = static_cast<float>(_sizeWindow._x) - tools::percentage(static_cast<float>(_sizeWindow._x), 33);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 15);
    addPlayer
    .setString("+")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    text = "Number of player";
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(text.c_str(), 40)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 5);
    bmb::rlib::EText nbPlayerText(text, Vector2f(), 40);
    nbPlayerText
    .setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(std::to_string(bmb::sys->nbPlayer()).c_str(), 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 15);
    bmb::rlib::EText nbPlayer(std::to_string(bmb::sys->nbPlayer()), Vector2f(), 60);
    nbPlayer
    .setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    bmb::widget::Button removeScore;
    x = 0.f;
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 40);
    removeScore
    .setString("-")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button addScore;
    x = static_cast<float>(_sizeWindow._x) - tools::percentage(static_cast<float>(_sizeWindow._x), 33);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 40);
    addScore
    .setString("+")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    text = "Number of matche(s)";
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(text.c_str(), 40)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 30);
    bmb::rlib::EText nbScoreText(text, Vector2f(), 40);
    nbScoreText
    .setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(std::to_string(bmb::sys->nbPlayer()).c_str(), 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 40);
    bmb::rlib::EText nbScore(std::to_string(bmb::sys->maxScore()), Vector2f(), 60);
    nbScore
    .setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    bmb::widget::Button reduceTime;
    x = 0.f;
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 70);
    reduceTime
    .setString("<-")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button addTime;
    x = static_cast<float>(_sizeWindow._x) - tools::percentage(static_cast<float>(_sizeWindow._x), 33);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 70);
    addTime
    .setString("->")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 33), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    text = "Timer";
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(text.c_str(), 40)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 60);
    bmb::rlib::EText timeText(text, Vector2f(), 40);
    timeText
    .setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(bmb::sys->time().c_str(), 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 70);
    bmb::rlib::EText time(bmb::sys->time(), Vector2f(), 60);
    time
    .setPosition(Vector2f(x, y))
    .setColor(bmb::rlib::color::White);

    bmb::widget::Button back;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 8) - (MeasureText("Back", 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 90);
    back
    .setString("Back")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 20), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button next;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 90) - (MeasureText("Next", 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 90);
    next
    .setString("Next")
    .setStringSize(30)
    .setStringColor(bmb::rlib::color::White)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 20), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    _buttons["addPlayer"]       = addPlayer;
    _buttons["removePlayer"]    = removePlayer;
    _texts["nbPlayerText"]      = nbPlayerText;
    _texts["nbPlayer"]          = nbPlayer;
    _buttons["addScore"]        = addScore;
    _buttons["removeScore"]     = removeScore;
    _texts["nbScoreText"]       = nbScoreText;
    _texts["nbScore"]           = nbScore;
    _buttons["addTime"]         = addTime;
    _buttons["reduceTime"]      = reduceTime;
    _texts["timeText"]          = timeText;
    _texts["time"]              = time;
    _buttons["back"]            = back;
    _buttons["next"]            = next;
}

void bmb::scene::Options::unload(void) {
    _isLoaded = false;
    _buttons.clear();
    _texts.clear();
}

void bmb::scene::Options::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    cManager[0]->setModeDisplay(bmb::character::CURSOR);
    load();
}

void bmb::scene::Options::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter player = cManager[0];
    bmb::event::InputUser input = player->getInput();

    audioManager.updateMusic("menu");

    if (player->getCursor().getPosition()._x < 0.f)
        player->getCursor().setPosition(Vector2f(0.f, player->getCursor().getPosition()._y));
    if (player->getCursor().getPosition()._x > _sizeWindow._x - player->getCursor().getSize()._x)
        player->getCursor().setPosition(Vector2f(_sizeWindow._x - player->getCursor().getSize()._x, player->getCursor().getPosition()._y));
    if (player->getCursor().getPosition()._y < 0.f)
        player->getCursor().setPosition(Vector2f(player->getCursor().getPosition()._x, 0.f));
    if (player->getCursor().getPosition()._y > _sizeWindow._y - player->getCursor().getSize()._y)
        player->getCursor().setPosition(Vector2f(player->getCursor().getPosition()._x, _sizeWindow._y - player->getCursor().getSize()._y));

    player->move(input);
    if (_buttons["removePlayer"].isHover(player->getCursor()) == 1 ||
        _buttons["addPlayer"].isHover(player->getCursor()) == 1 ||
        _buttons["removeScore"].isHover(player->getCursor()) == 1 ||
        _buttons["addScore"].isHover(player->getCursor()) == 1 ||
        _buttons["addTime"].isHover(player->getCursor()) == 1 ||
        _buttons["reduceTime"].isHover(player->getCursor()) == 1 ||
        _buttons["back"].isHover(player->getCursor()) == 1 ||
        _buttons["next"].isHover(player->getCursor()) == 1)
        audioManager.playSound("hover", true);

    if (_buttons["removePlayer"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (bmb::sys->nbPlayer() > 2) {
            bmb::sys->nbPlayer() -= 1;
            _texts["nbPlayer"].setString(std::to_string(bmb::sys->nbPlayer()));
            audioManager.playSound("click", true);
        } else
            audioManager.playSound("limit", true);
    }
    if (_buttons["addPlayer"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (bmb::sys->nbPlayer() < 4) {
            bmb::sys->nbPlayer() += 1;
            _texts["nbPlayer"].setString(std::to_string(bmb::sys->nbPlayer()));
            audioManager.playSound("click", true);
        } else
            audioManager.playSound("limit", true);
    }
    if (_buttons["removeScore"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (bmb::sys->maxScore() > 1) {
            bmb::sys->maxScore() -= 1;
            _texts["nbScore"].setString(std::to_string(bmb::sys->maxScore()));
            audioManager.playSound("click", true);
        } else
            audioManager.playSound("limit", true);
        audioManager.playSound("limit", true);
    }
    if (_buttons["addScore"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        if (bmb::sys->maxScore() < 5) {
            bmb::sys->maxScore() += 1;
            _texts["nbScore"].setString(std::to_string(bmb::sys->maxScore()));
            audioManager.playSound("click", true);
        } else
            audioManager.playSound("limit", true);
        audioManager.playSound("limit", true);
    }
    if (_buttons["reduceTime"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        bmb::sys->time() = _unTimer[bmb::sys->time()];
        _texts["time"].setString(bmb::sys->time());
        audioManager.playSound("click", true);
    }
    if (_buttons["addTime"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        bmb::sys->time() = _timer[bmb::sys->time()];
        _texts["time"].setString(bmb::sys->time());
        audioManager.playSound("click", true);
    }
    if (_buttons["back"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_MENU);
    }
    if (_buttons["next"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_SELECT_MAP);
    }
    window->clearBackground(bmb::rlib::color::White);
    window->beginDrawing();
    DrawTexture(*bmb::sys->textures()[std::to_string(_sizeWindow._x) + "_" + std::to_string(_sizeWindow._y)], 0, 0, WHITE);
    for (auto it : _texts)
        it.second.draw();
    for (auto it : _buttons)
        it.second.display();
    player->display();
    window->endDrawing();
}
