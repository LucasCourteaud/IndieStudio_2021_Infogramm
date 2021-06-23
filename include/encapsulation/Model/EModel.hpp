/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EModel
*/

#pragma once

#include "raylib.h"
#include <string>
#include <vector>
#include <memory>
#include "encapsulation/Vector/vector.h"
#include "encapsulation/Color/EColor.hpp"

namespace bmb::rlib {
class EModel {
 public:

    /**
     * @brief Construct a new EModel object
     *
     * @param pathModel
     */
    EModel(const std::string &pathModel);

    /**
     * @brief Construct a new EModel object
     *
     */
    EModel(void);

    /**
     * @brief Destroy the EModel object
     *
     */
    ~EModel(void);

    /**
     * @brief
     *
     * @param modeml
     * @return EModel&
     */
    EModel &load(const std::string &pathModel);

    /**
     * @brief
     *
     * @return EModel&
     */
    void unload(void);

    /**
     * @brief
     *
     * @param pathAnimation
     * @return EModel&
     */
    EModel &loadAnimation(const std::string &pathAnimation);

    /**
     * @brief
     *
     */
    void unloadAnimation(void);

    /**
     * @brief
     *
     * @return true / false
     */
    bool isLoaded(void) const;

    /**
     * @brief
     *
     * @return false / true
     */
    bool isAnimated(void) const;

    /**
     * @brief
     *
     * @param move
     * @return EModel&
     */
    EModel &move(const Vector3f &move);

    /**
     * @brief Set the Position object
     *
     * @return EModel&
     */
    EModel &setPosition(const Vector3f &position);

    /**
     * @brief Get the Position object
     *
     * @return Vector3f
     */
    Vector3f getPosition(void) const;

    /**
     * @brief Set the Size object
     *
     * @param size
     * @return EModel&
     */
    EModel &setSize(const Vector3f &size);

    /**
     * @brief Get the Size object
     *
     * @return Vector3f
     */
    Vector3f getSize(void) const;

    /**
     * @brief Set the Color object
     *
     * @param color
     * @return EModel&
     */
    EModel &setColor(const EColor &color);

    /**
     * @brief Get the Color object
     *
     * @return EColor
     */
    EColor getColor(void) const;

    /**
     * @brief
     *
     * @param transform
     * @return EModel&
     */
    EModel &transform(const Matrix &transform);

    /**
     * @brief
     *
     * @param anim
     * @return EModel&
     */
    EModel &updateAnimation(const int &anim);

    /**
     * @brief Set the Texture object
     *
     * @param texture
     * @return EModel&
     */
    EModel &setTexture(const Texture &texture, const int &materials = 0);

     /**
      * @brief
      *
      * @param rotationAxis
      * @param rotationAngle
      * @param scale
      */
    void display(const Vector3f &rotationAxis, const float &rotationAngle);

    /**
     * @brief
     *
     * @param scale
     */
    void display(const float &scale);

    /**
     * @brief return reference to _isVisible
     *
     * @return true
     * @return false
     */
    bool &isVisible(void);

    /**
     * @brief Get the Bounding Box object
     *
     * @return BoundingBox
     */
    BoundingBox getBoundingBox(void) const;

 private:
    std::string                     _pathModel;
    Model                           _model;
    ModelAnimation *                _animation;
    int                             _animsCount;
    std::vector<int>                _animsFrameCounter;
    bool                            _isLoaded;
    bool                            _isAnimated;
    Vector3f                        _position;
    Vector3f                        _size;
    EColor                          _color;
    BoundingBox                     _bounds;
    bool                            _isVisible;
};
}  // namespace bmb::rlib
