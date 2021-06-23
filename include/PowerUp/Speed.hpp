/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Speed
*/

#include "PowerUp/PowerUp.hpp"
#include "encapsulation/Shapes/Shapes3D/Sphere.hpp"

#pragma once

#define MAX_BONUS_SPEED             50

#define MIN_BONUS_SPEED             25

namespace bmb::items {
class Speed : public PowerUp {
 public:
    /**
     * @brief Construct a new Speed object
     *
     */
    Speed(void)
        : PowerUp(SPEED, bmb::rlib::shapes3D::Sphere(Vector3f(0.f, 0.f, 0.f), 4.f, bmb::rlib::color::Blue)) {
    }

    /**
     * @brief Destroy the Speed object
     *
     */
    ~Speed(void) {}

    /**
     * @brief Get the Bonus object
     *
     * @return float
     */
    float getBonus(void) const {
        return static_cast<float>(rand() % (MAX_BONUS_SPEED/2) + MIN_BONUS_SPEED);
    }
};
}  // namespace bmb::items
