/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** App
*/

#include <iostream>
#include <memory>
#include "System/System.hpp"
#include "Character/CharacterManager.hpp"
#include "encapsulation/Window/EWindow.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "Scene/Menu.hpp"
#include "Scene/Game.hpp"
#include "Scene/Settings.hpp"
#include "Scene/Pause.hpp"
#include "Scene/Options.hpp"
#include "Scene/SelectMap.hpp"
#include "Scene/Transition.hpp"
#include "Scene/HowToPlay.hpp"
#include "Scene/Loading.hpp"
#include "Scene/Scoreboard.hpp"

#pragma once

namespace bmb {
   using uniqueWindow = std::unique_ptr<rlib::EWindow>;

class App {

 public:
    /**
     * @brief Construct a new App object
     *
     */
    App(void);

    /**
     * @brief Destroy the App object
     *
     */
    ~App(void);

    /**
     * @brief Run the application
     *
     */
    void run(void);

 private:
   uniqueWindow _window;
   bmb::character::CharacterManager _manager;
   std::unordered_map<bmb::scene::SceneTag_t, std::shared_ptr<bmb::Scene>> _listScenes;
   bmb::rlib::AudioManager _audioManager;
};
}
//  namespace bmb
