/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EColor
*/

#include "encapsulation/Color/EColor.hpp"

bmb::rlib::EColor::EColor(bmb::rlib::EVector4<unsigned char> color)
    : _color(color) {
}

bmb::rlib::EColor::EColor(bmb::rlib::EColor const &other)
    : _color(other._color) {
}

bmb::rlib::EColor::EColor::~EColor(void) {}

unsigned char &bmb::rlib::EColor::r(void) {
    return _color._x;
}

unsigned char &bmb::rlib::EColor::g(void) {
    return _color._y;
}

unsigned char &bmb::rlib::EColor::b(void) {
    return _color._z;
}

unsigned char &bmb::rlib::EColor::a(void) {
    return _color._w;
}

Color bmb::rlib::EColor::colorRlib(void) const {
    Color color = {_color._x, _color._y, _color._z, _color._w};
    return color;
}

void bmb::rlib::EColor::operator=(EColor const &other) {
    _color = other._color;
}