/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** ESound
*/

#pragma once

#include <string>
#include "raylib.h"

namespace bmb::rlib {
class ESound {
 public:

    /**
     * @brief Construct a new ESound object
     *
     * @param sound
     * @param title
     */
    ESound(const std::string &sound, const std::string &title, const float &volume = 1);

    /**
     * @brief Destroy the ESound object
     *
     */
    ~ESound();

    /**
     * @brief Load sound
     *
     * @param sound
     * @param title
     */
    void load(const std::string &sound, const std::string &title);

    /**
     * @brief Unload sound
     *
     */
    void unload(void);

    /**
     * @brief Get the sound object
     *
     * @return sound
     */
    Sound &getSound(void);

    /**
     * @brief Get the Title object
     *
     * @return std::string
     */
    const std::string &getTitle(void) const;

    /**
     * @brief Set the Playing object
     *
     * @param status
     */
    void setPlaying(bool status);

    /**
     * @brief Get the Playing object
     *
     * @return true
     * @return false
     */
    bool getPlaying(void);

	/**
	 * @brief Set the Volume object
	 *
	 * @param volume
	 * @return ESound&
	 */
	ESound &setVolume(const float &volume);

	/**
	 * @brief Get the Volume object
	 *
	 * @return float
	 */
	float getVolume(void) const;

	/**
	 * @brief Overload the operator+=
	 *
	 * @param volume
	 * @return ESound&
	 */
	ESound &operator+=(const float &volume);

	/**
	 * @brief Overload the operator-=
	 *
	 * @param volume
	 * @return ESound&
	 */
	ESound &operator-=(const float &volume);

 private:
    Sound _sound;
    std::string _title;
    bool _isPlaying;
    float _volume;
};
}  //namespace bmb::rlib
