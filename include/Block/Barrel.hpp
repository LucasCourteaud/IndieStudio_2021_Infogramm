/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Barrel
*/

#include <string>
#include "Block/Block.hpp"
#include "encapsulation/Color/EColor.hpp"

#pragma once

#define CHANCE_BONUS        3

#define PATH_OBJ_BARREL     "assets/blocks/barrel.obj"

namespace bmb::block {
class Barrel : public Block {
 public:

    /**
     * @brief Construct a new Barrel object
     *
     */
    Barrel(void);

    /**
     * @brief Destroy the Barrel object
     *
     */
    ~Barrel();

    /**
     * @brief display Barrel block
     *
     */
    void display(void);

    /**
     * @brief destroy Barrel block
     *
     * @return Block&
     */
    bool destroy(void);
};
}
