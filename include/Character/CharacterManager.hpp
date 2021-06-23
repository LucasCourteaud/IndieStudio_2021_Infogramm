/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** CharacterManager
*/

#include <list>
#include <vector>
#include "Character/CharacterFactory.hpp"

#pragma once

namespace bmb::character {
class CharacterManager {
 public:

    /**
     * @brief Construct a new Character Manager object
     *
     * @param player
     * @param ai
     */
    CharacterManager(const size_t &player = 0, const size_t &ai = 0);

    /**
     * @brief Destroy the Character Manager object
     *
     */
    ~CharacterManager(void);

    /**
     * @brief Add n character to manager
     *
     * @param tag
     * @param n
     * @return CharacterManager&
     */
    CharacterManager &add(const CharacterTag_t &tag, const size_t &n = 1);

    /**
     * @brief Get the list of uniqueCharacter
     *
     * @return std::list<uniqueCharacter>
     */
    std::list<uniqueCharacter> get(void);

	/**
	 * @brief Overload the operator[]
	 *
	 * @param pos
	 * @return uniqueCharacter&
	 */
	uniqueCharacter &operator[](const size_t &pos);

    /**
     * @brief Get the Size of CharacterManager
     *
     * @return size_t
     */
    size_t size(void) const;

    /**
     * @brief Reset CharacterManager
     *
     * @return CharacterManager&
     */
    CharacterManager &reset(void);

 private:
    const std::vector<bmb::rlib::EColor> _colorList = {bmb::rlib::color::Red, bmb::rlib::color::Blue, bmb::rlib::color::Green, bmb::rlib::color::Yellow};
    CharacterFactory            _factory;
    int                      _indexEntity;
    int                      _indexController;
    std::list<uniqueCharacter>  _list;
};
}  // namespace bmb::character
