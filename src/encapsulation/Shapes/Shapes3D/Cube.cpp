/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Cube
*/

#include "encapsulation/Shapes/Shapes3D/Cube.hpp"

bmb::rlib::shapes3D::Cube::Cube(bmb::rlib::EVector3<float> size, bmb::rlib::EVector3<float> position, EColor color)
    : Shapes3D(bmb::rlib::shapes::CUBE, size, position, color) {
}

bmb::rlib::shapes3D::Cube::~Cube(void) {}

void bmb::rlib::shapes3D::Cube::display(void) const {
    Vector3 tmpP = {_position._x, _position._y, _position._z};
    Vector3 tmpS = {_size._x, _size._y, _size._z};
    DrawCubeV(tmpP, tmpS, _color.colorRlib());
}