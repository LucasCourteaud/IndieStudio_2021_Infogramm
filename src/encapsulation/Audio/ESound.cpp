/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** ESound
*/

#include <iostream>
#include "encapsulation/Audio/ESound.hpp"

bmb::rlib::ESound::ESound(const std::string &sound, const std::string &title, const float &volume)
    : _title(title) {
    _sound = LoadSound(sound.c_str());
    setVolume(volume);
}

bmb::rlib::ESound::~ESound() {
    unload();
}

void bmb::rlib::ESound::load(const std::string &sound, const std::string &title) {
    UnloadSound(_sound);
    _title = title;
    LoadSound(sound.c_str());
}


void bmb::rlib::ESound::unload(void) {
    std::cout << "[BMB] : Unload '" << _title << "'." << std::endl;
    UnloadSound(_sound);
}

Sound &bmb::rlib::ESound::getSound(void) {
    return _sound;
}

const std::string &bmb::rlib::ESound::getTitle(void) const {
    return _title;
}

void bmb::rlib::ESound::setPlaying(bool status) {
    _isPlaying = status;
}

bool bmb::rlib::ESound::getPlaying(void) {
    return _isPlaying;
}

bmb::rlib::ESound &bmb::rlib::ESound::setVolume(const float &volume) {
    _volume = volume;
    if (_volume < 0)
        _volume = 0;
    if (_volume > 1)
        _volume = 1;
    SetSoundVolume(_sound, _volume);

    return *this;
}

float bmb::rlib::ESound::getVolume(void) const {
    return _volume;
}

bmb::rlib::ESound &bmb::rlib::ESound::operator+=(const float &volume) {
    _volume += volume;
    setVolume(_volume);

    return *this;
}

bmb::rlib::ESound &bmb::rlib::ESound::operator-=(const float &volume) {
    _volume -= volume;
    setVolume(_volume);

    return *this;
}