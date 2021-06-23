/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** controller
*/

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "raylib.h"
#include <unordered_map>

namespace bmb::rlib::control {
typedef enum {
    DISCONNECT = -1,
    UNKNOWN = 0,
    ARROW_UP,
    ARROW_RIGHT,
    ARROW_DOWN,
    ARROW_LEFT,
    BUTTON_1,
    BUTTON_2,
    BUTTON_3,
    BUTTON_4,
    TRIGGER_LEFT_FRONT,
    TRIGGER_LEFT_BACK,
    TRIGGER_RIGHT_FRONT,
    TRIGGER_RIGHT_BACK,
    SELECT,
    START,
    HOME,
    ANALOG_PRESSED_LEFT,
    ANALOG_PRESSED_RIGHT,
    ANALOG_AXIS_LEFT,
    ANALOG_AXIS_RIGHT
} CONTROL_NAME_T;

static std::unordered_map<int, CONTROL_NAME_T> mapping_control = {
    {GAMEPAD_BUTTON_RIGHT_FACE_DOWN , BUTTON_3            },
    {GAMEPAD_BUTTON_MIDDLE_LEFT     , SELECT              },
    {GAMEPAD_BUTTON_RIGHT_FACE_UP   , BUTTON_1            },
    {GAMEPAD_BUTTON_RIGHT_FACE_LEFT , BUTTON_4            },
    {GAMEPAD_BUTTON_RIGHT_FACE_RIGHT, BUTTON_2            },
    {GAMEPAD_AXIS_RIGHT_TRIGGER     , ANALOG_PRESSED_RIGHT},
    {GAMEPAD_AXIS_LEFT_TRIGGER      , ANALOG_PRESSED_LEFT },
    {GAMEPAD_BUTTON_LEFT_TRIGGER_1  , TRIGGER_LEFT_FRONT  },
    {GAMEPAD_BUTTON_LEFT_TRIGGER_2  , TRIGGER_LEFT_BACK   },
    {GAMEPAD_BUTTON_RIGHT_TRIGGER_1 , TRIGGER_RIGHT_FRONT },
    {GAMEPAD_BUTTON_RIGHT_TRIGGER_2 , TRIGGER_RIGHT_BACK  },
    {GAMEPAD_BUTTON_MIDDLE_RIGHT    , START               },
    {GAMEPAD_BUTTON_LEFT_FACE_UP    , ARROW_UP            },
    {GAMEPAD_BUTTON_LEFT_FACE_RIGHT , ARROW_RIGHT         },
    {GAMEPAD_BUTTON_LEFT_FACE_DOWN  , ARROW_DOWN          },
    {GAMEPAD_BUTTON_LEFT_FACE_LEFT  , ARROW_LEFT          },
    {GAMEPAD_BUTTON_MIDDLE          , HOME                },
};
}  // namespace bmb::rlib::control

#endif /* !CONTROLLER_H_ */
