/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Map
*/

#include "Map/Map.hpp"
#include "Map/MapParser.hpp"

bmb::Map::Map(void)
    : _index(0) {}

bmb::Map::~Map(void) {}

bmb::Map &bmb::Map::add(bmb::block::uniqueBlock newBlock) {
    _listBlocks[_index].push_back(newBlock);

    return *this;
}

bmb::Map &bmb::Map::draw(void) {
    for (auto it : _listBlocks)
        for (auto it2 : it.second)
            it2->display();
    return *this;
}

bmb::Map &bmb::Map::setName(const std::string &name) {
    _name = name;

    return *this;
}

std::string bmb::Map::getName(void) const {
    return _name;
}

Vector2f &bmb::Map::offset(void) {
    return _offset;
}

bmb::Map &bmb::Map::remove(size_t const &l, size_t const &c) {
    auto emptyblock = bmb::block::BlockFactory::createBlock(bmb::block::EMPTY);

    _listBlocks[l].erase(_listBlocks[l].begin() + c);
    _listBlocks[l].emplace(_listBlocks[l].begin() + c, emptyblock);

    return *this;
}

bmb::Map &bmb::Map::remove(bmb::block::uniqueBlock const &block) {
    for (size_t i = 0; i < _listBlocks.size(); i++) {
        for (size_t j = 0; j < _listBlocks[i].size(); j++) {
            if (_listBlocks[i][j] == block) {
                std::cout << "FOUND" << std::endl;
                auto emptyblock = bmb::block::BlockFactory::createBlock(bmb::block::EMPTY);
                emptyblock->setPosition(_listBlocks[i][j]->getPosition());
                _listBlocks[i].erase(_listBlocks[i].begin() + j);
                _listBlocks[i].emplace(_listBlocks[i].begin() + j, emptyblock);
                return *this;
            }
        }
    }
    std::cout << "NOT FOUND\n";
    return *this;
}

bmb::Map &bmb::Map::newLine(void) {
    _index++;

    return *this;
}

bmb::Map &bmb::Map::clear(void) {
    _index = 0;
    _listBlocks.clear();

    return *this;
}

std::vector<bmb::block::uniqueBlock> &bmb::Map::operator[](const size_t &pos) {
    return _listBlocks[pos];
}

size_t bmb::Map::size(void) const {
    return _listBlocks.size();
}

Vector3f &bmb::Map::origin(void) {
    return _orig;
}

Vector2i &bmb::Map::max(void) {
    return _max;
}