/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Controller
*/

#include <iostream>
#include "encapsulation/Controller/Controller.hpp"

bmb::rlib::Controller::Controller(const int &indexController)
    : _indexController(indexController) {
}

bmb::rlib::Controller::~Controller(void) {}

bmb::rlib::Controller &bmb::rlib::Controller::operator=(Controller const &other) {
    _indexController = other._indexController;
    return *this;
}

bmb::event::InputUser bmb::rlib::Controller::getControllerInput(void) const {
    bmb::event::InputUser Iuser;
    bmb::event::inputName analogL = bmb::rlib::control::DISCONNECT;
    bmb::rlib::EVector2<float> axisL;
    bmb::event::inputName analogR = bmb::rlib::control::DISCONNECT;
    bmb::rlib::EVector2<float> axisR;

    if (!IsGamepadAvailable(_indexController))
        return Iuser.setButton(bmb::rlib::control::DISCONNECT).setAnalogLeft(analogL, axisL).setAnalogRight(analogR, axisR);
    for (auto it : bmb::rlib::control::mapping_control) {
        if (IsGamepadButtonPressed(_indexController, it.first)) {
            Iuser.setButton(it.second);
            Iuser.setTypeInput(bmb::event::PRESSED);
            break;
        }
        if (IsGamepadButtonDown(_indexController, it.first)) {
            Iuser.setButton(it.second);
            Iuser.setTypeInput(bmb::event::DOWN);
            break;
        }
        if (IsGamepadButtonReleased(_indexController, it.first)) {
            Iuser.setButton(it.second);
            Iuser.setTypeInput(bmb::event::RELEASE);
            break;
        }
    }
    for (int i = 0; i < GetGamepadAxisCount(_indexController); i++) {
        switch (i) {
            case 0:
                analogL = bmb::rlib::control::ANALOG_AXIS_LEFT;
                axisL._x = GetGamepadAxisMovement(_indexController, i);
            case 1:
                analogL = bmb::rlib::control::ANALOG_AXIS_LEFT;
                axisL._y = GetGamepadAxisMovement(_indexController, i);
            case 2:
                analogR = bmb::rlib::control::ANALOG_AXIS_RIGHT;
                axisR._x = GetGamepadAxisMovement(_indexController, i);
            case 3:
                analogR = bmb::rlib::control::ANALOG_AXIS_RIGHT;
                axisR._y = GetGamepadAxisMovement(_indexController, i);
            default: break;
        }
    }
    return Iuser.setAnalogLeft(analogL, axisL).setAnalogRight(analogR, axisR);
}