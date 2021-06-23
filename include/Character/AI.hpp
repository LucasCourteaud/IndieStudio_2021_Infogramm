/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** AI
*/

#include "Character/Character.hpp"

#pragma once

namespace bmb::character {
class AI : public Character {
 public:
    /**
     * @brief Construct a new AI object
     *
     * @param indexAI
     */
    AI(indexEntity_u indexAI);

    /**
     * @brief Destroy the AI object
     *
     */
    ~AI(void);

    /**
     * @brief Get the Input object
     *
     * @return bmb::event::InputUser
     */
    bmb::event::InputUser getInput(void);

    /**
     * @brief Move AI
     *
     * @param input
     */
    bool move(const bmb::event::InputUser &input);

    /**
     * @brief Action AI
     *
     * @param input
     */
    void action(const bmb::event::InputUser &input,  const bmb::clock::Clock &clock);

    /**
     * @brief get type of character
     *
     * @return CharacterTag_t
     */
    CharacterTag_t type(void) const;
};
}  // namespace bmb::entity
