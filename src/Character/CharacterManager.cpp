/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** CharacterManager
*/

#include <string>
#include "Error/AppError.hpp"
#include "Character/CharacterManager.hpp"
#include "encapsulation/Camera/ECamera.hpp"

bmb::character::CharacterManager::CharacterManager(const size_t &player, const size_t &ai)
    : _indexEntity(1), _indexController(0) {
    add(T_PLAYER, player);
    add(T_AI, ai);
}

bmb::character::CharacterManager::~CharacterManager(void) {}

bmb::character::CharacterManager &bmb::character::CharacterManager::add(const CharacterTag_t &tag, const size_t &n) {
    if (_list.size() > 4)
        throw bmb::error::CharacterManageError("Maximum number of character created.");
    _factory << tag;
    for (size_t i = 0; i < n; i++) {
        auto character = _factory.launch(_indexEntity, _indexController);
        character->getModel().setColor(_colorList[_indexEntity-1]);
        character->getCursor().setColor(_colorList[_indexEntity-1]);
        _list.push_back(character);
        if (tag == T_PLAYER)
            _indexController++;
        _indexEntity++;
    }
    return *this;
}

std::list<bmb::character::uniqueCharacter> bmb::character::CharacterManager::get(void) {
    return _list;
}

bmb::character::uniqueCharacter &bmb::character::CharacterManager::operator[](const size_t &pos) {
    std::list<uniqueCharacter>::iterator it;

    if (pos < 0)
        throw bmb::error::CharacterManageError("Index to get a character must be positive integer.");
    it = _list.begin();
    for (int i = 0; i < _list.size(); i++, it++)
        if (i == pos)
            return *it;
    throw bmb::error::CharacterManageError("Index to get a character is too long.");
}

size_t bmb::character::CharacterManager::size(void) const {
    return _list.size();
}

bmb::character::CharacterManager &bmb::character::CharacterManager::reset(void) {
        _list.clear();
        _indexController = 0;
        _indexEntity = 1;
        add(T_PLAYER, 1);
        return *this;
    }