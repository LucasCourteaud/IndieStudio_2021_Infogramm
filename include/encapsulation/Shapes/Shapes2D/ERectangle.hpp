/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Rectangle
*/

#pragma once

#include "encapsulation/Shapes/Shapes2D/Shapes2D.hpp"

namespace bmb::rlib::shapes2D {
class ERectangle : public Shapes2D {
 public:

    /**
     * @brief Construct a new Rectangle object
     *
     * @param size
     * @param position
     * @param color
     */
    ERectangle(EVector2<float> size, EVector2<float> position, EColor color = bmb::rlib::color::Transparent);

    /**
     * @brief Destroy the Rectangle object
     *
     */
    ~ERectangle(void);

    /**
     * @brief Operator=
     *
     * @param other
     * @return ERectangle&
     */
    ERectangle &operator=(const ERectangle &other);

    /**
     * @brief Get the Rectangle object
     *
     * @return Rectangle
     */
    Rectangle getRectangleRlib(void) const;

    /**
     * @brief Display the Rectangle
     *
     */
    void display(void) const;

    /**
     * @brief Display with lines
     *
     */
    void displayLines(void) const;

    Shapes2D &setRadius(const float &radius) = delete;
    float getRadius(void) const = delete;
    bmb::rlib::EVector2<float> getCenter(void) const = delete;
    Shapes2D &setCenter(const EVector2<float> &center) = delete;

};
}  // namespace bmb::rlib
