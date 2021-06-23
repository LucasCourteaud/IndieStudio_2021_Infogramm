/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Scoreboard
*/

#include "encapsulation/Text/EText.hpp"
#include "Widget/Widget.hpp"
#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "Widget/Button.hpp"
#include "tools/tools.hpp"
#include "Scene/Scene.hpp"
#include "Character/CharacterFactory.hpp"

#pragma once

namespace bmb::scene {
class Scoreboard : public Scene {
 public:
    /**
     * @brief Construct a new Scoreboard object
     *
     */
    Scoreboard(void);

    /**
     * @brief Destroy the Scoreboard object
     *
     */
    ~Scoreboard(void);

    /**
     * @brief Load the Scoreboard
     *
     */
    void load(void);

    /**
     * @brief Unload the Scoreboard
     *
     */
    void unload(void);

    /**
     * @brief Set the Up object
     *
     * @param window
     * @param cManager
     */
    void setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager);

    /**
     * @brief
     *
     * @param window
     * @param cManager
     */
    void loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager);

 private:
    bmb::rlib::EVector2<int>  _sizeWindow;
    bmb::rlib::EColor         _color;
};
}  // namespace bmb::scene
