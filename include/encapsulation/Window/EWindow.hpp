/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Window
*/

#pragma once

#include <string>
#include "raylib.h"
#include "encapsulation/Vector/vector.h"
#include "encapsulation/Color/EColor.hpp"

#define R_1920x1080     bmb::rlib::EVector2<int>(1920, 1080)

#define R_1600x1200     bmb::rlib::EVector2<int>(1600, 1200)

#define R_1366x728      bmb::rlib::EVector2<int>(1366, 728)

#define R_800x600       bmb::rlib::EVector2<int>(800, 600)

namespace bmb::rlib {
class EWindow {
 public:
    /**
     * @brief Construct a new Window object
     *
     */
    EWindow(EVector2<int> size, std::string title);

    /**
     * @brief Destroy the Window object
     *
     */
    ~EWindow();

    /**
     * @brief Set the FPS of Window
     *
     * @param fps Frame Per Second
     */
    void setFPS(int fps);


    /**
     * @brief Check if the Window should close
     *
     */
    bool shouldClose(void);

    /**
     * @brief Close window
     *
     */
    void close(void);

    /**
     * @brief Begin drawingMode on the window
     *
     */
    void beginDrawing(void);

    /**
     * @brief End drawingMode on the window
     *
     */
    void endDrawing(void);

    /**
     * @brief Clear background of window
     *
     * @param color
     */
    void clearBackground(const bmb::rlib::EColor &color);

    /**
     * @brief Toggle windowed to fullscreen
     *
     */
    void fullscreen(void);

    /**
     * @brief Set the Window Size object
     *
     * @param size
     */
    EWindow &setSize(EVector2<int> size);

    /**
     * @brief Get the Size object
     *
     * @return EVector2<int>
     */
    EVector2<int> getSize(void) const;

 private:
    EVector2<int> _size;
};
}
