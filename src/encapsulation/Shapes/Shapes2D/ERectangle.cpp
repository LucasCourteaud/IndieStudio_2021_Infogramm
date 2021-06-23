/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Rectangle
*/

#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"

bmb::rlib::shapes2D::ERectangle::ERectangle(EVector2<float> size, EVector2<float> position, EColor color)
    : Shapes2D(bmb::rlib::shapes::RECTANGLE, size, position, color) {
}

bmb::rlib::shapes2D::ERectangle::~ERectangle(void) {}

bmb::rlib::shapes2D::ERectangle &bmb::rlib::shapes2D::ERectangle::operator=(const ERectangle &other) {
    _size = other._size;
    _position = other._position;
    _color = other._color;
    _thick = other._thick;

    return *this;
}

Rectangle bmb::rlib::shapes2D::ERectangle::getRectangleRlib(void) const {
    Rectangle rec = {_position._x, _position._y, _size._x, _size._y};

    return rec;
}

void bmb::rlib::shapes2D::ERectangle::display(void) const {
    Vector2 tmpP = {_position._x, _position._y};
    Vector2 tmpS = {_size._x, _size._y};

    DrawRectangleV(tmpP, tmpS, _color.colorRlib());
}

void bmb::rlib::shapes2D::ERectangle::displayLines(void) const {
    DrawRectangleLinesEx(getRectangleRlib(), _thick, _color.colorRlib());
}