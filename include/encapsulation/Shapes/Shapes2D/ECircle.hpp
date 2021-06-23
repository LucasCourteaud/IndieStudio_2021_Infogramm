/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** ECircle
*/

#pragma once

#include "encapsulation/Shapes/Shapes2D/Shapes2D.hpp"

namespace bmb::rlib::shapes2D {
class ECircle : public Shapes2D {
 public:
    /**
     * @brief Construct a new ECircle object
     *
     * @param tag
     * @param center
     * @param radius
     * @param color
     */
    ECircle(const EVector2<float> &center, const float &radius, const bmb::rlib::EColor &color = bmb::rlib::color::Transparent);

    /**
     * @brief Destroy the ECircle object
     *
     */
    ~ECircle(void);

    /**
     * @brief Move the circle
     *
     * @param move
     * @return ECircle&
     */
    ECircle &move(const EVector2<float> &move);

    /**
     * @brief Display he circle;
     *
     */
    void display(void) const;

    /**
     * @brief Display with lines
     *
     */
    void displayLines(void) const;

    bmb::rlib::EVector2<float> getSize(void) const = delete;
    Shapes2D &setSize(const EVector2<float> &size) = delete;
    bmb::rlib::EVector2<float> getPosition(void) = delete;
    Shapes2D &setPosition(const EVector2<float> &position) = delete;
};
}  // namespace bmb::rlib::shapes2D
