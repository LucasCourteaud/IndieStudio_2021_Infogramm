/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** EVector3
*/

#pragma once

#include <iostream>
#include <string>

namespace bmb::rlib {
template<typename T>
class EVector3 {
 public:
    /**
     * @brief Construct a new Vector 3 object
     *
     * @param x Value x
     * @param y Value y
     * @param z Value z
     */
    EVector3(T x, T y, T z) : _x(x), _y(y), _z(z) {}

    /**
     * @brief Construct a new Vector 3 object
     *
     * @tparam U Type of other class
     * @param other Other class to copy value
     */
    template<typename U>
    EVector3(EVector3<U> const &other) : _x(other._x), _y(other._y), _z(other._z) {}

    /**
     * @brief Construct a new Vector 3 object
     *
     */
    EVector3(void) : _x(0), _y(0), _z(0) {}

    /**
     * @brief Destroy the Vector 3 object
     *
     */
    ~EVector3(void) {}

    template<typename U>
    EVector3<T> operator=(EVector3<U> const &other) {
        _x = other._x;
        _y = other._y;
        _z = other._z;
    }

    template<typename U>
    EVector3<T> operator+(EVector3<U> const &other) {
        return EVector3<T>(_x + other._x, _y + other._y, _z + other._z);
    }

    template<typename U>
    EVector3<T> &operator+=(EVector3<U> const &other) {
        _x += other._x;
        _y += other._y;
        _z += other._z;
        return *this;
    }

    T _x;
    T _y;
    T _z;
};

template<typename T>
std::ostream &operator<<(std::ostream &stream, EVector3<T> const &other) {
    stream << "x: " << other._x << ", y: " << other._y << ", z: " << other._z;
    return stream;
}
}  // namespace bmb::rlib
