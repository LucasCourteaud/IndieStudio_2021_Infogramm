/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Entity
*/

#include <string>

#pragma once

namespace bmb::entity {

    typedef enum {
        UNKNONWN = -1,
        CHARACTER,
        BLOCK,
        ITEMS
    } TAG_ENTITY;

class Entity {
 public:
    /**
     * @brief Destroy the Entity object
     *
     */
    virtual ~Entity() = default;

    /**
     * @brief Get the Tag object
     *
     * @return TAG_ENTITY
     */
    virtual TAG_ENTITY getTag(void) const = 0;
};
}  // namespace bmb::entity
