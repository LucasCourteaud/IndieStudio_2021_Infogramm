/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Clock
*/

#include "Clock/Clock.hpp"

bmb::clock::Clock::Clock(void) {}

bmb::clock::Clock::~Clock(void) {}

void bmb::clock::Clock::start(void) {
    _start = std::chrono::system_clock::now();
}

int bmb::clock::Clock::getTimeInSecond(void) const {
    std::chrono::time_point<std::chrono::system_clock> tmp = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(tmp - _start).count();

    return elapsed_seconds;
}

int bmb::clock::Clock::getTimeInMillisecond(void) const {
    std::chrono::time_point<std::chrono::system_clock> tmp = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(tmp - _start).count();

    return elapsed_seconds;
}