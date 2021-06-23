/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Player
*/

#include "Character/Character.hpp"
#include "encapsulation/Controller/Controller.hpp"

#pragma once

namespace bmb::character {

class Player : public Character {
 public:
    /**
     * @brief Construct a new Player object
     *
     * @param indexController
     * @param indexPlayer
     */
    Player(indexController_u indexController = 0, indexEntity_u indexPlayer = 1);

    /**
     * @brief Destroy the Player object
     */
    ~Player(void);

    /**
     * @brief Get the Input object
     *
     * @return bmb::event::InputUser
     */
    bmb::event::InputUser getInput(void);

    /**
     * @brief Move Player with inut as params
     *
     * @param input
     */
    bool move(const bmb::event::InputUser &input);

    /**
     * @brief Action plyaer
     *
     * @param input
     */
    void action(const bmb::event::InputUser &input, const bmb::clock::Clock &clock);

    /**
     * @brief Display the playerr
     *
     */
    void display(void);

    /**
     * @brief Get tag of player character
     *
     * @return bmb::character::CharacterTag_t
     */
    bmb::character::CharacterTag_t type(void) const;

 private:
	/**
	 * @brief Move model
	 *
	 * @param input
	 */
	bool moveModel(const bmb::event::InputUser &input);

	/**
	 * @brief Move cursor
	 *
	 * @param input
	 */
	bool moveCursor(const bmb::event::InputUser &input);

    indexController_u _indexController;
    bmb::rlib::Controller _controller;
	bmb::event::InputUser _inputUser;
};
}  // namespace bmb::entity
