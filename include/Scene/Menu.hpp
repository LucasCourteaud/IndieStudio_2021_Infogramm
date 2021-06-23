/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Menu
*/

#include "encapsulation/Text/EText.hpp"
#include "Widget/Widget.hpp"
#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "Widget/Button.hpp"
#include "tools/tools.hpp"
#include "Scene/Scene.hpp"

#pragma once

namespace bmb::scene {
class Menu : public Scene {
 public:
    /**
     * @brief Construct a new Menu object
     *
     */
    Menu(void);

    /**
     * @brief Destroy the Menu object
     *
     */
    ~Menu(void);

    /**
     * @brief Load the menu
     *
     */
    void load(void);

    /**
     * @brief Unload the menu
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
    bmb::rlib::EVector2<int> _sizeWindow;
    bmb::rlib::EModel _decor;
    int               _timerMove;
};
}  // namespace bmb::scene
