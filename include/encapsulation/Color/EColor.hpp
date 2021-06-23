/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EColor
*/

#include "raylib.h"
#include <iostream>
#include "encapsulation/Vector/EVector4.hpp"

#pragma once

namespace bmb::rlib {
class EColor {
 public:
    /**
     * @brief Construct a new EColor object
     *
     * @param color
     */
    EColor(EVector4<unsigned char> color = EVector4<unsigned char>());

    /**
     * @brief Construct a new EColor object
     *
     * @param other
     */
    EColor(EColor const &other);

    /**
     * @brief Destroy the EColor object
     *
     */
    ~EColor(void);

    /**
     * @brief
     *
     * @return unsigned char&
     */
    unsigned char &r(void);

    /**
     * @brief
     *
     * @return unsigned char&
     */
    unsigned char &g(void);

    /**
     * @brief
     *
     * @return unsigned char&
     */
    unsigned char &b(void);

    /**
     * @brief
     *
     * @return unsigned char&
     */
    unsigned char &a(void);

    /**
     * @brief
     *
     * @return Color
     */
    Color colorRlib(void) const;

    /**
     * @brief
     *
     * @param other
     */
    void operator=(EColor const &other);

 private:
    EVector4<unsigned char> _color;
};

}  // namespace bmb::rlib

namespace bmb::rlib::color {
    static rlib::EColor White(rlib::EVector4<unsigned char>(WHITE.r, WHITE.g, WHITE.b, WHITE.a));
    static rlib::EColor Blue(rlib::EVector4<unsigned char>(BLUE.r, BLUE.g, BLUE.b, BLUE.a));
    static rlib::EColor Red(rlib::EVector4<unsigned char>(RED.r, RED.g, RED.b, RED.a));
    static rlib::EColor Yellow(rlib::EVector4<unsigned char>(YELLOW.r, YELLOW.g, YELLOW.b, YELLOW.a));
    static rlib::EColor Green(rlib::EVector4<unsigned char>(GREEN.r, GREEN.g, GREEN.b, GREEN.a));
    static rlib::EColor Black(rlib::EVector4<unsigned char>(BLACK.r, BLACK.g, BLACK.b, BLACK.a));
    static rlib::EColor Transparent(rlib::EVector4<unsigned char>(BLANK.r, BLANK.g, BLANK.b, BLANK.a));
}  // namespace bmb::rlib
