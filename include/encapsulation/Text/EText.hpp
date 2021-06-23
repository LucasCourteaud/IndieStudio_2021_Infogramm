/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EText
*/

#pragma once

#include "raylib.h"
#include "encapsulation/Color/EColor.hpp"
#include "encapsulation/Vector/vector.h"

namespace bmb::rlib {
class EText {
 public:

    /**
     * @brief Construct a new EText object
     *
     * @param text
     * @param position
     * @param fontSize
     * @param color
     */
    EText(const std::string &text = "", Vector2f position = {0.f, 0.f}, int fontSize = 20, bmb::rlib::EColor color = bmb::rlib::color::Black);

    /**
     * @brief Destroy the EText object
     *
     */
    ~EText(void);

    /**
     * @brief Draw Text
     *
     */
    void draw(void);

	/**
	 * @brief
	 *
	 * @param font
	 */
	void draw(const Font &font);

    /**
     * @brief Draw with parameters
     *
     * @param text
     * @param position
     * @param fontSize
     * @param color
     */
    void draw(const std::string &text, Vector2f position, int fontSize = 20, bmb::rlib::EColor color = bmb::rlib::color::Black);

    /**
     * @brief Set the Text object
     *
     * @param text
     * @return EText&
     */
    EText &setString(const std::string &text);

    /**
     * @brief Set the Position object
     *
     * @param position
     * @return EText&
     */
    EText &setPosition(const Vector2f &position);

    /**
     * @brief Set the Font Size object
     *
     * @param fontSize
     * @return EText&
     */
    EText &setFontSize(const int &fontSize);

    /**
     * @brief Set the Color object
     *
     * @param color
     * @return EText&
     */
    EText &setColor(const bmb::rlib::EColor &color);

    /**
     * @brief Get the String object
     *
     * @return std::string
     */
    std::string getString(void) const;

    /**
     * @brief Get the Position object
     *
     * @return Vector2
     */
    Vector2f getPosition(void) const;

    /**
     * @brief Get the Font Size object
     *
     * @return int
     */
    int getFontSize(void) const;

    /**
     * @brief Return a reference to _isVisible
     *
     * @return true
     * @return false
     */
    bool &isVisible(void);

 private:
    std::string _text;
    Vector2f _position;
    int _fontSize;
    bmb::rlib::EColor _color;
    bool _isVisible;
};
}  //namespace bmb::rlib
