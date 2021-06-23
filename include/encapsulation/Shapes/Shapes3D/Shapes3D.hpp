/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Shapes3D
*/

#include "encapsulation/Vector/EVector3.hpp"
#include "encapsulation/Shapes/Shapes.hpp"
#include "encapsulation/Color/EColor.hpp"

#pragma once

namespace bmb::rlib {
class Shapes3D : public Shapes {
 public:
    /**
     * @brief Construct a new Shapes 3 D object
     *
     */

    Shapes3D(bmb::rlib::shapes::ShapesTag_t tag, EVector3<float> size,
    EVector3<float> position, bmb::rlib::EColor colorShape)
        : _tag(tag), _size(size), _position(position), _color(colorShape), _isVisible(true) {
    }

    /**
     * @brief Construct a new Shapes 3 D object
     *
     * @param tag
     * @param center
     * @param radius
     * @param color
     */
    Shapes3D(bmb::rlib::shapes::ShapesTag_t tag, const EVector3<float> &center, const float &radius, const bmb::rlib::EColor &color)
        : _tag(tag), _center(center), _radius(radius), _color(color), _isVisible(true) {
    }

    /**
     * @brief Destroy the Shapes 3 D object
     *
     */
    virtual ~Shapes3D(void) {}

    /**
     * @brief Get the Position object
     *
     * @return bmb::rlib::EVector3<float>
     */
    bmb::rlib::EVector3<float> getPosition(void) const {
        return _position;
    }

    /**
     * @brief Get the Size object
     *
     * @return bmb::rlib::EVector3<float>
     */
    bmb::rlib::EVector3<float> getSize(void) const {
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
     * @brief Set the Position object
     *
     * @param position
     * @return Shapes3D&
     */
    Shapes3D &setPosition(EVector3<float> position) {
        _position = position;
        return *this;
    }

    /**
     * @brief Move
     *
     * @param move
     * @return Shapes3D&
     */
    Shapes3D &move(EVector3<float> move) {
        _position += move;
        return *this;
    }

    /**
     * @brief Set the Size object
     *
     * @param size
     * @return Shapes3D&
     */
    Shapes3D &setSize(EVector3<float> size) {
        _size = size;
        return *this;
    }

    /**
     * @brief Set the Color object
     *
     * @param color
     * @return Shapes3D&
     */
    Shapes3D &setColor(bmb::rlib::EColor const &color) {
        _color = color;
        return *this;
    }

    /**
     * @brief Get ShapesTag
     *
     * @return bmb::rlib::shapes::ShapesTag_t
     */
    bmb::rlib::shapes::ShapesTag_t tag(void) const {
        return _tag;
    }

    /**
     * @brief Display shape
     *
     */
    virtual void display(void) const = 0;

    /**
     * @brief Return a reference to _isVisible
     *
     * @return true
     * @return false
     */
    bool &isVisible(void) {
        return _isVisible;
    }

    /**
     * @brief Set the Center object
     *
     * @param center
     * @return Shapes3D&
     */
    Shapes3D &setCenter(const Vector3f &center) {
        _center = center;

        return *this;
    }

    /**
     * @brief Get the Center object
     *
     * @return Vector3f
     */
    Vector3f getCenter(void) const {
        return _center;
    }

    /**
     * @brief Set the Radius object
     *
     * @param radius
     * @return Shapes3D&
     */
    Shapes3D &setRadius(const float &radius) {
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

 protected:
    const bmb::rlib::shapes::ShapesTag_t    _tag;
    EVector3<float>                         _position;
    EVector3<float>                         _size;
    EColor                                  _color;
    bool                                    _isVisible;
    EVector3<float>                         _center;
    float                                   _radius;
};
}  // namespace bmb::rlib