/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EImage
*/

#include "encapsulation/Image/EImage.hpp"

bmb::rlib::EImage::EImage(const std::string &pathImage, const Vector2i &size, const Vector2f &pos, const bmb::rlib::EColor &color)
    : _isLoaded(false), _size(size), _position(pos), _color(color) {
    load(pathImage);
}

bmb::rlib::EImage::EImage(void)
    : _isLoaded(false), _color(bmb::rlib::color::White) {
}

bmb::rlib::EImage::~EImage(void) {
    unload();
}

bmb::rlib::EImage &bmb::rlib::EImage::load(const std::string &pathImage) {
    if (_isLoaded)
        unload();
    _isLoaded = true;
    _pathimage = pathImage;
    _image = LoadImage(_pathimage.c_str());
    ImageResize(&_image, 800, 600);
    _texture = LoadTextureFromImage(_image);
    return *this;
}

bmb::rlib::EImage &bmb::rlib::EImage::setTexture(const Texture &texture) {
    _texture = texture;

    return *this;
}

bmb::rlib::EImage &bmb::rlib::EImage::setPosition(const bmb::rlib::EVector2<float> &pos) {
    _position = pos;

    return *this;
}

Vector2f bmb::rlib::EImage::getPosition(void) const {
    return _position;
}

bmb::rlib::EImage &bmb::rlib::EImage::setColor(const bmb::rlib::EColor &color) {
    _color = color;

    return *this;
}

bmb::rlib::EColor bmb::rlib::EImage::getColor(void) const {
    return _color;
}

void bmb::rlib::EImage::unload(void) {
    if (!_isLoaded)
        return;
    UnloadImage(_image);
    UnloadTexture(_texture);
}

void bmb::rlib::EImage::display(void) {
    Vector2 pos = {_position._x, _position._y};

    DrawTextureV(_texture, pos, _color.colorRlib());
}