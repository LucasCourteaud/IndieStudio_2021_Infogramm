/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Widget
*/

#pragma once

#include "System/System.hpp"
#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"
#include "encapsulation/Shapes/Shapes2D/ECircle.hpp"
#include "encapsulation/Text/EText.hpp"

namespace bmb::widget {
    typedef enum {
        BUTTON,
    } TagWidget_t;
};

namespace bmb {
class Widget {
 public:
    /**
     * @brief Destroy the Widget object
     *
     */
    virtual ~Widget() = default;

    /**
     * @brief
     *
     * @return bmb::widget::TagWidget_t
     */
    virtual bmb::widget::TagWidget_t tag(void) const = 0;
};
}  // namespace bmb
