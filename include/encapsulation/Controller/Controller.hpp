/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Controller
*/

#include "encapsulation/Controller/controller.h"
#include "Character/InputUser.hpp"

#pragma once

namespace bmb::rlib {
class Controller {
 public:
    /**
     * @brief Construct a new Controller object
     *
     * @param indexController
     */
    Controller(const int &indexController = 0);

    /**
     * @brief Destroy the Controller object
     *
     */
    ~Controller(void);

    /**
     * @brief Operator=
     *
     * @param other
     * @return Controller&
     */
    Controller &operator=(Controller const &other);

    /**
     * @brief Get the Controller Input object
     *
     * @return bmb::event::InputUser
     */
    bmb::event::InputUser getControllerInput(void) const;

 private:
    int _indexController;
};
}  // namespace bmb::rlib
