/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** System
*/

#include "Map/MapParser.hpp"
#include "encapsulation/Vector/EVector2.hpp"

#pragma once

#define CSV_PATH_TEXTURE    "assets/csv/textures.csv"

namespace bmb {
class System {
 public:
    System(const System &other) = delete;

    void operator=(const System &other) = delete;

    /**
     * @brief
     *
     * @return System*
     */
    static System *get(void) {
        if (_system == nullptr)
            _system = new System();
        return _system;
    }

    /**
     * @brief
     *
     * @return bmb::rlib::EVector2<int>&
     */
    bmb::rlib::EVector2<int> &resolution(void) {
        return _resolution;
    }

    /**
     * @brief
     *
     * @return std::string&
     */
    std::string &fullscreen(void) {
        return _fullcreen;
    }

    /**
     * @brief
     *
     * @return float&
     */
    float &soundVolume(void) {
        return _soundVolume;
    }

    /**
     * @brief
     *
     * @return int&
     */
    int &playerPaused(void) {
        return _playerPaused;
    }

    /**
     * @brief
     *
     * @return float&
     */
    float &musicVolume(void) {
        return _musicVolume;
    }

    /**
     * @brief
     *
     * @return bmb::Map&
     */
    bmb::Map &map(void) {
        return _map;
    }

    /**
     * @brief
     *
     * @return int&
     */
    int &nbPlayer(void) {
        return _nbPlayer;
    }

    /**
     * @brief
     *
     * @return int&
     */
    int &maxScore(void) {
        return _maxScore;
    }

    /**
     * @brief
     *
     * @return std::string&
     */
    std::string &time(void) {
        return _time;
    }

    /**
     * @brief
     *
     * @return std::unordered_map<std::string, std::shared_ptr<Texture>>&
     */
    std::unordered_map<std::string, std::shared_ptr<Texture>> &textures(void) {
        return _textures;
    }

    /**
     * @brief
     *
     * @return std::unordered_map<std::string, Font>&
     */
    std::unordered_map<std::string, std::shared_ptr<Font>> &fonts(void) {
        return _fonts;
    }

    /**
     * @brief
     *
     * @return true
     */
    bool &restart(void) {
        return _restart;
    }

    /**
     * @brief
     *
     */
    void deleteS(void) {
        if (_system != nullptr)
            delete _system;
        _system = nullptr;
    }

 protected:
    /**
     * @brief Construct a new System object
     *
     */
    System(void)
        : _resolution(800, 600), _fullcreen("OFF"), _soundVolume(1),
        _musicVolume(1), _playerPaused(0), _nbPlayer(2), _maxScore(1), _time("1:00"), _restart(false) {}


    static System *_system;

    bmb::rlib::EVector2<int>                                    _resolution;
    std::string                                                 _fullcreen;
    float                                                       _soundVolume;
    float                                                       _musicVolume;
    int                                                         _playerPaused;
    int                                                         _nbPlayer;
    int                                                         _maxScore;
    std::string                                                 _time;
    bmb::Map                                                    _map;
    std::unordered_map<std::string, std::shared_ptr<Texture>>   _textures;
    std::unordered_map<std::string, std::shared_ptr<Font>>      _fonts;
    bool                                                        _restart;
};
    static System *sys = System::get();
}  // namespace bmb