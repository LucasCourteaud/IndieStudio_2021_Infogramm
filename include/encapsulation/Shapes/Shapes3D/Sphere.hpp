/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Sphere
*/

#include "encapsulation/Shapes/Shapes3D/Shapes3D.hpp"
#include "encapsulation/Color/EColor.hpp"
#include "encapsulation/Vector/vector.h"

#pragma once

namespace bmb::rlib::shapes3D {
class Sphere : public Shapes3D {
 public:
    /**
     * @brief Construct a new Sphere object
     *
     * @param center
     * @param radius
     * @param color
     */
    Sphere(const EVector3<float> &center, const float &radius, const bmb::rlib::EColor &color = bmb::rlib::color::White);

    /**
     * @brief Destroy the Sphere object
     *
     */
    ~Sphere(void);

    /**
     * @brief Display the Sphere Object
     *
     */
    void display(void) const;

    bmb::rlib::EVector3<float> getPosition(void) const = delete;
    bmb::rlib::EVector3<float> getSize(void) const = delete;
    Shapes3D &setPosition(EVector3<float> position) = delete;
    Shapes3D &move(EVector3<float> move) = delete;
    Shapes3D &setSize(EVector3<float> size) = delete;
};
}  // namespace
