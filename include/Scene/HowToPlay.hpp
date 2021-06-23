/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** HowToPlay
*/

#include "Scene/Scene.hpp"
#include "encapsulation/Image/EImage.hpp"

#pragma once

namespace bmb::scene {
class HowToPlay : public Scene {
 public:
    /**
     * @brief Construct a new HowToPlay object
     *
     */
    HowToPlay(void);

    /**
     * @brief Destroy the HowToPlay object
     *
     */
    ~HowToPlay(void);

    /**
     * @brief Load the HowToPlay
     *
     */
    void load(void);

    /**
     * @brief Unload the HowToPlay
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
    Vector2i                                            _sizeWindow;
    int                                                 _index;
};
}  // namespace bmb::scene
