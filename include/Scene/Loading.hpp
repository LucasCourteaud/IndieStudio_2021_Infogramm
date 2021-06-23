/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Loading
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
class Loading : public Scene {
 public:
    /**
     * @brief Construct a new Loading object
     *
     */
    Loading(void);

    /**
     * @brief Destroy the Loading object
     *
     */
    ~Loading(void);

    /**
     * @brief Load the Scene Loading
     *
     */
    void load(void);

    /**
     * @brief Unload the scene Loading
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
     * @param audioManager
     */
    void loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager);

    /**
     * @brief
     *
     * @param window
     */
    void loadTexture(uniqueWindow &window);

 private:
    bmb::rlib::EVector2<int> _sizeWindow;
};
}  // namespace bmb::scene

