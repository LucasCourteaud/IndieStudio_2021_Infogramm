/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** AppError
*/

#pragma once
#include <exception>
#include <string>

namespace bmb::error {
class AppError : public std::exception {
 public:
    /**
     * @brief Construct a new App Error object
     *
     * @param msg Error Message
     * @param type Error Type
     */
    AppError(const std::string &msg, const std::string &type = "AppError: ")
        : _msg(msg), _type(type) {}

    /**
     * @brief Destroy the App Error object
     *
     */
    ~AppError(void) {}

    /**
     * @brief Return the error message
     *
     * @return const char*
     */
    const char *what(void) const throw() { return _msg.c_str(); }

    /**
     * @brief Return the error type
     *
     * @return std::string const&
     */
    std::string const &type(void) const { return _type; }

 protected:
    std::string _msg;
    std::string _type;
};

class CharacterFactoryError : public AppError {
 public:
    /**
     * @brief Construct a new App Error object
     *
     * @param msg Error Message
     * @param type Error Type
     */
    CharacterFactoryError(const std::string &msg, const std::string &type = "CharacterFactoryError: ")
        : AppError(msg, type) {}

    /**
     * @brief Destroy the App Error object
     *
     */
    ~CharacterFactoryError(void) {}
};

class CharacterManageError : public AppError {
 public:
    /**
     * @brief Construct a new App Error object
     *
     * @param msg Error Message
     * @param type Error Type
     */
    CharacterManageError(const std::string &msg, const std::string &type = "CharacterManageError: ")
        : AppError(msg, type) {}

    /**
     * @brief Destroy the App Error object
     *
     */
    ~CharacterManageError(void) {}
};

class BlockFactoryError : public AppError {
 public:
    /**
     * @brief Construct a new App Error object
     *
     * @param msg Error Message
     * @param type Error Type
     */
    BlockFactoryError(const std::string &msg, const std::string &type = "BlockFactoryError: ")
        : AppError(msg, type) {}

    /**
     * @brief Destroy the App Error object
     *
     */
    ~BlockFactoryError(void) {}
};

class MapParserError : public AppError {
 public:
    /**
     * @brief Construct a new App Error object
     *
     * @param msg Error Message
     * @param type Error Type
     */
    MapParserError(const std::string &msg, const std::string &type = "MapParserError: ")
        : AppError(msg, type) {}

    /**
     * @brief Destroy the App Error object
     *
     */
    ~MapParserError(void) {}
};

}  // namespace bmb::error
