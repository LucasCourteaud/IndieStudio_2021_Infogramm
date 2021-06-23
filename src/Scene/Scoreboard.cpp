/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Scoreboard
*/

#include "Scene/Scoreboard.hpp"

bmb::scene::Scoreboard::Scoreboard(void)
    : Scene() {
}

bmb::scene::Scoreboard::~Scoreboard(void) {
    std::cout << "[BMB] : Destroy Scene Scoreboard." << std::endl;
    unload();
}

void bmb::scene::Scoreboard::load(void) {
    float x = 0.f;
    float y = 0.f;
    std::string text;

    _isLoaded = true;
    _mainCamera
    .setPosition(Vector3f(0.f, 150.f, 325.f))
    .setTarget(Vector3f(0.f, 150.f, 0.f))
    .setCameraMode(CAMERA_ORBITAL);

    bmb::widget::Button menu;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (static_cast<float>(_sizeWindow._x) / 2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 90);
    menu
    .setString("Menu")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(static_cast<float>(_sizeWindow._x), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));


    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText("NAME       SCORE", 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 2);
    Vector2f pos = {x, y};
    bmb::rlib::EText scoreboard("NAME       SCORE", pos, 60);
    scoreboard.setPosition(pos);

    _buttons["menu"]        = menu;
    _texts["scoreboard"]    = scoreboard;
}

void bmb::scene::Scoreboard::unload(void) {
    _isLoaded = false;
    _buttons.clear();
    _texts.clear();
}

void bmb::scene::Scoreboard::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    cManager[0]->setModeDisplay(bmb::character::CURSOR);
    float cursorSize = tools::percentage(static_cast<float>(_sizeWindow._x), 2);
    cManager[0]->getCursor().setSize(Vector2f(cursorSize, cursorSize));
    load();
    std::string text;
    float x = 0.f;
    float y = 0.f;
    float posy = 20.f;
    int maxScore = cManager[0]->score();
    _color = cManager[0]->getModel().getColor();

    cManager[0]->getCursor().setColor(bmb::rlib::color::Black);
    for (int i = 1; i < cManager.size(); i++) {
        if (maxScore < cManager[i]->score()) {
            maxScore = cManager[i]->score();
            _color = cManager[i]->getModel().getColor();
            continue;
        }
        if (maxScore == cManager[i]->score()) {
            _color = bmb::rlib::color::White;
            break;
        }
    }

    for (int i = 0; i < cManager.size(); i++) {
        if (cManager[i]->type() == bmb::character::T_AI)
            text = "AI ";
        else
            text = "PLAYER ";
        text += std::to_string(i) + "            " + std::to_string(cManager[i]->score());
        x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(text.c_str(), 60)/2);
        y = tools::percentage(static_cast<float>(_sizeWindow._y), posy);
        Vector2f pos = {x, y};
        bmb::rlib::EText score(text, pos, 60);
        score.setPosition(pos);
        _texts[text] = score;
        posy += 20.f;
    }
}

void bmb::scene::Scoreboard::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter player = cManager[0];
    bmb::event::InputUser input = player->getInput();

    audioManager.updateMusic("scoreboard");

    _mainCamera.update();

    player->move(input);
    if (player->getCursor().getPosition()._x < 0.f)
        player->getCursor().setPosition(Vector2f(0.f, player->getCursor().getPosition()._y));
    if (player->getCursor().getPosition()._x > _sizeWindow._x - player->getCursor().getSize()._x)
        player->getCursor().setPosition(Vector2f(_sizeWindow._x - player->getCursor().getSize()._x, player->getCursor().getPosition()._y));
    if (player->getCursor().getPosition()._y < 0.f)
        player->getCursor().setPosition(Vector2f(player->getCursor().getPosition()._x, 0.f));
    if (player->getCursor().getPosition()._y > _sizeWindow._y - player->getCursor().getSize()._y)
        player->getCursor().setPosition(Vector2f(player->getCursor().getPosition()._x, _sizeWindow._y - player->getCursor().getSize()._y));

    if (_buttons["menu"].isHover(player->getCursor()) == 1)
        audioManager.playSound("hover", true);

    if (_buttons["menu"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        cManager.reset();
        cManager[0]->getCursor().setColor(bmb::rlib::color::Red);
        switchScene(bmb::scene::SCENE_MENU);
    }

    window->clearBackground(_color);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    _mainCamera.endMode3D();
    for (auto it : _texts)
        it.second.draw(*bmb::sys->fonts()["ka1"]);
    for (auto it : _buttons)
        it.second.display();
    player->display();
    window->endDrawing();
}