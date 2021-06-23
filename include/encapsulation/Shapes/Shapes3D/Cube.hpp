/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Cube
*/

#include "encapsulation/Shapes/Shapes3D/Shapes3D.hpp"
#include "encapsulation/Color/EColor.hpp"
#include "encapsulation/Vector/vector.h"

#pragma once

namespace bmb::rlib::shapes3D {
class Cube : public Shapes3D {
 public:
    /**
     * @brief Construct a new Cube object
     *
     * @param size
     * @param position
     */
    Cube(EVector3<float> size, EVector3<float> position, EColor color);

    /**
     * @brief Destroy the Cube object
     *
     */
    ~Cube(void);

    /**
     * @brief Display the 3DCube in window
     *
     */
    void display(void) const;
};
}  // namespace bmb::rlib
