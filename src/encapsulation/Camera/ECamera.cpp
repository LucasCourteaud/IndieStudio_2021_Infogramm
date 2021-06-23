/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** ECamera
*/

#include "encapsulation/Camera/ECamera.hpp"

bmb::rlib::ECamera::ECamera(void) {
    Vector3_t tmpP = { 0.0f, 10.0f, 10.0f };
    Vector3_t tmpT = { 0.0f, 1.8f, 0.0f };
    Vector3_t tmpU = { 0.0f, 1.0f, 0.0f };

    Camera camera = {0};
    camera.position = tmpP;
    camera.target = tmpT;
    camera.up = tmpU;
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    _camera = camera;
}

bmb::rlib::ECamera::~ECamera(void) {
}

bmb::rlib::ECamera &bmb::rlib::ECamera::setPosition(bmb::rlib::EVector3<float> position) {
    Vector3_t tmpP = {position._x, position._y, position._z};
    _camera.position = tmpP;
    return *this;
}

bmb::rlib::ECamera &bmb::rlib::ECamera::setTarget(bmb::rlib::EVector3<float> target) {
    Vector3_t tmpT = {target._x, target._y, target._z};
    _camera.target = tmpT;
    return *this;
}

bmb::rlib::ECamera &bmb::rlib::ECamera::setUp(EVector3<float> up) {
    Vector3_t tmpU = {up._x, up._y, up._z};
    _camera.up = tmpU;
    return *this;
}

bmb::rlib::ECamera &bmb::rlib::ECamera::setFOV(float fovy) {
    _camera.fovy = fovy;
    return *this;
}

bmb::rlib::ECamera &bmb::rlib::ECamera::setProjection(int projection) {
    _camera.projection = projection;
    return *this;
}

Camera &bmb::rlib::ECamera::getCamera(void) {
    return _camera;
}

void bmb::rlib::ECamera::setCameraMode(CameraMode mode) {
    SetCameraMode(_camera, mode);
}

void bmb::rlib::ECamera::update(void) {
    UpdateCamera(&_camera);
}

void bmb::rlib::ECamera::beginMode3D(void) {
    BeginMode3D(_camera);
}

void bmb::rlib::ECamera::endMode3D(void) {
    EndMode3D();
}