/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Sphere
*/

#include "encapsulation/Shapes/Shapes3D/Sphere.hpp"

bmb::rlib::shapes3D::Sphere::Sphere(const EVector3<float> &center, const float &radius, const bmb::rlib::EColor &color)
    : Shapes3D(bmb::rlib::shapes::SPHERE, center, radius, color) {
}

bmb::rlib::shapes3D::Sphere::~Sphere(void) {}

void bmb::rlib::shapes3D::Sphere::display(void) const {
    if (!_isVisible)
        return;
    Vector3 center = {_center._x, _center._y, _center._z};
    DrawSphere(center, _radius, _color.colorRlib());
}