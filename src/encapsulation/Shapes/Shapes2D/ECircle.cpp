/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** ECircle
*/

#include "encapsulation/Shapes/Shapes2D/ECircle.hpp"

bmb::rlib::shapes2D::ECircle::ECircle(const EVector2<float> &center, const float &radius, const bmb::rlib::EColor &color)
    : Shapes2D(bmb::rlib::shapes::CIRCLE, center, radius, color) {}

bmb::rlib::shapes2D::ECircle::~ECircle(void) {}

bmb::rlib::shapes2D::ECircle &bmb::rlib::shapes2D::ECircle::move(const EVector2<float> &move) {
    _center = move;
    return *this;
}

void bmb::rlib::shapes2D::ECircle::display(void) const {
    Vector2 center = {_center._x, _center._x};

    DrawCircleV(center, _radius, _color.colorRlib());
}

void bmb::rlib::shapes2D::ECircle::displayLines(void) const {
    int x = static_cast<int>(_center._x);
    int y = static_cast<int>(_center._y);

    DrawCircleLines(x, y, _radius, _color.colorRlib());
}
