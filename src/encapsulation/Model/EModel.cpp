/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EModel
*/

#include "encapsulation/Model/EModel.hpp"

bmb::rlib::EModel::EModel(const std::string &pathModel)
    : _animation(NULL), _animsCount(0), _isLoaded(false), _isAnimated(false),
    _position(0.f, 0.f, 0.f), _size(0.f, 0.f, 0.f), _color(bmb::rlib::color::Transparent),
    _isVisible(true) {
    load(pathModel);
}

bmb::rlib::EModel::EModel(void)
    : _pathModel(""), _animation(NULL), _animsCount(0), _isLoaded(false), _isAnimated(false),
    _position(0.f, 0.f, 0.f), _size(0.f, 0.f, 0.f), _color(bmb::rlib::color::Transparent),
    _isVisible(true) {}

bmb::rlib::EModel::~EModel(void) {
    unloadAnimation();
    unload();
}

bmb::rlib::EModel &bmb::rlib::EModel::load(const std::string &pathModel) {
    if (_isLoaded)
        unload();
    _isLoaded = true;
    _pathModel = pathModel;
    _model = LoadModel(_pathModel.c_str());
    _bounds = GetMeshBoundingBox(_model.meshes[0]);
    return *this;
}

void bmb::rlib::EModel::unload(void) {
    if (!_isLoaded)
        return;
    UnloadModel(_model);
}

bmb::rlib::EModel &bmb::rlib::EModel::loadAnimation(const std::string &pathAnimation) {
    if (_isAnimated)
        unloadAnimation();
    _isAnimated = true;
    _animation = LoadModelAnimations(pathAnimation.c_str(), &_animsCount);
    for (int i = 0; i < _animsCount; i++)
        _animsFrameCounter.push_back(0);
    return *this;
}

void bmb::rlib::EModel::unloadAnimation(void) {
    if (!_isAnimated)
        return;
    for (int i = 0; i < _animsCount; i++)
        UnloadModelAnimation(_animation[i]);
    RL_FREE(_animation);
    _animation = NULL;
    _isAnimated = false;
    _animsFrameCounter.clear();
    _animsCount = 0;
}

bool bmb::rlib::EModel::isLoaded(void) const {
    return _isLoaded;
}

bool bmb::rlib::EModel::isAnimated(void) const {
    return _isAnimated;
}


bmb::rlib::EModel &bmb::rlib::EModel::move(const Vector3f &move) {
    _position += move;
    return *this;
}

bmb::rlib::EModel &bmb::rlib::EModel::setPosition(const Vector3f &position) {
    _position = position;
    return *this;
}

Vector3f bmb::rlib::EModel::getPosition(void) const {
    return _position;
}

bmb::rlib::EModel &bmb::rlib::EModel::setSize(const Vector3f &size) {
    _size = size;
    return *this;
}

Vector3f bmb::rlib::EModel::getSize(void) const {
    return _size;
}

bmb::rlib::EModel &bmb::rlib::EModel::setColor(const EColor &color) {
    _color = color;
    return *this;
}

bmb::rlib::EColor bmb::rlib::EModel::getColor(void) const {
    return _color;
}

bmb::rlib::EModel &bmb::rlib::EModel::transform(const Matrix &transform) {
    _model.transform = transform;
    return *this;
}

bmb::rlib::EModel &bmb::rlib::EModel::updateAnimation(const int &anim) {
    _animsFrameCounter[anim] += 1;
    UpdateModelAnimation(_model, _animation[anim], _animsFrameCounter[anim]);
    if (_animsFrameCounter[anim] >= _animation[anim].frameCount)
        _animsFrameCounter[anim] = 0;
    return *this;
}

bmb::rlib::EModel &bmb::rlib::EModel::setTexture(const Texture &texture, const int &materials) {
    if (!_isLoaded)
        return *this;
    _model.materials[materials].maps[MAP_DIFFUSE].texture = texture;
    return *this;
}


void bmb::rlib::EModel::display(const Vector3f &rotationAxis, const float &rotationAngle) {
    if (!_isVisible)
        return;
    Vector3 tmpPosition = {_position._x, _position._y, _position._z};
    Vector3 tmpSize = {_size._x, _size._y, _size._z};
    Vector3 tmpRotattionAxis = {rotationAxis._x, rotationAxis._y, rotationAxis._z};

    DrawModelEx(_model, tmpPosition, tmpRotattionAxis, rotationAngle, tmpSize, _color.colorRlib());
}

void bmb::rlib::EModel::display(const float &scale) {
    if (!_isVisible)
        return;
    Vector3 tmpPosition = {_position._x, _position._y, _position._z};

    DrawModel(_model, tmpPosition, scale, _color.colorRlib());
}

bool &bmb::rlib::EModel::isVisible(void) {
    return _isVisible;
}

BoundingBox bmb::rlib::EModel::getBoundingBox(void) const {
    Vector3 limit1 = {_position._x - _size._x, _position._y - _size._y, _position._z - _size._z};
    Vector3 limit2 =  {_position._x + _size._x, _position._y + _size._y, _position._z + _size._z};
    BoundingBox box = {limit1, limit2};

    return box;
}