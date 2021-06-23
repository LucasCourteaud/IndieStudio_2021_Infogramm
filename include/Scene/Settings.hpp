/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Settings
*/

#include "Scene/Scene.hpp"
#include "Widget/Widget.hpp"
#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "tools/tools.hpp"

#pragma once

namespace bmb::scene {
class Settings : public Scene {
 public:
    /**
     * @brief Construct a new Settings object
     *
     */
    Settings(void);

    /**
     * @brief Destroy the Settings object
     *
     */
    ~Settings(void);

    /**
     * @brief
     *
     */
    void load(void);

    /**
     * @brief
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

 private:
    /**
     * @brief Get the Resolution object
     *
     * @param oldResolution
     * @return bmb::rlib::EVector2<int>
     */
    bmb::rlib::EVector2<int> getResolution(const bmb::rlib::EVector2<int> &oldResolution);

    bmb::rlib::EVector2<int>                        _sizeWindow;
    std::unordered_map<std::string, std::string>    _screenMode;
};
}  // namespace bmb::scene
