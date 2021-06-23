/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** tools
*/

#include <fstream>
#include "tools/tools.hpp"

size_t tools::replaceString(std::string &str, const std::string &search,
const std::string &replace) {
    size_t count = 0;

    for (size_t pos = 0; (pos = str.find(search, pos)) != std::string::npos;) {
        str.replace(pos, search.length(), replace);
        count++;
        pos+=replace.length();
    }
    return count;
}

std::string &tools::trimString(std::string &str) {
    replaceString(str, "\t", " ");
    while (replaceString(str, "  ", " ")) {}
    if (!str.empty()) {
        if (str.back() == ' ')
            str.pop_back();
        if (!str.empty() && str.front() == ' ')
            str.erase(str.begin());
    }
    return str;
}

static inline bool endsWith(const std::string& s, const std::string& suffix) {
    return s.size() >= suffix.size() &&
            s.substr(s.size() - suffix.size()) == suffix;
}

std::vector<std::string> tools::split(const std::string &str,
const std::string &delimiter, bool const &emptyArea) {
    std::vector<std::string> list;
    size_t end = 0;
    size_t position = 0;
    std::string token;
    size_t start = 0;

    for (; start < str.length(); start = end + delimiter.length()) {
        position = str.find(delimiter, start);
        end = position != std::string::npos ? position : str.length();
        token = str.substr(start, end - start);
        if (emptyArea || !token.empty())
            list.push_back(token);
    }
    if (emptyArea && (str.empty() || endsWith(str, delimiter)))
        list.push_back("");
    return list;
}

bool tools::isNumber(const std::string &s) {
    std::string::const_iterator it = s.begin();

    if (*it == '-')
        it++;
    for (; it != s.end() && std::isdigit(*it); it++) {}
    return !s.empty() && it == s.end();
}

std::vector<std::string> tools::explore(const std::string &pathFile) {
    std::vector<std::string> files;
    std::ifstream ifs{pathFile};
    std::string line;

    if (!ifs.is_open())
        return files;
    while (std::getline(ifs, line))
        files.push_back(line);
    return files;
}

std::vector<std::string> tools::fileToVector(const std::string &pathname) {
    std::vector<std::string> file;
    std::string line;
    std::ifstream ifs(pathname);

    if (!ifs.is_open())
        return file;
    while (std::getline(ifs, line))
        file.push_back(line);
    ifs.close();
    return file;
}

float tools::percentage(const float &number, const float &percent) {
    return number * percent / 100.f;
}