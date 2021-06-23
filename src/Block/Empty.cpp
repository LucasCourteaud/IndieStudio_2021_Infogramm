/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Empty
*/

#include "Block/Empty.hpp"
#include "System/System.hpp"

bmb::block::Empty::Empty(void)
    : Block(PATH_OBJ_EMPTY, *bmb::sys->textures()["barrel"]) {
    _isDestructible = false;
    _bonus = false;
    _blockTag = EMPTY;
    _model.isVisible() = false;
}

bmb::block::Empty::~Empty(void) {}

void bmb::block::Empty::display(void) {
    _model.display(1.f);
}

bool bmb::block::Empty::destroy(void) {
    _model.isVisible() = false;
    _model.setColor(bmb::rlib::color::White);
    return true;
}
