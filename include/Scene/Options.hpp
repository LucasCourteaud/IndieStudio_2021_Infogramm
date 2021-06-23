/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Options
*/

#include "encapsulation/Text/EText.hpp"
#include "Widget/Widget.hpp"
#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "Widget/Button.hpp"
#include "tools/tools.hpp"
#include "Scene/Scene.hpp"

#pragma once

const std::vector<std::string> timer {"1:00", "2:00", "3:00"};

namespace bmb::scene {
class Options : public Scene {
 public:
    /**
     * @brief Construct a new Options object
     *
     */
    Options(void);

    /**
     * @brief Destroy the Options object
     *
     */
    ~Options(void);

    /**
     * @brief Load the scene Options
     *
     */
    void load(void);

    /**
     * @brief Unload the scene unload
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
     * @brief Loop of the scene options
     *
     * @param window
     * @param cManager
     * @param audioManager
     */
    void loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager);

 private:
    bmb::rlib::EVector2<int> _sizeWindow;
    std::unordered_map<std::string, std::string> _timer;
    std::unordered_map<std::string, std::string> _unTimer;
};
}  // namespace bmb::scene
