/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Game
*/

#include "Scene/Game.hpp"
#include "Map/MapParser.hpp"

bmb::scene::Game::Game(void)
    : Scene() {
    _timePass = 0;
    _gameRound["1:00"] = 60;
    _gameRound["2:00"] = 120;
    _gameRound["3:00"] = 180;
}

bmb::scene::Game::~Game(void) {
    std::cout << "[BMB] : Destroy Scene Game." << std::endl;
    unload();
}

void bmb::scene::Game::load(void) {
    float x = 0.f;
    float y = 0.f;

    if (bmb::sys->restart()) {
        _timePass = 0;
        bmb::sys->restart() = false;
    }
    _isLoaded = true;
    _timeRound = _gameRound[bmb::sys->time()];
    _timerDelay = 0;
    bmb::Map map = bmb::sys->map();
    Vector2i angle = map.max();
    int maxX = angle._x + 1;
    int maxY = angle._y + 1;
    float angleY = maxX * ((map.offset()._x + map.offset()._y) / 2);
    _isLoaded = true;
    if (maxX < maxY)
        angleY = maxY * ((map.offset()._x + map.offset()._y) / 2);
    _mainCamera
        .setPosition(Vector3f(0.f, angleY, 50.f));

    bmb::rlib::EText round;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(std::to_string(bmb::sys->maxScore()).c_str(), 70) / 2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 2);
    round
        .setString(std::to_string(bmb::sys->maxScore()))
        .setFontSize(70)
        .setColor(bmb::rlib::color::Black)
        .setPosition(Vector2f(x, y));

    bmb::rlib::EText timeText;
    std::string toto = std::to_string(_timeRound - _timePass);
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText(toto.c_str(), 40) / 2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 18);
    timeText
        .setString(toto)
        .setFontSize(40)
        .setColor(bmb::rlib::color::Black)
        .setPosition(Vector2f(x, y));

    bmb::rlib::EText textRound;
    x = tools::percentage(static_cast<float>(_sizeWindow._x), 50) - (MeasureText("round(s)", 20) / 2);
    y = tools::percentage(static_cast<float>(_sizeWindow._y), 14);
    textRound
        .setString("rounds(s)")
        .setFontSize(20)
        .setColor(bmb::rlib::color::Black)
        .setPosition(Vector2f(x, y));

    _texts["textround"] = textRound,
    _texts["round"]     = round;
    _texts["time"]      = timeText;
}

void bmb::scene::Game::unload(void) {
    _isLoaded = false;
    _texts.clear();
    _pos.clear();
}

void bmb::scene::Game::setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) {
    _sizeWindow = window->getSize();
    _clock.start();
    auto listC = cManager.get();
    int i = 0;

    _posCadre = Vector2f(tools::percentage(_sizeWindow._x, 50) - (bmb::sys->textures()["cadre"]->width / 2), tools::percentage(_sizeWindow._y, 1.8));
    _pos[0] = Vector2f(tools::percentage(_sizeWindow._x, 10), tools::percentage(_sizeWindow._y, 5));
    _pos[1] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 12), tools::percentage(_sizeWindow._y, 5));
    _pos[2] = Vector2f(tools::percentage(_sizeWindow._x, 10), _sizeWindow._y - tools::percentage(_sizeWindow._y, 5));
    _pos[3] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 12), _sizeWindow._y - tools::percentage(_sizeWindow._y, 5));

    _pos[4] = Vector2f(tools::percentage(_sizeWindow._x, 2), tools::percentage(_sizeWindow._y, 15));
    _pos[5] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 20), tools::percentage(_sizeWindow._y, 15));
    _pos[6] = Vector2f(tools::percentage(_sizeWindow._x, 2), _sizeWindow._y - tools::percentage(_sizeWindow._y, 15));
    _pos[7] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 20), _sizeWindow._y - tools::percentage(_sizeWindow._y, 15));

    _pos[8] = Vector2f(tools::percentage(_sizeWindow._x, 10), tools::percentage(_sizeWindow._y, 15));
    _pos[9] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 12), tools::percentage(_sizeWindow._y, 15));
    _pos[10] = Vector2f(tools::percentage(_sizeWindow._x, 10), _sizeWindow._y - tools::percentage(_sizeWindow._y, 15));
    _pos[11] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 12), _sizeWindow._y - tools::percentage(_sizeWindow._y, 15));

    _pos[12] = Vector2f(tools::percentage(_sizeWindow._x, 18), tools::percentage(_sizeWindow._y, 15));
    _pos[13] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 4), tools::percentage(_sizeWindow._y, 15));
    _pos[14] = Vector2f(tools::percentage(_sizeWindow._x, 18), _sizeWindow._y - tools::percentage(_sizeWindow._y, 15));
    _pos[15] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 4), _sizeWindow._y - tools::percentage(_sizeWindow._y, 15));

    _pos[16] = Vector2f(tools::percentage(_sizeWindow._x, 2), tools::percentage(_sizeWindow._y, 21));
    _pos[17] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 20), tools::percentage(_sizeWindow._y, 21));
    _pos[18] = Vector2f(tools::percentage(_sizeWindow._x, 2), _sizeWindow._y - tools::percentage(_sizeWindow._y, 21));
    _pos[19] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 20), _sizeWindow._y - tools::percentage(_sizeWindow._y, 21));

    _pos[20] = Vector2f(tools::percentage(_sizeWindow._x, 10), tools::percentage(_sizeWindow._y, 21));
    _pos[21] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 12), tools::percentage(_sizeWindow._y, 21));
    _pos[22] = Vector2f(tools::percentage(_sizeWindow._x, 10), _sizeWindow._y - tools::percentage(_sizeWindow._y, 21));
    _pos[23] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 12), _sizeWindow._y - tools::percentage(_sizeWindow._y, 21));

    _pos[24] = Vector2f(tools::percentage(_sizeWindow._x, 18), tools::percentage(_sizeWindow._y, 21));
    _pos[25] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 4), tools::percentage(_sizeWindow._y, 21));
    _pos[26] = Vector2f(tools::percentage(_sizeWindow._x, 18), _sizeWindow._y - tools::percentage(_sizeWindow._y, 21));
    _pos[27] = Vector2f(_sizeWindow._x - tools::percentage(_sizeWindow._x, 4), _sizeWindow._y - tools::percentage(_sizeWindow._y, 21));
    for (auto it : listC) {
        cManager[i]->getText("score").setPosition(_pos[i]);
        cManager[i]->getText("bomb").setPosition(_pos[i+4]);
        cManager[i]->getText("speed").setPosition(_pos[i+8]);
        cManager[i]->getText("range").setPosition(_pos[i+12]);
        it->setModeDisplay(bmb::character::MODEL);
        auto bombs = it->getBombs();
        for (auto it2 : bombs) {
            if (it2->state() == bmb::items::WAITING)
                it2->activate(_clock);
        }
        i++;
    }
    load();
}

void bmb::scene::Game::loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) {
    auto tmp = cManager.get();
    std::vector<bmb::event::InputUser> inputs;
    bmb::Map map = bmb::sys->map();
    size_t nbPlayer = cManager.size();
    int multi = 0;

    if (_timerDelay + 1 < _clock.getTimeInSecond()) {
        _timePass++;
        _texts["time"].setString(std::to_string(_timeRound - _timePass));
        _timerDelay = _clock.getTimeInSecond();
    }
    audioManager.updateMusic("game");
    _oldCharacterAlive = _characterAlive;
    for (size_t i = 0; i < nbPlayer; i++) {
        if (cManager[i]->isAlive())
            _characterAlive.push_back(i);
        auto tmp = cManager[i]->getInput();
        if (tmp.getAnalogLeft().second._x && tmp.getAnalogLeft().second._y)
            multi++;
        inputs.push_back(tmp);
    }
    if (!multi)
        multi = 1;
    for (size_t i = 0; i < nbPlayer; i++) {
        cManager[i]->multiplicatorSpeed() = multi;
        if (cManager[i]->move(inputs[i])) {
            for (size_t x = 0; x < map.size(); x++) {
                for (size_t j = 0; j < map[x].size(); j++)
                    cManager[i]->isCollision(map[x][j]);
            }
        }
        cManager[i]->action(inputs[i], _clock);
        auto listDestroyed = cManager[i]->updateBomb(_clock, audioManager);
        if (listDestroyed.size() != 0) {
            for (size_t j = 0; j < nbPlayer; j++) {
                for (auto it : listDestroyed)
                    if (cManager[j]->isCollisionB(it))
                        cManager[j]->setState(false);
            }
        }
        if (inputs[i].getButton() == bmb::rlib::control::START && inputs[i].type() == bmb::event::PRESSED) {
            audioManager.playSound("click", true);
            bmb::sys->playerPaused() = i;
            switchScene(bmb::scene::SCENE_PAUSE);
        }
    }
    if (_characterAlive.size() == 1) {
        cManager[_characterAlive[0]]->addScore();
        reset(cManager);
    }
    if (_characterAlive.size() == 0 || (_timeRound - _timePass) < 0)
        reset(cManager);
    window->clearBackground(bmb::rlib::color::White);
    window->beginDrawing();
    _mainCamera.beginMode3D();
    for (auto it : tmp)
        it->display();
    bmb::sys->map().draw();
    DrawGrid(100.f, 10.f);
    _mainCamera.endMode3D();
    DrawTexture(*bmb::sys->textures()["cadre"], static_cast<int>(_posCadre._x), static_cast<int>(_posCadre._y), WHITE);
    for (int i = 0; i < cManager.size(); i++) {
        DrawTexture(*bmb::sys->textures()["bomblogo"], static_cast<int>(_pos[i+16]._x), static_cast<int>(_pos[i+16]._y), WHITE);
        DrawTexture(*bmb::sys->textures()["shoe"], static_cast<int>(_pos[i+20]._x), static_cast<int>(_pos[i+20]._y), WHITE);
        DrawTexture(*bmb::sys->textures()["range"], static_cast<int>(_pos[i+24]._x), static_cast<int>(_pos[i+24]._y), WHITE);
    }
    for (auto it : _texts)
        it.second.draw();
    for (auto it : tmp)
        it->drawTitle(_mainCamera);
    window->endDrawing();
    _characterAlive.clear();
}

void bmb::scene::Game::reset(bmb::character::CharacterManager &cManager) {
    bmb::sys->maxScore()--;
    _timePass = 0;
    if (bmb::sys->maxScore() == 0) {
        bmb::sys->maxScore() = 1;
        bmb::sys->playerPaused() = 0;
        switchScene(SCENE_SCOREBOARD);
        return;
    }
    bmb::MapParser::fileToMap("map/" + bmb::sys->map().getName() + ".bmb", bmb::sys->map());
    auto map = bmb::sys->map();
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
    switchScene(SCENE_GAME);
}
