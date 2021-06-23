/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Barrel
*/

#include "PowerUp/Range.hpp"
#include "Block/Barrel.hpp"
#include "System/System.hpp"
#include "PowerUp/NBomb.hpp"

bmb::block::Barrel::Barrel(void)
    : Block(PATH_OBJ_BARREL, *bmb::sys->textures()["barrel"]) {
    _isDestructible = true;
    _blockTag = BARREL;
    _model.isVisible() = true;
    _bonus = false;
    int r = rand() % CHANCE_BONUS;

    if (r)
        return;
    _bonus = true;
    r = rand() % 3;
    if (r == 0)
        _powerUp = std::shared_ptr<bmb::items::Speed>(new bmb::items::Speed());
    if (r == 1)
        _powerUp = std::shared_ptr<bmb::items::Range>(new bmb::items::Range());
    if (r == 2)
        _powerUp = std::shared_ptr<bmb::items::NBomb>(new bmb::items::NBomb());
}

bmb::block::Barrel::~Barrel(void) {
}

void bmb::block::Barrel::display(void) {
    if (_bonus && _blockTag == EMPTY) {
        _powerUp->display();
        return;
    }
    _model.display(1.f);
}

bool bmb::block::Barrel::destroy(void) {
    _blockTag = EMPTY;
    _model.isVisible() = false;
    if (_bonus)
        _powerUp->getModel().setCenter(_model.getPosition());
    return true;
}