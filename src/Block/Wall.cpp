/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Wall
*/

#include "Block/Wall.hpp"
#include "System/System.hpp"

bmb::block::Wall::Wall(void)
 : Block(PATH_OBJ_WALL, *bmb::sys->textures()["wall"]) {
    _isDestructible = false;
    _bonus = false;
    _blockTag = WALL;
    _model.isVisible() = true;
}

bmb::block::Wall::~Wall() {
}

void bmb::block::Wall::display(void) {
    _model.display(1.f);
}

void bmb::block::Wall::setColor(bmb::rlib::EColor color) {
    _model.setColor(color);
}