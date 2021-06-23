/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Window
*/

#include "encapsulation/Window/EWindow.hpp"

bmb::rlib::EWindow::EWindow(bmb::rlib::EVector2<int> size, std::string title)
    : _size(size) {
    InitWindow(size._x, size._y, title.c_str());
}

bmb::rlib::EWindow::~EWindow() {
    std::cout << "[BMB] : Close Window." << std::endl;
    CloseWindow();
}

void bmb::rlib::EWindow::setFPS(int fps) {
    SetTargetFPS(fps);
}

bool bmb::rlib::EWindow::shouldClose(void) {
    return WindowShouldClose();
}

void bmb::rlib::EWindow::close(void) {
    CloseWindow();
}

void bmb::rlib::EWindow::beginDrawing(void) {
    BeginDrawing();
}

void bmb::rlib::EWindow::endDrawing(void) {
    EndDrawing();
}

void bmb::rlib::EWindow::clearBackground(const bmb::rlib::EColor &color) {
    ClearBackground(color.colorRlib());
}

void bmb::rlib::EWindow::fullscreen(void) {
    ToggleFullscreen();
}

bmb::rlib::EWindow &bmb::rlib::EWindow::setSize(bmb::rlib::EVector2<int> size) {
    _size = size;
    SetWindowSize(size._x, size._y);
    return *this;
}

bmb::rlib::EVector2<int> bmb::rlib::EWindow::getSize(void) const {
    return _size;
}