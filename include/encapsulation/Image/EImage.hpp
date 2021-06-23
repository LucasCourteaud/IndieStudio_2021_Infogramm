/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EImage
*/

#include "raylib.h"
#include <string>
#include "encapsulation/Color/EColor.hpp"
#include "encapsulation/Vector/vector.h"

#pragma once

namespace bmb::rlib {
class EImage {
 public:
    /**
     * @brief Construct a new EImage object
     *
     * @param pathImage
     */
    EImage(const std::string &pathImage, const Vector2i &size = bmb::rlib::EVector2<int>(800, 600), const Vector2f &pos = bmb::rlib::EVector2<float>(), const bmb::rlib::EColor &color = bmb::rlib::color::White);

    /**
     * @briesf Construct a new EImage object
     *
     */
    EImage(void);

    /**
     * @brief Destroy the EImage object
     *
     */
    ~EImage(void);

    /**
     * @brief Load image
     *
     * @param pathImage
     * @return EImage&
     */
    EImage &load(const std::string &pathImage);

    /**
     * @brief Set the Texture object
     *
     * @param texture
     * @return EImage&
     */
    EImage &setTexture(const Texture &texture);

    /**
     * @brief Set the Position object
     *
     * @param pos
     * @return EImage&
     */
    EImage &setPosition(const bmb::rlib::EVector2<float> &pos);

    /**
     * @brief Get the Position object
     *
     * @return Vector2f
     */
    Vector2f getPosition(void) const;

    /**
     * @brief Set the Color object
     *
     * @param color
     * @return EImage&
     */
    EImage &setColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get the Color object
     *
     * @return bmb::rlib::EColor
     */
    bmb::rlib::EColor getColor(void) const;

    /**
     * @brief unload image
     *
     */    void unload(void);

    /**
     * @brief
     *
     */
    void display(void);

 private:
    Vector2i            _size;
    std::string         _pathimage;
    Image               _image;
    Texture2D           _texture;
    bool                _isLoaded;
    Vector2f            _position;
    bmb::rlib::EColor   _color;
};
} //namespace bmb::rlib