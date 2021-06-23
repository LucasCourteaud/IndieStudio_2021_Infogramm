/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** AI
*/

#include "Character/AI.hpp"

bmb::character::AI::AI(indexEntity_u indexAI)
    : Character(bmb::entity::CHARACTER, "AI", indexAI) {
    _spawn = Vector3f();
}

bmb::character::AI::~AI(void) {
    _listBomb.clear();
}

bmb::event::InputUser bmb::character::AI::getInput(void) {
    bmb::event::InputUser input;
    return input;
}

bool bmb::character::AI::move(const bmb::event::InputUser &input) {
    (void)input;
    return false;
}

void bmb::character::AI::action(const bmb::event::InputUser &input, const bmb::clock::Clock &clock) {
    (void)input;
    (void)clock;
}

bmb::character::CharacterTag_t bmb::character::AI::type(void) const {
    return bmb::character::T_AI;
}