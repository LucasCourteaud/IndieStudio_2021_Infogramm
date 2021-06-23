/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** InputUser
*/

#include "encapsulation/Vector/vector.h"
#include "encapsulation/Controller/controller.h"

#pragma once

#define DISCONNECTED(input) \
    (bool)(input.getButton() == bmb::rlib::control::DISCONNECT)

namespace bmb::event {
    using inputName = bmb::rlib::control::CONTROL_NAME_T;

    typedef enum {
        PRESSED,
        DOWN,
        RELEASE
    } TypeInput_t;

class InputUser {

 public:
    /**
     * @brief Construct a new Input User object
     *
     * @param input
     */
    InputUser(void);

    /**
     * @brief Destroy the Input User object
     *
     */
    ~InputUser(void);

    /**
     * @brief Get the Input object
     *
     * @return inputName
     */
    inputName getButton(void) const;

    /**
     * @brief Get the Axis object
     *
     * @return inputName
     */
    std::pair<inputName,bmb::rlib::EVector2<float>> getAnalogLeft(void) const;

    /**
     * @brief Get the Axis object
     *
     * @return inputName
     */
    std::pair<inputName,bmb::rlib::EVector2<float>> getAnalogRight(void) const;

    /**
     * @brief Set Button
     *
     * @param button
     * @return InputUser&
     */
    InputUser &setButton(const bmb::event::inputName &button);

    /**
     * @brief Set Analog Left
     *
     * @param button
     * @param axis
     * @return InputUser&
     */
    InputUser &setAnalogLeft(const bmb::event::inputName &analog, bmb::rlib::EVector2<float> axis);

    /**
     * @brief Set Analog Right
     *
     * @param button
     * @param axis
     * @return InputUser&
     */
    InputUser &setAnalogRight(const bmb::event::inputName &analog, bmb::rlib::EVector2<float> axis);

    /**
     * @brief Get type of input user
     *
     * @return TypeInput_t
     */
    TypeInput_t type(void) const;

    /**
     * @brief Set the Type Input object
     *
     * @param type
     * @return InputUser&
     */
    InputUser &setTypeInput(const TypeInput_t &type);

 private:
    inputName _button;
    inputName _analogL;
    inputName _analogR;
    bmb::rlib::EVector2<float> _axisL;
    bmb::rlib::EVector2<float> _axisR;
    TypeInput_t _type;
};
}  // namespace bmb
