/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Map
*/

#include <vector>
#include "Block/BlockFactory.hpp"

#pragma once

#define DEFAULT_MAP_PATH        "map/default_map.bmb"

namespace bmb {
class Map {
 public:
    /**
     * @brief Construct a new Map object
     *
     */
    Map(void);

    /**
     * @brief Destroy the Map object
     *
     */
    ~Map(void);

    /**
     * @brief
     *
     * @param newBlock
     * @return Map&
     */
    Map &add(bmb::block::uniqueBlock newBlock);

    /**
     * @brief
     *
     * @return Map&
     */
    Map &draw(void);

    /**
     * @brief Set the Name object
     *
     * @param name
     * @return Map&
     */
    Map &setName(const std::string &name);

    /**
     * @brief Get the Name object
     *
     * @return std::string
     */
    std::string getName(void) const;

    /**
     * @brief
     *
     * @return Map&
     */
    Vector2f &offset(void);

    /**
     * @brief
     *
     * @param l
     * @param c
     * @return Map&
     */
    Map &remove(size_t const &l, size_t const &c);

    /**
     * @brief
     *
     * @param block
     * @return Map&
     */
    Map &remove(const bmb::block::uniqueBlock &block);

    /**
     * @brief
     *
     * @return Map&
     */
    Map &newLine(void);

    /**
     * @brief
     *
     * @return Map&
     */
    Map &clear(void);

    /**
     * @brief
     *
     * @param pos
     * @return bmb::block::uniqueBlock&
     */
    std::vector<bmb::block::uniqueBlock> &operator[](const size_t &pos);

    /**
     * @brief
     *
     * @return size_t
     */
    size_t size(void) const;

    /**
     * @brief Set and Get the origin of the map
     *
     * @return size_t&
     */
    Vector3f &origin(void);

    /**
     * @brief
     *
     * @return Vector2f&
     */
    Vector2i &max(void);

 private:
    std::string _name;
    std::unordered_map<size_t, std::vector<bmb::block::uniqueBlock>> _listBlocks;
    Vector2f _offset;
    int _index;
    Vector3f _orig;
    Vector2i _max;
};
}  // namespace bmb
