/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** SelectMap
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
class SelectMap : public Scene {
 public:
    /**
     * @brief Construct a new Select Map object
     *
     */
    SelectMap(void);

    /**
     * @brief Destroy the Select Map object
     *
     */
    ~SelectMap(void);

    /**
     * @brief Load the Select Map
     *
     */
    void load(void);

    /**
     * @brief Unload the SelectMap
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
     * @brief Center the camera on the map
     *
     */
      void centerCameraMap(void);

 private:
    /**
     * @brief
     *
     * @param cManager
     */
    void updateGametoPlay(bmb::character::CharacterManager &cManager);

    bmb::rlib::EVector2<int>                _sizeWindow;
    std::vector<std::string>                _listPath;
    std::unordered_map<int, bmb::Map>       _listMap;
    int                                     _index;
};
}  // namespace bmb::scene
