/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Items
*/

#include "Entity/Entity.hpp"

#pragma once

namespace bmb::items {
class Items : public bmb::entity::Entity {
 public:
    /**
     * @brief Construct a new Items object
     *
     */
    Items(void) {}

    /**
     * @brief Destroy the Items object
     *
     */
    virtual ~Items(void) {}

    /**
     * @brief Get the Tag object
     *
     * @return bmb::entity::TAG_ENTITY
     */
    bmb::entity::TAG_ENTITY getTag(void) const {
        return bmb::entity::ITEMS;
    }
};
}  // namespace bmb::items
