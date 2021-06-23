/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** SelectMap
*/

#include "tools/tools.hpp"
#include "Scene/SelectMap.hpp"

bmb::scene::SelectMap::SelectMap(void)
    : Scene() {
    std::vector<std::string> path;
    #ifdef _WIN32
        path = tools::explore("assets/csv/map_window.csv");
    #endif
    #ifdef __linux__
        path = tools::explore("assets/csv/map_linux.csv");
    #endif
    for (int i = 0; i < path.size(); i++) {
        bmb::MapParser::fileToMap(path[i], _listMap[i]);
        _listPath.push_back(path[i]);
    }
}

bmb::scene::SelectMap::~SelectMap(void) {
    unload();
}

void bmb::scene::SelectMap::load(void) {
    float x = 0.f;
    float y = 0.f;
    std::string text = "";

    _index = 0;
    _isLoaded = true;
    _mainCamera
    .setPosition(Vector3f(0.f, 200.f, 150.f))
    .setCameraMode(CAMERA_ORBITAL);
    centerCameraMap();

    bmb::widget::Button back;
    x = 0.f;
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 90);
    back
    .setString("Back")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 20), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    bmb::widget::Button play;
    x = static_cast<float>(_sizeWindow._x) - tools::percentage(static_cast<float>(_sizeWindow._x), 20);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 90);
    play
    .setString("Play")
    .setStringSize(30)
    .setModel(bmb::rlib::shapes2D::ERectangle(Vector2f(tools::percentage(static_cast<float>(_sizeWindow._x), 20), tools::percentage(static_cast<float>(_sizeWindow._y), 10)), Vector2f(x, y)))
    .hide()
    .setHoverColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(225, 225, 225, 127)));

    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(bmb::MapParser::getNameMap(_listPath[_index]).c_str(), 60)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 5);
    Vector2f pos = {x, y};
    bmb::rlib::EText name(bmb::MapParser::getNameMap(_listPath[_index]), pos, 60);
    name.setPosition(pos);

    text = " L1 \nNext";
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 90) - (MeasureText(text.c_str(), 40)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 40);
    bmb::rlib::EText nextMap(text, Vector2f(), 40);
    nextMap.setPosition(Vector2f(x, y));

    text = " R1 \nPrev";
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 10) - (MeasureText(text.c_str(), 40)/2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 40);
    bmb::rlib::EText prevMap(text, Vector2f(), 40);
    prevMap.setPosition(Vector2f(x, y));

    _texts["name"]      = name;
    _texts["next"]      = nextMap;
    _texts["prev"]      = prevMap;
    _buttons["play"]    = play;
    _buttons["back"]    = back;
}

void bmb::scene::SelectMap::unload(void) {
    _isLoaded = false;
    _index = 0;
}

void bmb::scene::SelectMap::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    cManager[0]->setModeDisplay(bmb::character::CURSOR);
    float cursorSize = tools::percentage(static_cast<float>(_sizeWindow._x), 2);
    cManager[0]->getCursor().setSize(Vector2f(cursorSize, cursorSize));
    load();
}

void bmb::scene::SelectMap::centerCameraMap(void)
{
    Vector2i angle = _listMap[_index].max();
    int maxX = angle._x + 1;
    int maxY = angle._y + 1;
    float angleY = maxX * ((_listMap[_index].offset()._x + _listMap[_index].offset()._y) / 2);
    _isLoaded = true;
    if (maxX < maxY)
        angleY = maxY * ((_listMap[_index].offset()._x + _listMap[_index].offset()._y) / 2);
    _mainCamera
        .setPosition(Vector3f(0.f, angleY, 50.f))
        .setCameraMode(CAMERA_ORBITAL);
}

void bmb::scene::SelectMap::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    bmb::character::uniqueCharacter toto = cManager[0];
    bmb::event::InputUser input = toto->getInput();
    Vector2f pos;

    _mainCamera.update();

    audioManager.updateMusic("menu");

    if (toto->getCursor().getPosition()._x < 0.f)
        toto->getCursor().setPosition(Vector2f(0.f, toto->getCursor().getPosition()._y));
    if (toto->getCursor().getPosition()._x > _sizeWindow._x - toto->getCursor().getSize()._x)
        toto->getCursor().setPosition(Vector2f(_sizeWindow._x - toto->getCursor().getSize()._x, toto->getCursor().getPosition()._y));
    if (toto->getCursor().getPosition()._y < 0.f)
        toto->getCursor().setPosition(Vector2f(toto->getCursor().getPosition()._x, 0.f));
    if (toto->getCursor().getPosition()._y > _sizeWindow._y - toto->getCursor().getSize()._y)
        toto->getCursor().setPosition(Vector2f(toto->getCursor().getPosition()._x, _sizeWindow._y - toto->getCursor().getSize()._y));

    toto->move(input);
    if (_buttons["play"].isHover(toto->getCursor()) == 1 ||
        _buttons["back"].isHover(toto->getCursor()) == 1)
        audioManager.playSound("hover", true);
    if (_buttons["back"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        switchScene(bmb::scene::SCENE_OPTIONS);
    }
    if (_buttons["play"].action(input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::DOWN, input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::RELEASE)) {
        audioManager.playSound("click", true);
        updateGametoPlay(cManager);
        switchScene(bmb::scene::SCENE_GAME);
    }
    if (input.getButton() == bmb::rlib::control::TRIGGER_LEFT_FRONT && input.type() == bmb::event::PRESSED) {
        _index--;
        _index = (_index < 0) ? _listPath.size() - 1: _index;
        pos = _texts["name"].getPosition();
        pos._x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(bmb::MapParser::getNameMap(_listPath[_index]).c_str(), 60)/2);
        _texts["name"]
        .setString(bmb::MapParser::getNameMap(_listPath[_index]))
        .setPosition(pos);
        audioManager.playSound("click", true);
        centerCameraMap();
    }
    if (input.getButton() == bmb::rlib::control::TRIGGER_RIGHT_FRONT && input.type() == bmb::event::PRESSED) {
        _index++;
        _index = (_index >= _listPath.size()) ? 0 : _index;
        pos = _texts["name"].getPosition();
        pos._x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(bmb::MapParser::getNameMap(_listPath[_index]).c_str(), 60)/2);
        _texts["name"]
        .setString(bmb::MapParser::getNameMap(_listPath[_index]))
        .setPosition(pos);
        audioManager.playSound("click", true);
        centerCameraMap();
    }
    window->clearBackground(bmb::rlib::color::White);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    DrawGrid(100, 10.f);
    _listMap[_index].draw();
    _mainCamera.endMode3D();
    for (auto it : _texts)
        it.second.draw();
    for (auto it : _buttons)
        it.second.display();
    toto->display();
    window->endDrawing();
}

void bmb::scene::SelectMap::updateGametoPlay(bmb::character::CharacterManager &cManager) {
    bmb::MapParser::fileToMap(_listPath[_index], bmb::sys->map());
    bmb::Map map = bmb::sys->map();
    std::vector<std::shared_ptr<bmb::block::Block>> _listSpawn;

    cManager.add(bmb::character::T_PLAYER, static_cast<size_t>(bmb::sys->nbPlayer()-1));
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