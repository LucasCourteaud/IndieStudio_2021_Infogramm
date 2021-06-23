/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** CharacterFactory
*/

#include "Error/AppError.hpp"
#include "Character/CharacterFactory.hpp"
#include "Character/AI.hpp"

bmb::character::CharacterFactory::CharacterFactory(CharacterTag_t const &tag)
    : _tag(tag) {
}

bmb::character::CharacterFactory::CharacterFactory::~CharacterFactory(void) {}

bmb::character::CharacterFactory &bmb::character::CharacterFactory::operator<<(CharacterTag_t const &tag) {
    _tag = tag;
    return *this;
}

bmb::character::uniqueCharacter bmb::character::CharacterFactory::launch(indexEntity_u indexEntity, ...) {
    va_list args;
    std::unordered_map<CharacterTag_t, creatorCharacter> Fcreator;

    Fcreator[T_PLAYER] = createPlayer;
    Fcreator[T_AI]     = createAI;
    va_start(args, indexEntity);
    for (auto it : Fcreator) {
        if (it.first == _tag) {
            uniqueCharacter tmp = it.second(indexEntity, args);
            va_end(args);
            return tmp;
        }
    }
    va_end(args);
    throw bmb::error::CharacterFactoryError("CharaterTag specified doesn't exist, can't build this character.");
}

bmb::character::uniqueCharacter bmb::character::CharacterFactory::createPlayer(indexEntity_u indexEntity, va_list args) {
    indexController_u indexController = va_arg(args, int);
    return uniqueCharacter(new bmb::character::Player(indexController, indexEntity));
}

bmb::character::uniqueCharacter bmb::character::CharacterFactory::createAI(indexEntity_u indexEntity, va_list args) {
    return uniqueCharacter(new bmb::character::AI(indexEntity));
}