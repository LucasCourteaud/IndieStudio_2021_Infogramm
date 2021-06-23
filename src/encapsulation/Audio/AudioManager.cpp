/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** AudioManager
*/

#include <iostream>
#include "encapsulation/Audio/AudioManager.hpp"

bmb::rlib::AudioManager::AudioManager() {
    InitAudioDevice();
}

bmb::rlib::AudioManager::~AudioManager() {
    StopSoundMulti();
    CloseAudioDevice();
    std::cout << "[BMB] : Destroy the AudioManager." << std::endl;
}

bmb::rlib::AudioManager &bmb::rlib::AudioManager::addMusic(const std::string &music, const std::string &title) {
    _listMusic.push_back(uniqueMusic(new EMusic(music, title)));

    return *this;
}

void bmb::rlib::AudioManager::updateMusic(const std::string &title) {
    for (auto it : _listMusic)
        if (it->getTitle() == title)
            UpdateMusicStream(it->getMusic());
}

void bmb::rlib::AudioManager::playMusic(const std::string &title) {
    for (auto it : _listMusic) {
        if (it->getTitle() == title) {
            PlayMusicStream(it->getMusic());
            it->setPlaying(true);
        }
    }
}

void bmb::rlib::AudioManager::stopMusic(const std::string &title) {
    for (auto it : _listMusic) {
        if (it->getTitle() == title) {
            StopMusicStream(it->getMusic());
            it->setPlaying(false);
        }
    }
}

bmb::rlib::AudioManager &bmb::rlib::AudioManager::addSound(const std::string &sound, const std::string &title) {
    _listSound.push_back(uniqueSound(new ESound(sound, title)));
    return *this;
}

void bmb::rlib::AudioManager::playSound(const std::string &title, bool multiSound) {
    for (auto it : _listSound) {
        if (it->getTitle() == title) {
            (multiSound) ? PlaySoundMulti(it->getSound()) : PlaySound(it->getSound());
            it->setPlaying(true);
        }
    }
}

void bmb::rlib::AudioManager::stopSound(const std::string &title, bool multiSound) {
    for (auto it : _listSound) {
        if (it->getTitle() == title) {
            (multiSound) ? StopSoundMulti() : StopSound(it->getSound());
            it->setPlaying(false);
        }
    }
}

bmb::rlib::AudioManager &bmb::rlib::AudioManager::setSoundVolume(const float &volume) {
    for (auto it : _listSound)
        it->setVolume(volume);
    return *this;
}

float bmb::rlib::AudioManager::getSoundVolume(void) const {
    float volume = 1;

    for (auto it : _listSound)
        volume = it->getVolume();
    return volume;
}

bmb::rlib::AudioManager &bmb::rlib::AudioManager::addSoundVolume(const float &volume) {
    for (auto it : _listSound)
        (*it) += volume;
    return *this;
}

bmb::rlib::AudioManager &bmb::rlib::AudioManager::setMusicVolume(const float &volume) {
    for (auto it : _listMusic)
        it->setVolume(volume);
    return *this;
}

float bmb::rlib::AudioManager::getMusicVolume(void) const {
    float volume = 1;

    for (auto it : _listMusic)
        volume = it->getVolume();
    return volume;
}

bmb::rlib::AudioManager &bmb::rlib::AudioManager::addMusicVolume(const float &volume) {
    for (auto it : _listMusic)
        (*it) += volume;
    return *this;
}

bool bmb::rlib::AudioManager::currentMusic(const std::string &title) {
    for (auto it : _listMusic)
        if (it->getTitle() == title)
            return it->getPlaying();
    return false;
}