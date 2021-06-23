/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Bomb
*/

#include "encapsulation/Color/EColor.hpp"
#include "System/System.hpp"
#include "Bomb/Bomb.hpp"

bmb::items::Bomb::Bomb(void)
    : Items(), _state(DESACTIVED), _stateTime(0), _explosionRange(DEFAULT_RANGE_EXPLOSION), _size(3.f) {
    _model.isVisible() = false;
    _model
    .load(DEFAULT_PATH_BOMB_MODEL)
    .setTexture(*bmb::sys->textures()["bomb"])
    .setColor(bmb::rlib::color::White);
}

bmb::items::Bomb::~Bomb(void) {}

bmb::rlib::EModel &bmb::items::Bomb::getModel(void) {
    return _model;
}

bmb::items::Bomb &bmb::items::Bomb::activate(const bmb::clock::Clock &clock) {
    _state = WAITING;
    _startTime = clock.getTimeInSecond();
    _model.isVisible() = true;
    _destroyedBlocks.clear();

    bmb::Map map = bmb::sys->map();
    _size = 3.f;
    int y = _posInMap._y;
    int x = _posInMap._x;
    for (int i = 0; i < _explosionRange && x < map[y].size(); i++, x++) {
        auto type = map[y][x]->type();
        if (type == bmb::block::SPAWN)
            _destroyedBlocks.push_back(map[y][x]);
        if (type != bmb::block::WALL && type != bmb::block::SPAWN) {
            _destroyedBlocks.push_back(map[y][x]);
            map[y][x]->getModel().setColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(255, 111, 125, 127)));
            map[y][x]->getModel().isVisible() = true;
        }
        if (type != bmb::block::EMPTY)
            break;
    }
    y = _posInMap._y;
    x = _posInMap._x;
    for (int i = 0; i < _explosionRange && x >= 0; i++, x--) {
        auto type = map[y][x]->type();
        if (type == bmb::block::SPAWN)
            _destroyedBlocks.push_back(map[y][x]);
        if (type != bmb::block::WALL && type != bmb::block::SPAWN) {
            _destroyedBlocks.push_back(map[y][x]);
            map[y][x]->getModel().setColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(255, 111, 125, 127)));
            map[y][x]->getModel().isVisible() = true;
        }
        if (type != bmb::block::EMPTY)
            break;
    }
    y = _posInMap._y;
    x = _posInMap._x;
    for (int i = 0; i < _explosionRange && y < map.size(); i++, y++) {
        auto type = map[y][x]->type();
        if (type == bmb::block::SPAWN)
            _destroyedBlocks.push_back(map[y][x]);
        if (type != bmb::block::WALL && type != bmb::block::SPAWN) {
            _destroyedBlocks.push_back(map[y][x]);
            map[y][x]->getModel().setColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(255, 111, 125, 127)));
            map[y][x]->getModel().isVisible() = true;
        }
        if (type != bmb::block::EMPTY)
            break;
    }
    y = _posInMap._y;
    x = _posInMap._x;
    for (int i = 0; i < _explosionRange && y >= 0; i++, y--) {
        auto type = map[y][x]->type();
        if (type == bmb::block::SPAWN)
            _destroyedBlocks.push_back(map[y][x]);
        if (type != bmb::block::WALL && type != bmb::block::SPAWN) {
            _destroyedBlocks.push_back(map[y][x]);
            map[y][x]->getModel().setColor(bmb::rlib::EColor(bmb::rlib::EVector4<unsigned char>(255, 111, 125, 127)));
            map[y][x]->getModel().isVisible() = true;
        }
        if (type != bmb::block::EMPTY)
            break;
    }
    return *this;
}

bmb::items::Bomb &bmb::items::Bomb::desactivate(void) {
    _state = DESACTIVED;
    _model.isVisible() = false;
    _explosionRange = DEFAULT_RANGE_EXPLOSION;
    _startTime = 0;
    _stateTime = 0;

    return *this;
}

bmb::items::Bomb &bmb::items::Bomb::draw(void) {
    _model.display(_size);

    return *this;
}

bmb::items::BombState_t bmb::items::Bomb::state(void) const {
    return _state;
}

std::list<std::shared_ptr<bmb::block::Block>> bmb::items::Bomb::update(const bmb::clock::Clock &clock) {
    std::list<std::shared_ptr<bmb::block::Block>> tmp;
    if (_state == DESACTIVED) {
        _destroyedBlocks.clear();
        return _destroyedBlocks;
    }
    if (_state == WAITING) {
        int seconds = (clock.getTimeInSecond() - _startTime);
        _size += 0.01;
        if (_stateTime + TIME_TO_EXPLOSE < seconds) {
            _state = EXPLOSED;
            _stateTime = clock.getTimeInSecond();
        }
        return tmp;
    }
    bmb::Map map = bmb::sys->map();
    int y = _posInMap._y;
    int x = _posInMap._x;
    for (int i = 0; i < _explosionRange && x < map[y].size(); i++, x++) {
        auto type = map[y][x]->type();
        bool tmp = map[y][x]->destroy();
        if (!tmp || (tmp && type != bmb::block::EMPTY))
            break;
    }
    y = _posInMap._y;
    x = _posInMap._x;
    for (int i = 0; i < _explosionRange && x >= 0; i++, x--) {
        auto type = map[y][x]->type();
        bool tmp = map[y][x]->destroy();
        if (!tmp || (tmp && type != bmb::block::EMPTY))
            break;
    }
    y = _posInMap._y;
    x = _posInMap._x;
    for (int i = 0; i < _explosionRange && y < map.size(); i++, y++) {
        auto type = map[y][x]->type();
        bool tmp = map[y][x]->destroy();
        if (!tmp || (tmp && type != bmb::block::EMPTY))
            break;
    }
    y = _posInMap._y;
    x = _posInMap._x;
    for (int i = 0; i < _explosionRange && y >= 0; i++, y--) {
        auto type = map[y][x]->type();
        bool tmp = map[y][x]->destroy();
        if (!tmp || (tmp && type != bmb::block::EMPTY))
            break;
    }
    desactivate();
    return _destroyedBlocks;
}

bmb::items::Bomb &bmb::items::Bomb::setPositionMap(const Vector2i &pos) {
    _posInMap = pos;

    return *this;
}

Vector2i bmb::items::Bomb::getPositionMap(void) const {
    return _posInMap;
}

int &bmb::items::Bomb::range(void) {
    return _explosionRange;
}