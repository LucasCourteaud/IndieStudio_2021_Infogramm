/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** main
*/

#include <iostream>
#include "Error/AppError.hpp"
#include "App/App.hpp"

int main(void) {
    bmb::App app;

    try {
        app.run();
    } catch (bmb::error::AppError const &error) {
        std::cerr << error.type() << error.what() << std::endl;
    }
    return 0;
}