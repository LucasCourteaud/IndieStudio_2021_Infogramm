/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Spawn
*/

#include "Block/Spawn.hpp"
#include "System/System.hpp"

bmb::block::Spawn::Spawn(void)
 : Block(PATH_OBJ_SPAWN, *bmb::sys->textures()["spawn"]) {
    _isDestructible = false;
    _bonus = false;
    _blockTag = SPAWN;
    _model.isVisible() = true;
}

bmb::block::Spawn::~Spawn() {
}

void bmb::block::Spawn::display(void) {
    _model.display(1.f);
}

void bmb::block::Spawn::setColor(bmb::rlib::EColor color) {
    _model.setColor(color);
}