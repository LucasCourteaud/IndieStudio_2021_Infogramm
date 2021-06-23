/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Shapes
*/

#include "encapsulation/Shapes/shapes.h"

#pragma once

namespace bmb::rlib {

class Shapes {
 public:

    /**
     * @brief Destroy the Shapes object
     *
     */
    virtual ~Shapes(void) = default;

    /**
     * @brief Display shape
     *
     */
    virtual void display(void) const = 0;

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    virtual bool &isVisible(void) = 0;

    /**
     * @brief Get ShapesTag
     *
     * @return bmb::rlib::shapes::ShapesTag_t
     */
    virtual bmb::rlib::shapes::ShapesTag_t tag(void) const = 0;
};
}  // namespace bmb::rlib
