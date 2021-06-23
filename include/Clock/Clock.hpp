/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Clock
*/

#include <chrono>

#pragma once

namespace bmb::clock {
class Clock {
 public:
    /**
     * @brief Construct a new Clock object
     *
     */
    Clock(void);

    /**
     * @brief Destroy the Clock object
     *
     */
    ~Clock(void);

    /**
     * @brief Start the Clock
     *
     */
    void start(void);

    /**
     * @brief Get the Time In Second object
     *
     * @return int
     */
    int getTimeInSecond(void) const;

    /**
     * @brief Get the Time In Millisecond object
     *
     * @return int
     */
    int getTimeInMillisecond(void) const;

 protected:
    std::chrono::time_point<std::chrono::system_clock> _start;
};
}  // namespace bmb::clock
