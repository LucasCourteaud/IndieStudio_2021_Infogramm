/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EText
*/

#include "encapsulation/Text/EText.hpp"

bmb::rlib::EText::EText(const std::string &text, Vector2f position, int fontSize, bmb::rlib::EColor color)
    : _text(text), _position(position), _fontSize(fontSize), _color(color), _isVisible(true) {
}

bmb::rlib::EText::~EText(void) {
}

void bmb::rlib::EText::draw(void) {
    Vector2 tmpPos = {_position._x, _position._y};
    DrawText(_text.c_str(), static_cast<int>(tmpPos.x), static_cast<int>(tmpPos.y), _fontSize, _color.colorRlib());
}

void bmb::rlib::EText::draw(const Font &font) {
    Vector2 tmpPos = {_position._x, _position._y};
    DrawTextEx(font, _text.c_str(), tmpPos, _fontSize, 2, _color.colorRlib());
}

void bmb::rlib::EText::draw(const std::string &text, Vector2f position, int fontSize, bmb::rlib::EColor color) {
    Vector2 tmpPos = {position._x, position._y};
    DrawText(text.c_str(), static_cast<int>(tmpPos.x), static_cast<int>(tmpPos.y), fontSize, color.colorRlib());
}

bmb::rlib::EText &bmb::rlib::EText::setString(const std::string &text) {
    _text = text;
    return *this;
}

bmb::rlib::EText &bmb::rlib::EText::setPosition(const Vector2f &position) {
    _position = position;
    return *this;
}

bmb::rlib::EText &bmb::rlib::EText::setFontSize(const int &fontSize) {
    _fontSize = fontSize;
    return *this;
}

bmb::rlib::EText &bmb::rlib::EText::setColor(const bmb::rlib::EColor &color) {
    _color = color;
    return *this;
}

std::string bmb::rlib::EText::getString(void) const {
    return _text;
}

Vector2f bmb::rlib::EText::getPosition(void) const {
    return _position;
}

int bmb::rlib::EText::getFontSize(void) const {
    return _fontSize;
}


bool &bmb::rlib::EText::isVisible(void) {
    return _isVisible;
}