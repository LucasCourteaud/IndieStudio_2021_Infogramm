/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EMusic
*/

#pragma once

#include <string>
#include "raylib.h"

namespace bmb::rlib {
class EMusic {
 public:

    /**
     * @brief Construct a new EMusic object
     *
     * @param music
     * @param title
     */
    EMusic(const std::string &music, const std::string &title, const float &volume = 1);

    /**
     * @brief Destroy the EMusic object
     *
     */
    ~EMusic();

    /**
     * @brief Load music
     *
     * @param music
     * @param title
     */
    void load(const std::string &music, const std::string &title);

    /**
     * @brief Unload music
     *
     */
    void unload(void);

    /**
     * @brief Get the Music object
     *
     * @return Music
     */
    Music &getMusic(void);

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
	EMusic &setVolume(const float &volume);

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
	 * @return EMusic&
	 */
	EMusic &operator+=(const float &volume);

	/**
	 * @brief Overload the operator-=
	 *
	 * @param volume
	 * @return EMusic&
	 */
	EMusic &operator-=(const float &volume);

 private:
    Music _music;
    std::string _title;
    bool _isPlaying;
    float _volume;

};
}  //namespace bmb::rlib
