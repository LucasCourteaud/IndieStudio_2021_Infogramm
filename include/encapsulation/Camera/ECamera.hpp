/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** ECamera
*/

#include "raylib.h"
#include "encapsulation/Vector/vector.h"

#pragma once

typedef struct Vector3 Vector3_t;

namespace bmb::rlib {
class ECamera {
 public:
    /**
     * @brief Construct a new ECamera object
     *
     */
    ECamera(void);

    /**
    * @brief Destroy the ECamera object
    *
    */
    ~ECamera(void);

    /**
     * @brief Set the Position object
     *
     * @param position
     * @return ECamera&
     */
    ECamera &setPosition(EVector3<float> position);

    /**
     * @brief Set the Target object
     *
     * @param target
     * @return ECamera&
     */
    ECamera &setTarget(EVector3<float> target);

    /**
     * @brief Set the Up object
     *
     * @param up
     * @return ECamera&
     */
    ECamera &setUp(EVector3<float> up);

    /**
     * @brief
     *
     * @param fov
     * @return ECamera&
     */
    ECamera &setFOV(float fov);

    /**
     * @brief Set the Projection object
     *
     * @param projection
     * @return ECamera&
     */
    ECamera &setProjection(int projection);

    /**
     * @brief Get the Camera object
     *
     * @return Camera&
     */
    Camera &getCamera(void);

    /**
     * @brief Set the Camera Mode object
     *
     * @param mode
     */
    void setCameraMode(CameraMode mode);

    /**
     * @brief Update the Camera
     *
     */
    void update(void);

    /**
     * @brief Begin the 3D Mode
     *
     */
    void beginMode3D(void);

    /**
     * @brief End the 3D Mode
     *
     */
    void endMode3D(void);

 private:
    Camera _camera;
};
}
