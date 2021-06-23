/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Button
*/

#include "Widget/Button.hpp"

bmb::widget::Button::Button(const bmb::rlib::shapes2D::ERectangle &rect)
    : _model(rect), _imageType(false), _hover(false), _action(false), _state(0), _defColor(rect.getColor()),
    _hoverColor(bmb::rlib::color::White), _downColor(bmb::rlib::color::White) {}

bmb::widget::Button::~Button(void) {}

bmb::widget::Button &bmb::widget::Button::setModel(const bmb::rlib::shapes2D::ERectangle &model) {
    _model = model;
    _defColor = _model.getColor();
    return *this;
}

bmb::rlib::shapes2D::ERectangle &bmb::widget::Button::getModel(void) {
    return _model;
}

bmb::widget::Button &bmb::widget::Button::hide(void) {
    _defColor = bmb::rlib::color::Transparent;
    _hoverColor = bmb::rlib::color::Transparent;
    _downColor = bmb::rlib::color::Transparent;

    return *this;
}

int bmb::widget::Button::isHover(const Vector2f &pos) {
    Vector2 tmpPos = {pos._x, pos._y};

    if (CheckCollisionPointRec(tmpPos, _model.getRectangleRlib())) {
        _hover = true;
        if (_state == 1 || _state == 2)
            _state = 2;
        else
            _state = 1;
        _model.setColor(_hoverColor);
        _text.setFontSize(_defSizeText + 10);
        return _state;
    }
    _state = 0;
    _hover = false;
    _model.setColor(_defColor);
    _text.setFontSize(_defSizeText);
    return _state;
}

int bmb::widget::Button::isHover(const bmb::rlib::shapes2D::ERectangle &rec) {
    if (CheckCollisionRecs(rec.getRectangleRlib(), _model.getRectangleRlib())) {
        if (_state == 1 || _state == 2)
            _state = 2;
        else
            _state = 1;
        _hover = true;
        _model.setColor(_hoverColor);
        _text.setFontSize(_defSizeText + 10);
        return _state;
    }
    _state = 0;
    _hover = false;
    _model.setColor(_defColor);
    _text.setFontSize(_defSizeText);
    return _state;
}

bool bmb::widget::Button::action(bool down, bool release) {
    if (!_hover)
        return false;
    if (down) {
        _text.setFontSize(_defSizeText - 5);
        _model.setColor(_downColor);
    } else {
        _model.setColor(_hoverColor);
        _text.setFontSize(_defSizeText + 10);
        _state = 2;
    }
    if (release) {
        return true;
    }
    return false;
}


void bmb::widget::Button::display(void) {
    if (!_imageType)
        displayWithText();
}

bmb::widget::Button &bmb::widget::Button::setDefaultColor(const bmb::rlib::EColor &color) {
    _defColor = color;
    _model.setColor(_defColor);

    return *this;
}

bmb::rlib::EColor bmb::widget::Button::getDefaultColor(void) const {
    return _defColor;
}

bmb::widget::Button &bmb::widget::Button::setHoverColor(const bmb::rlib::EColor &color) {
    _hoverColor = color;

    return *this;
}

bmb::rlib::EColor bmb::widget::Button::getHoverColor(void) const {
    return _hoverColor;
}

bmb::widget::Button &bmb::widget::Button::setDownColor(const bmb::rlib::EColor &color) {
    _downColor = color;

    return *this;
}

bmb::rlib::EColor bmb::widget::Button::getDownColor(void) const {
    return _downColor;
}

bmb::widget::Button &bmb::widget::Button::setColor(const bmb::rlib::EColor &color) {
    _model.setColor(color);

    return *this;
}

bmb::rlib::EColor bmb::widget::Button::getColor(void) const {
    return _model.getColor();
}

bmb::widget::Button &bmb::widget::Button::setString(const std::string &text) {
    _text.setString(text);
    _defSizeText = _text.getFontSize();

    return *this;
}

bmb::widget::Button &bmb::widget::Button::setStringSize(const int &size) {
    _text.setFontSize(size);
    _defSizeText = _text.getFontSize();

    return *this;
}

bmb::widget::Button &bmb::widget::Button::setStringColor(const bmb::rlib::EColor &color) {
    _text.setColor(color);

    return *this;
}

void bmb::widget::Button::displayWithText(void) {
    float x = _model.getPosition()._x + (_model.getSize()._x / 2) - (MeasureText(_text.getString().c_str(), _text.getFontSize()) / 2);
    float y = _model.getPosition()._y + (_model.getSize()._y / 2) - (_text.getFontSize() / 2);
    Vector2f position = {x, y};
    _text.setPosition(position);

    _model.display();
    _text.draw();
}

bmb::widget::TagWidget_t bmb::widget::Button::tag(void) const {
    return bmb::widget::BUTTON;
}
