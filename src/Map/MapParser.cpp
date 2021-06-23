/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** MapParser
*/

#include "Map/MapParser.hpp"
#include "Error/AppError.hpp"

static std::unordered_map<char, bmb::block::BlockTag> symbole = {
    {'W', bmb::block::WALL},
    {'S', bmb::block::SPAWN},
    {' ', bmb::block::EMPTY},
    {'B', bmb::block::BARREL}
};

static std::unordered_map<bmb::block::BlockTag, char> unsymbole = {
    {bmb::block::WALL, 'W'},
    {bmb::block::SPAWN, 'S'},
    {bmb::block::EMPTY, ' '},
    {bmb::block::BARREL, 'B'}
};

Vector2f getOffsetHeader(const std::vector<std::string> &file) {
    float x = -1;
    float y = -1;

    if (file[0] != "[HEADER]")
        throw bmb::error::MapParserError("Corrupted header in map file.");
    for (int i = 0; i < file.size() && file[i].find("[MAP]") == std::string::npos; i++) {
        if (file[i].find("OFFSET_X=") != std::string::npos)
            x = static_cast<float>(atof(file[i].substr(file[i].find("=")+1).c_str()));
        if (file[i].find("OFFSET_Y=") != std::string::npos)
            y = static_cast<float>(atof(file[i].substr(file[i].find("=")+1).c_str()));
    }
    return Vector2f(x, y);
}

bmb::rlib::EVector2<size_t> getMaxSize(const std::vector<std::string> &file, size_t index) {
    size_t max_x = 0;
    size_t max_y = 0;

    for (; index < file.size(); index++, max_y++)
        max_x = std::max(file[index].size(), max_x);
    return bmb::rlib::EVector2<size_t>(max_x, max_y);
}

void buildMap(const std::vector<std::string> &file, bmb::Map &map, size_t index)
{
    bmb::rlib::EVector2<size_t> tmpsize = getMaxSize(file, index);
    bmb::rlib::EVector2<int> size(static_cast<int>(tmpsize._x), static_cast<int>(tmpsize._y));
    float x = 0;
    float y = 0 - (size._y * map.offset()._y / 2);

    map.max() = size;
    map.origin() = Vector3f(0 - (size._x * map.offset()._x / 2), 0.f, y);
    for (; index < file.size(); index++, y += map.offset()._y) {
        x = 0 - (size._x * map.offset()._x / 2);
        for (size_t j = 0; file[index][j]; j++, x += map.offset()._x) {
            auto newBlock = bmb::block::BlockFactory::createBlock(symbole[file[index][j]]);
            newBlock->setPosition(Vector3f(x, 2.5f, y));
            map.add(newBlock);
        }
        map.newLine();
    }
}

void bmb::MapParser::fileToMap(const std::string &pathMap, Map &map) {
    std::vector<std::string> file = tools::fileToVector(pathMap);
    Vector2f offset = 0;
    size_t index = 0;

    if (file.empty())
        throw bmb::error::MapParserError("File map given doesn't exist or technicall problem.");
    offset = getOffsetHeader(file);
    if (offset._x == -1 || offset._y == -1)
        throw bmb::error::MapParserError("Corrupted file.");
    map.clear();
    map.setName(pathMap.substr(pathMap.find("/")+1, pathMap.length() - 8));
    map.offset() = offset;
    for (; index < file.size() && file[index].find("[MAP]") == std::string::npos; index++);
    buildMap(file, map, index + 1);
}

void bmb::MapParser::mapToFile(Map &map) {
    std::string name = "map/" + map.getName() + ".bmb";
    std::ofstream ofs(name);

    if (!ofs.is_open())
        throw bmb::error::MapParserError("Proble to convert the map in file.");
    ofs << "[HEADER]\n";
    ofs << "OFFSET_X=" << map.offset()._x << std::endl;
    ofs << "OFFSET_Y=" << map.offset()._y << std::endl;
    ofs << std::endl << "[MAP]\n";
    for (size_t  i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++)
            ofs << unsymbole[map[i][j]->type()];
        ofs << std::endl;
    }
    ofs.close();
}

std::string bmb::MapParser::getNameMap(const std::string &pathMap) {
    std::string name(pathMap.substr(pathMap.find("/")+1, pathMap.length() - 8));

    return name;
}