/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** BlockFactory
*/

#include "Block/BlockFactory.hpp"

bmb::block::uniqueBlock bmb::block::BlockFactory::createBlock(BlockTag const &tag) {
    std::unordered_map<BlockTag, blockCreator> creator;

    creator[WALL]   = createWall;
    creator[BARREL] = createBarrel;
    creator[SPAWN]  = createSpawn;
    creator[EMPTY]  = createEmpty;
    for (auto it : creator)
        if (it.first == tag)
            return it.second();
    throw bmb::error::BlockFactoryError("BlockTag specified doesn't exist, can't build this block.");
}

bmb::block::uniqueBlock bmb::block::BlockFactory::createWall(void) {
    return uniqueBlock(new bmb::block::Wall);
}

bmb::block::uniqueBlock bmb::block::BlockFactory::createBarrel(void) {
    return uniqueBlock(new bmb::block::Barrel);
}

bmb::block::uniqueBlock bmb::block::BlockFactory::createSpawn(void) {
    return uniqueBlock(new bmb::block::Spawn);
}

bmb::block::uniqueBlock bmb::block::BlockFactory::createEmpty(void) {
    return uniqueBlock(new bmb::block::Empty);
}