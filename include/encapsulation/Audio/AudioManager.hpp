/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** AudioManager
*/

#pragma once

#include "raylib.h"
#include <string>
#include <memory>
#include <list>
#include "EMusic.hpp"
#include "ESound.hpp"

namespace bmb::rlib {
   using uniqueSound = std::shared_ptr<ESound>;
   using uniqueMusic = std::shared_ptr<EMusic>;

class AudioManager {
 public:

    /**
     * @brief Construct a new Audio Manager object
     *
     */
    AudioManager();

    /**
     * @brief Destroy the Audio Manager object
     *
     */
    ~AudioManager();

    /**
     * @brief add music in listMusic
     *
     * @param music
     */
    AudioManager &addMusic(const std::string &sound, const std::string &title);

    /**
     * @brief add sound in listSound
     *
     * @param music
     */
    AudioManager &addSound(const std::string &sound, const std::string &title);

    /**
     * @brief Update music
     *
     * @param title
     */
    void updateMusic(const std::string &title);

    /**
     * @brief Play music
     *
     * @param music
     */
    void playMusic(const std::string &title);

    /**
     * @brief Stop music
     *
     * @param music
     */
    void stopMusic(const std::string &title);

    /**
     * @brief Play sound
     *
     * @param title
     */
    void playSound(const std::string &title, bool multiSound);

    /**
     * @brief Stop sound
     *
     * @param title
     */
    void stopSound(const std::string &title, bool multiSound);

    /**
     * @brief Set the Sound Volume object
     *
     * @param volume
     * @return AudioManager&
     */
    AudioManager &setSoundVolume(const float &volume);

    /**
     * @brief Get the Sound Volume object
     *
     * @return float
     */
    float getSoundVolume(void) const;

    /**
     * @brief Turn up the Sound Volume
     *
     * @param volume
     * @return AudioManager&
     */
    AudioManager &addSoundVolume(const float &volume);

    /**
     * @brief Set the Sound Volume object
     *
     * @param volume
     * @return AudioManager&
     */
    AudioManager &setMusicVolume(const float &volume);

    /**
     * @brief Get the Music Volume object
     *
     * @return float
     */
    float getMusicVolume(void) const;

    /**
     * @brief Turn up the Music Volume
     *
     * @param volume
     * @return AudioManager&
     */
    AudioManager &addMusicVolume(const float &volume);

    /**
     * @brief get if music playing
     *
     * @return true
     * @return false
     */
    bool currentMusic(const std::string &title);

 private:
    std::list<uniqueMusic> _listMusic;
    std::list<uniqueSound> _listSound;
};
}  //namespace bmb::rlib
