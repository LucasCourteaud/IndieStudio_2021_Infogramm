/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Button
*/

#pragma once

#include "Widget/Widget.hpp"

namespace bmb::widget {
class Button : public Widget {
 public:

    /**
     * @brief Construct a new Button object
     *
     * @param rect
     */
    Button(const bmb::rlib::shapes2D::ERectangle &rect = bmb::rlib::shapes2D::ERectangle(Vector2f(0.f, 0.f), Vector2f(0.f, 0.f)));

    /**
     * @brief Destroy the Button object
     *
     */
    ~Button(void);

    /**
     * @brief Set the Model object
     *
     * @param model
     * @return Button&
     */
    Button &setModel(const bmb::rlib::shapes2D::ERectangle &model);

    /**
     * @brief Get the Model object
     *
     * @return bmb::rlib::shapes2D::ERectangle&
     */
    bmb::rlib::shapes2D::ERectangle &getModel(void);

    /**
     * @brief
     *
     * @return Button&
     */
    Button &hide(void);

    /**
     * @brief Check if a point is hover the button (ex: mousse)
     *
     * @param pos
     * @return true / false
     */
    int isHover(const Vector2f &pos);

    /**
     * @brief Check is a rect is hover with button
     *
     * @param rec
     * @return true / false
     */
    int isHover(const bmb::rlib::shapes2D::ERectangle &rec);

    /**
     * @brief
     *
     * @param down
     * @param release
     * @return true / false
     */
    bool action(bool down, bool release);

    /**
     * @brief
     *
     */
    void display(void);

    /**
     * @brief Set the Default Color object
     *
     * @param color
     * @return Button&
     */
    Button &setDefaultColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get the Default Color object
     *
     * @return bmb::rlib::EColor
     */
    bmb::rlib::EColor getDefaultColor(void) const;

    /**
     * @brief Set the Hover Color object
     *
     * @param color
     * @return Button&
     */
    Button &setHoverColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get the Hover Color object
     *
     * @return bmb::rlib::EColor
     */
    bmb::rlib::EColor getHoverColor(void) const;

    /**
     * @brief Set the Down Color object
     *
     * @param color
     * @return Button&
     */
    Button &setDownColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get the Down Color object
     *
     * @return bmb::rlib::EColor
     */
    bmb::rlib::EColor getDownColor(void) const;

    /**
     * @brief Set the Color object
     *
     * @param color
     * @return Button&
     */
    Button &setColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get the Color object
     *
     * @return bmb::rlib::EColor
     */
    bmb::rlib::EColor getColor(void) const;

    /**
     * @brief Set the String object
     *
     * @param text
     * @return Button&
     */
    Button &setString(const std::string &text);

    /**
     * @brief Set the String Size object
     *
     * @param size
     * @return Button&
     */
    Button &setStringSize(const int &size);

    /**
     * @brief Set the String Color object
     *
     * @param color
     * @return Button&
     */
    Button &setStringColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get Widget tag
     *
     * @return bmb::widget::TagWidget_t
     */
    bmb::widget::TagWidget_t tag(void) const;

 private:
    /**
     * @brief display button with text
     *
     */
    void displayWithText(void);

    /**
     * @brief Display button with image
     *
     */
    // void displayWithImage(void);

    bmb::rlib::shapes2D::ERectangle _model;
    bool                            _imageType;
    bool                            _hover;
    bool                            _action;
    int                             _state;
    bmb::rlib::EColor               _defColor;
    bmb::rlib::EColor               _hoverColor;
    bmb::rlib::EColor               _downColor;
    bmb::rlib::EText                _text;
    int                             _defSizeText;
};
}  // namespace bmb::widget
