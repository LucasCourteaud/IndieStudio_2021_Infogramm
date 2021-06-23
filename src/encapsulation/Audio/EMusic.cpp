/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EMusic
*/

#include <iostream>
#include "encapsulation/Audio/EMusic.hpp"

bmb::rlib::EMusic::EMusic(const std::string &music, const std::string &title, const float &volume)
    : _title(title) {
    _music = LoadMusicStream(music.c_str());
    setVolume(volume);
}

bmb::rlib::EMusic::~EMusic() {
    unload();
}

void bmb::rlib::EMusic::load(const std::string &music, const std::string &title) {
    UnloadMusicStream(_music);
    _title = title;
    LoadMusicStream(music.c_str());
}

void bmb::rlib::EMusic::unload(void) {
    std::cout << "[BMB] : Unload '" << _title << "'." << std::endl;
    UnloadMusicStream(_music);
}

Music &bmb::rlib::EMusic::getMusic(void){
    return _music;
}

const std::string &bmb::rlib::EMusic::getTitle(void) const {
    return _title;
}

void bmb::rlib::EMusic::setPlaying(bool status) {
    _isPlaying = status;
}

bool bmb::rlib::EMusic::getPlaying(void) {
    return _isPlaying;
}

bmb::rlib::EMusic &bmb::rlib::EMusic::setVolume(const float &volume) {
    _volume = volume;
    if (_volume < 0)
        _volume = 0;
    if (_volume > 1)
        _volume = 1;
    SetMusicVolume(_music, _volume);

    return *this;
}

float bmb::rlib::EMusic::getVolume(void) const {
    return _volume;
}

bmb::rlib::EMusic &bmb::rlib::EMusic::operator+=(const float &volume) {
    _volume += volume;
    setVolume(_volume);

    return *this;
}

bmb::rlib::EMusic &bmb::rlib::EMusic::operator-=(const float &volume) {
    _volume -= volume;
    setVolume(_volume);

    return *this;
}