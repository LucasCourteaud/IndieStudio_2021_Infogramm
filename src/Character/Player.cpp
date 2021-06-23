/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Player
*/

#include "System/System.hpp"
#include "encapsulation/Matrix/EMatrix.h"
#include "Character/Player.hpp"

bmb::character::Player::Player(indexController_u indexController, indexEntity_u indexPlayer)
    : Character(bmb::entity::CHARACTER, "Player", indexPlayer), _indexController(indexController) {
    _controller = bmb::rlib::Controller(_indexController);
    _spawn = bmb::rlib::EVector3<float>();
}

bmb::character::Player::~Player(void) {
    _listBomb.clear();
}

bmb::event::InputUser bmb::character::Player::getInput(void) {
    _inputUser = _controller.getControllerInput();
    return _inputUser;
}

bool bmb::character::Player::move(const bmb::event::InputUser &input) {
    if (_mode == MODEL && _alive)
        return moveModel(input);
    if (_mode == CURSOR)
        return moveCursor(input);
    return false;
}

void bmb::character::Player::action(const bmb::event::InputUser &input, const bmb::clock::Clock &clock) {
    int x = 0;
    int y = 0;

    if (!_alive)
        return;
    if (input.getButton() == bmb::rlib::control::BUTTON_3 && input.type() == bmb::event::PRESSED) {
        for (auto it : _listBomb) {
            if (it->state() == bmb::items::DESACTIVED) {
                x = static_cast<int>((_model.getPosition()._x - bmb::sys->map().origin()._x + (_model.getSize()._x/2)) / bmb::sys->map().offset()._x);
                y = static_cast<int>((_model.getPosition()._z - bmb::sys->map().origin()._z + (_model.getSize()._z/2)) / bmb::sys->map().offset()._y);
                it->getModel().setPosition(bmb::sys->map()[y][x]->getPosition());
                it->setPositionMap(Vector2i(x, y));
                it->range() = _rangeBomb;
                it->activate(clock);
                break;
            }
        }
    }
}

void bmb::character::Player::display(void) {
    if (DISCONNECTED(_inputUser))
        return;
    if (_mode == MODEL && _alive) {
        _model.display(Vector3f(1.0f, 0.0f, 0.0f), -90.f);
        for (auto it : _listBomb)
            it->draw();
    }
    if (_mode == CURSOR)
        _cursor.displayLines();
}

bmb::character::CharacterTag_t bmb::character::Player::type(void) const {
    return bmb::character::T_PLAYER;
}

bool bmb::character::Player::moveModel(const bmb::event::InputUser &input) {
    float vit = 0.f;
    float bonus = 0;

    _oldPosition = _model.getPosition();
    if (input.getButton() == bmb::rlib::control::ARROW_RIGHT) {
        vit = 1;
        bonus = tools::percentage(0.5 * abs(vit), _speedBonus);
        _model.transform(bmb::rmath::matrix::rotateXYZ(Vector3f(0.f, 0.f, 4.8f)))
        .move(Vector3f((0.5f * abs(vit) + bonus) * _multi, 0.f, 0.f))
        .updateAnimation(0);
        return true;
    }
    if (input.getButton() == 16) {
        vit = -1;
        bonus = tools::percentage(0.5 * abs(vit), _speedBonus);
        _model.transform(bmb::rmath::matrix::rotateXYZ(Vector3f(0.f, 0.f, 1.5f)))
        .move(Vector3f((-0.5f * abs(vit) - bonus) * _multi, 0.f, 0.f))
        .updateAnimation(0);
        return true;
    }
    if (input.getButton() == bmb::rlib::control::ARROW_UP) {
        vit = -1;
        bonus = tools::percentage(0.5 * abs(vit), _speedBonus);
        _model.transform(bmb::rmath::matrix::rotateXYZ(Vector3f(0.f, 0.f, 3.1f)))
        .move(Vector3f(0.f, 0.f, (-0.5f * abs(vit) - bonus) * _multi))
        .updateAnimation(0);
        return true;
    }
    if (input.getButton() == bmb::rlib::control::ARROW_DOWN) {
        vit = 1;
        bonus = tools::percentage(0.5 * abs(vit), _speedBonus);
        _model.transform(bmb::rmath::matrix::rotateXYZ(Vector3f(0.f, 0.f, 0.0f)))
        .move(Vector3f(0.f, 0.f, (0.5f * abs(vit) + bonus) * _multi))
        .updateAnimation(0);
        return true;
    }
    return false;
}

bool bmb::character::Player::moveCursor(const bmb::event::InputUser &input) {
    if (input.getAnalogLeft().second._x > 0.f)
        _cursor.move(Vector2f(7.f, 0.f));
    if (input.getAnalogLeft().second._x < 0.f)
        _cursor.move(Vector2f(-7.f, 0.f));
    if (input.getAnalogLeft().second._y < 0.f)
        _cursor.move(Vector2f(0.f, -7.f));
    if (input.getAnalogLeft().second._y > 0.f)
        _cursor.move(Vector2f(0.f, 7.f));
    return true;
}
