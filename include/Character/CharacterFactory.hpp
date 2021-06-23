/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** CharacterFactory
*/

#include <memory>
#include <cstdarg>
#include "Character/Player.hpp"
#include "Character/AI.hpp"

#pragma once

namespace bmb::character {
    using uniqueCharacter = std::shared_ptr<bmb::character::Character>;

class CharacterFactory {
 public:

    using creatorCharacter = uniqueCharacter (*)(indexEntity_u, va_list);

    /**
     * @brief Construct a new Character Factory object
     *
     * @param tag
     */
    CharacterFactory(CharacterTag_t const &tag = UNKNOWN);

    /**
     * @brief Destroy the Character Factory object
     *
     */
    ~CharacterFactory(void);

    /**
     * @brief Set the tag
     *
     * @param tag
     * @return CharacterFactory&
     */
    CharacterFactory &operator<<(CharacterTag_t const &tag);

     /**
     * @brief Launch the fatcory
     *
     * @param ...
     * @return uniqueCharacter
     */
    uniqueCharacter launch(indexEntity_u indexEntity...);

 private:
    CharacterTag_t _tag;

    /**
     * @brief Create a Player object
     *
     * @param indexEntity
     * @param args
     * @return uniqueCharacter
     */
    static uniqueCharacter createPlayer(indexEntity_u indexEntity, va_list args);

    /**
     * @brief CreateAI Object
     *
     * @param indexEntity
     * @param args
     * @return uniqueCharacter
     */
    static uniqueCharacter createAI(indexEntity_u indexEntity, va_list args);

};
}  // namespace bmb::character
