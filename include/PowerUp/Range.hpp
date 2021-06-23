/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Range
*/

#include "PowerUp/PowerUp.hpp"
#include "encapsulation/Shapes/Shapes3D/Sphere.hpp"

#pragma once

#define MAX_BONUS_RANGE         2

#define MIN_BONUS_RANGE         1

namespace bmb::items {
class Range : public PowerUp {
 public:
    /**
     * @brief Construct a new Range object
     *
     */
    Range(void)
        : PowerUp(RANGE, bmb::rlib::shapes3D::Sphere(Vector3f(0.f, 0.f, 0.f), 4.f, bmb::rlib::color::Red)) {}

    /**
     * @brief Destroy the Range object
     *
     */
    ~Range(void) {}

    /**
     * @brief Get the Bonus object
     *
     * @return float
     */
    float getBonus(void) const {
        return rand() % (MAX_BONUS_RANGE/2) + MIN_BONUS_RANGE;
    }
};
}  // namespace bmb::items
