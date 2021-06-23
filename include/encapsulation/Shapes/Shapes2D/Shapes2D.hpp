/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Shapes2D
*/

#pragma once

#include "encapsulation/Shapes/shapes.h"
#include "encapsulation/Shapes/Shapes.hpp"
#include "encapsulation/Color/EColor.hpp"

namespace bmb::rlib {
class Shapes2D {
 public:
    /**
     * @brief Construct a new Shapes 2 D object (ex: Rectangle)
     *
     * @param tag
     * @param size
     * @param position
     * @param colors
     */
    Shapes2D(const bmb::rlib::shapes::ShapesTag_t &tag, EVector2<float> size, EVector2<float> position, bmb::rlib::EColor color)
        : _tag(tag), _size(size), _position(position), _color(color), _thick(0), _isVisible(true) {}

    /**
     * @brief Construct a new Shapes 2 D object (ex: cirlce)
     *
     * @param tag
     * @param center
     * @param radius
     * @param color
     */
    Shapes2D(const bmb::rlib::shapes::ShapesTag_t &tag, const EVector2<float> &center, const float &radius, const bmb::rlib::EColor &color)
        : _tag(tag), _center(center), _radius(radius), _color(color), _thick(0), _isVisible(true) {}

    /**
     * @brief Destroy the Shapes 2 D object
     *
     */
    virtual ~Shapes2D(void) {}

    /**
     * @brief Display the Object2D
     *
     */
    virtual void display(void) const {}

    /**
     * @brief Display with Lines
     *
     */
    virtual void displayLines(void) const {};

    /**
     * @brief
     *
     * @return bmb::rlib::shapes::ShapesTag_t
     */
    bmb::rlib::shapes::ShapesTag_t tag() const {
        return _tag;
    }

    /**
     * @brief Get the Position object
     *
     * @return bmb::rlib::EVector2<float>
     */
    bmb::rlib::EVector2<float> getPosition(void) const {
        return _position;
    }

    /**
     * @brief Get the Size object
     *
     * @return bmb::rlib::EVector2<float>
     */
    bmb::rlib::EVector2<float> getSize(void) const {
        return _size;
    }

    /**
     * @brief Get the Color object
     *
     * @return bmb::rlib::EColor
     */
    bmb::rlib::EColor getColor(void) const {
        return _color;
    }

    /**
     * @brief Set the Thick object
     *
     * @param thick
     * @return Shapes2D&
     */
    Shapes2D &setThick(const float &thick) {
        _thick = thick;
        return *this;
    }

    /**
     * @brief Get the Thick object
     *
     * @return float
     */
    float getThick(void) const {
        return _thick;
    }

    /**
     * @brief Set the Position object
     *
     * @param position
     * @return Shapes2D&
     */
    Shapes2D &setPosition(const EVector2<float> &position) {
        _position = position;
        return *this;
    }

    /**
     * @brief Move
     *
     * @param move
     * @return Shapes2D&
     */
    virtual Shapes2D &move(const EVector2<float> &move) {
        _position += move;
        return *this;
    }

    /**
     * @brief Set the Size object
     *
     * @param size
     * @return Shapes2D&
     */
    Shapes2D &setSize(const EVector2<float> &size) {
        _size = size;
        return *this;
    }

    /**
     * @brief Set the Color object
     *
     * @param color
     * @return Shapes2D&
     */
    Shapes2D &setColor(bmb::rlib::EColor const &color) {
        _color = color;
        return *this;
    }

    /**
     * @brief Set the Center object
     *
     * @param center
     * @return Shapes2D&
     */
    Shapes2D &setCenter(const EVector2<float> &center) {
        _center = center;
        return *this;
    }

    /**
     * @brief Get the Center object
     *
     * @return bmb::rlib::EVector2<float>
     */
    bmb::rlib::EVector2<float> getCenter(void) const {
        return _center;
    }

    /**
     * @brief Set the Radius object
     *
     * @param radius
     * @return Shapes2D&
     */
    Shapes2D &setRadius(const float &radius) {
        _radius = radius;
        return *this;
    }

    /**
     * @brief Get the Radius object
     *
     * @return float
     */
    float getRadius(void) const {
        return _radius;
    }

    /**
     * @brief Return a reference to _isVisible
     *
     * @return true
     * @return false
     */
    bool &isVisible(void) {
        return _isVisible;
    }

 protected:
    const bmb::rlib::shapes::ShapesTag_t _tag;
    EVector2<float> _size;
    EVector2<float> _position;
    EVector2<float> _center;
    EColor          _color;
    float           _radius;
    float           _thick;
    bool            _isVisible;
};
}  // namespace bmb::rlib
