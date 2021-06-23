/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Wall
*/

#include <string>
#include "Block/Block.hpp"
#include "encapsulation/Color/EColor.hpp"

#pragma once

#define PATH_OBJ_WALL    "assets/blocks/wall.obj"

namespace bmb::block {
class Wall : public Block {
 public:

    /**
     * @brief Construct a new Wall object
     *
     */
    Wall(void);

    /**
     * @brief Destroy the Wall object
     *
     */
    ~Wall();

    /**
     * @brief display Wall block
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
