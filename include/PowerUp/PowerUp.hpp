/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** PowerUp
*/

#include "Items/Items.hpp"
#include "encapsulation/Shapes/Shapes3D/Sphere.hpp"

#pragma once

namespace bmb::items {

typedef enum {
    SPEED,
    BOMB,
    RANGE
} PowerUpType_t;

class PowerUp : public Items {
 public:
    /**
     * @brief Construct a new Power Up object
     *
     * @param tag
     */
    PowerUp(const PowerUpType_t &tag, const bmb::rlib::shapes3D::Sphere &model)
        : _tag(tag), _model(model) {
    }

    /**
     * @brief Destroy the Power Up object
     *
     */
    virtual ~PowerUp(void) {}

    /**
     * @brief
     *
     * @return PowerUpType_t
     */
    PowerUpType_t tag(void) const {
        return _tag;
    }

    /**
     * @brief Get the Bonus object
     *
     * @return float
     */
    virtual float getBonus(void) const = 0;

    /**
     * @brief Get the Model object
     *
     * @return bmb::rlib::shapes3D::Sphere&
     */
    bmb::rlib::shapes3D::Sphere &getModel(void) {
        return _model;
    }

    /**
     * @brief Display the powerUp
     *
     */
    void display(void) {
        _model.display();
    }

 protected:
    PowerUpType_t _tag;
    bmb::rlib::shapes3D::Sphere _model;
};
}  // namespace bmb::items
