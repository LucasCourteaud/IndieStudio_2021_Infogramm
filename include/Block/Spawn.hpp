/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Spawn
*/

#include <string>
#include "Block/Block.hpp"
#include "encapsulation/Color/EColor.hpp"

#pragma once

#define PATH_OBJ_SPAWN    "assets/blocks/spawn.obj"

namespace bmb::block {
class Spawn : public Block {
 public:

    /**
     * @brief Construct a new Spawn object
     *
     */
    Spawn(void);

    /**
     * @brief Destroy the Spawn object
     *
     */
    ~Spawn(void);

    /**
     * @brief display Spawn block
     *
     */
    void display(void);

    /**
     * @brief Set the Color object
     *
     * @param color
     */
    void setColor(bmb::rlib::EColor color);

   std::shared_ptr<bmb::items::PowerUp> &getPowerUp(void) = delete;
};
}
