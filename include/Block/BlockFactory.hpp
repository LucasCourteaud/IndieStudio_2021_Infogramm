/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** BlockFactory
*/

#include <unordered_map>
#include "Block/Wall.hpp"
#include "Block/Barrel.hpp"
#include "Block/Spawn.hpp"
#include "Block/Empty.hpp"
#include "Error/AppError.hpp"

#pragma once

namespace bmb::block {
    using uniqueBlock = std::shared_ptr<bmb::block::Block>;
    using blockCreator = uniqueBlock (*)(void);

class BlockFactory {
 public:

    /**
     * @brief Create a Block object
     *
     * @param tag
     * @return uniqueBlock
     */
    static uniqueBlock createBlock(BlockTag const &tag);

 private:
    /**
     * @brief Create a Wall object
     *
     * @return uniqueBlock
     */
    static uniqueBlock createWall(void);

    /**
     * @brief Create a Barrel object
     *
     * @return uniqueBlock
     */
    static uniqueBlock createBarrel(void);

    /**
     * @brief Create a Spawn object
     *
     * @return uniqueBlock
     */
    static uniqueBlock createSpawn(void);

    /**
     * @brief Create a Empty object
     *
     * @return uniqueBlock
     */
    static uniqueBlock createEmpty(void);
};
}
