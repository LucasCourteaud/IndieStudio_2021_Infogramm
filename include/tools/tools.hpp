/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** tools
*/

#pragma once

#include "raylib.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace tools {
    /**
     * @brief Relplace a string in a string by a string
     *
     * @param str Main string
     * @param search The string to replace
     * @param replace The new string
     * @return size_t
     */
    size_t replaceString(std::string &str, const std::string &search,
                            const std::string &replace);

    /**
     * @brief Clean a string
     *
     * @param str Main string
     * @return std::string&
     */
    std::string &trimString(std::string &str);

    /**
     * @brief Split the string in vector of string
     *
     * @param str The main string
     * @param delimiter Where the function split
     * @param emptyArea
     * @return std::vector<std::string>
     */
    std::vector<std::string> split(const std::string &str,
            const std::string &delimiter = " ", bool const &emptyArea = false);

    /**
     * @brief Search if string can be transfomr to an int
     *
     * @param s The string to transform
     * @return true ot false
     */
    bool isNumber(const std::string &s);

    /**
     * @brief Get all files name in a directory
     *
     * @param pathFolder directory to search file name
     * @return std::vector<std::string>
     */
    std::vector<std::string> explore(const std::string &pathFolder);

    /**
     * @brief
     *
     * @param pathname
     * @return std::vector<std::string>
     */
    std::vector<std::string> fileToVector(const std::string &pathname);

    /**
     * @brief Percentage of number given with percent
     *
     * @param number
     * @param percent
     * @return float
     */
    float percentage(const float &number, const float &percent);
}  // namespace tools