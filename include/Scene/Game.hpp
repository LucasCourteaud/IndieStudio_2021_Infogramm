/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Game
*/

#include "Scene/Scene.hpp"
#include "Map/Map.hpp"

#pragma once

namespace bmb::scene {
class Game : public Scene {
 public:
    /**
     * @brief Construct a new Game object
     *
     */
    Game(void);

    /**
     * @brief Destroy the Game object
     *
     */
    ~Game(void);

    /**
     * @brief Load the Game
     *
     */
    void load(void);

    /**
     * @brief Unload the Game
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
    /**
     * @brief
     *
     */
    void reset(bmb::character::CharacterManager &cManager);

    Vector2i                                    _sizeWindow;
    std::vector<int>                            _oldCharacterAlive;
    std::vector<int>                            _characterAlive;
    int                                         _timePass;
    std::unordered_map<std::string, int>        _gameRound;
    int                                         _timeRound;
    int                                         _timerDelay;
    Vector2f                                    _posCadre;
    std::unordered_map<int, Vector2f>           _pos;
};
}  // namespace bmb::scene
