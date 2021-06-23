/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Empty
*/

#include <string>
#include "Block/Block.hpp"
#include "encapsulation/Color/EColor.hpp"

#pragma once

#define PATH_OBJ_EMPTY    "assets/blocks/barrel.obj"

namespace bmb::block {
class Empty : public Block {
 public:

    /**
     * @brief Construct a new Empty object
     *
     */
    Empty(void);

    /**
     * @brief Destroy the Empty object
     *
     */
    ~Empty(void);

    /**
     * @brief display Empty block
     *
     */
    void display(void);

    /**
     * @brief destroy Empty block
     *
     * @return true
     * @return false
     */
    bool destroy(void);

    std::shared_ptr<bmb::items::PowerUp> &getPowerUp(void) = delete;
};
}  // namespace bmb::block
