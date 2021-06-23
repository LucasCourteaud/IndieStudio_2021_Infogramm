/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** MapParser
*/

#include "Map/Map.hpp"
#include "tools/tools.hpp"

#pragma once

namespace bmb {
class MapParser {
 public:

    static void fileToMap(const std::string &pathMap, Map &map);

    static void mapToFile(Map &map);

    static std::string getNameMap(const std::string &pathMap);
};
}  // bmb
