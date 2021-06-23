/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** EVector2
*/

#pragma once

#include <iostream>

namespace bmb::rlib {
template<typename T>
class EVector2 {
 public:

    /**
     * @brief Construct a new Vector 2 object
     *
     * @param x Value x
     * @param y Value y
     */
    EVector2(T x = 0, T y = 0) : _x(x), _y(y) {}

    /**
     * @brief Construct a new Vector 2 object
     *
     * @tparam U Type of other class
     * @param other Other class to copy value
     */
    template<typename U>
    EVector2(EVector2<U> const &other) : _x(other._x), _y(other._y) {}


    /**
     * @brief Destroy the Vector 2 object
     *
     */
    ~EVector2(void) {}

    template<typename U>
    EVector2<T> operator=(EVector2<U> const &other) {
        _x = other._x;
        _y = other._y;
    }

    template<typename U>
    EVector2<T> operator+(EVector2<U> const &other) {
        return EVector2<T>(_x + other._x, _y + other._y);
    }

    template<typename U>
    EVector2<T> &operator+=(EVector2<U> const &other) {
        _x += other._x;
        _y += other._y;
        return *this;
    }

    template<typename U>
    bool operator==(EVector2<U> const &other) const {
        return _x == other._x && _y == other._y;
    }

    template<typename U>
    bool operator!=(EVector2<U> const &other) const {
        return !(*this == other);
    }

    T _x;
    T _y;
};

template<typename T>
std::ostream &operator<<(std::ostream &stream, EVector2<T> const &other) {
    stream << "x: " << other._x << ", y: " << other._y;
    return stream;
}
}  // namespace bmb::rlib
