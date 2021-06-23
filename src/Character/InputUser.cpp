/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** InputUser
*/

#include <iostream>
#include "Character/InputUser.hpp"

bmb::event::InputUser::InputUser(void)
    : _button(bmb::rlib::control::UNKNOWN),
    _analogL(bmb::rlib::control::UNKNOWN), _axisL(bmb::rlib::EVector2<float>(0, 0)),
    _analogR(bmb::rlib::control::UNKNOWN), _axisR(bmb::rlib::EVector2<float>(0, 0)) {
}

bmb::event::InputUser::~InputUser(void) {}

bmb::event::inputName bmb::event::InputUser::getButton(void) const {
    return _button;
}

std::pair<bmb::event::inputName,bmb::rlib::EVector2<float>> bmb::event::InputUser::getAnalogLeft(void) const {
    return std::pair<bmb::event::inputName,bmb::rlib::EVector2<float>>(_analogL, _axisL);
}

std::pair<bmb::event::inputName,bmb::rlib::EVector2<float>> bmb::event::InputUser::getAnalogRight(void) const {
    return std::pair<bmb::event::inputName,bmb::rlib::EVector2<float>>(_analogR, _axisR);
}

bmb::event::InputUser &bmb::event::InputUser::setButton(const bmb::event::inputName &button) {
    _button = button;
    return *this;
}

bmb::event::InputUser &bmb::event::InputUser::setAnalogLeft(const bmb::event::inputName &analog, bmb::rlib::EVector2<float> axis) {
    _analogL = analog;
    _axisL = axis;
    return *this;
}

bmb::event::InputUser &bmb::event::InputUser::setAnalogRight(const bmb::event::inputName &analog, bmb::rlib::EVector2<float> axis) {
    _analogR = analog;
    _axisR = axis;
    return *this;
}

bmb::event::InputUser &bmb::event::InputUser::setTypeInput(const TypeInput_t &type) {
    _type = type;
    return *this;
}

bmb::event::TypeInput_t bmb::event::InputUser::type(void) const {
    return _type;
}