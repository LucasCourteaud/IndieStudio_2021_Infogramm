/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** NBomb
*/

#include "PowerUp/PowerUp.hpp"
#include "encapsulation/Shapes/Shapes3D/Sphere.hpp"

#pragma once

#define MAX_BONUS_NBOMB         1

namespace bmb::items {
class NBomb : public PowerUp {
 public:
    /**
     * @brief Construct a new NBomb object
     *
     */
    NBomb(void)
        : PowerUp(BOMB, bmb::rlib::shapes3D::Sphere(Vector3f(0.f, 0.f, 0.f), 4.f, bmb::rlib::color::Black)) {}

    /**
     * @brief Destroy the NBomb object
     *
     */
    ~NBomb(void) {}

    /**
     * @brief Get the Bonus object
     *
     * @return float
     */
    float getBonus(void) const {
        return MAX_BONUS_NBOMB;
    }
};
}  // namespace bmb::items
