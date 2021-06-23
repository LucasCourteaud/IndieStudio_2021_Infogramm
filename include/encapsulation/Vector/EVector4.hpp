/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EVector4
*/

#pragma once

#include <iostream>
#include <string>

namespace bmb::rlib {
template<typename T>
class EVector4 {
 public:
    /**
     * @brief Construct a new Vector 4 object
     *
     * @param x Value x
     * @param y Value y
     */
    EVector4(T x, T y, T z, T w) : _x(x), _y(y), _z(z), _w(w) {}

    /**
     * @brief Construct a new Vector 4 object
     *
     * @tparam U Type of other class
     * @param other Other class to copy value
     */
    template<typename U>
    EVector4(EVector4<U> const &other) : _x(other._x), _y(other._y), _z(other._z), _w(other._w) {}

    /**
     * @brief Construct a new Vector 4 object
     *
     */
    EVector4(void) : _x(0), _y(0), _z(0), _w(0) {}

    /**
     * @brief Destroy the Vector 4 object
     *
     */
    ~EVector4(void) {}

    template<typename U>
    EVector4<T> operator=(EVector4<U> const &other) {
        _x = other._x;
        _y = other._y;
        _z = other._z;
        _w = other._w;
    }

    template<typename U>
    EVector4<T> operator+(EVector4<U> const &other) {
        return EVector4<T>(_x + other._x, _y + other._y, _z + other._z, _w + other._w);
    }

    template<typename U>
    EVector4<T> &operator+=(EVector4<U> const &other) {
        _x += other._x;
        _y += other._y;
        _z += other._z;
        _w += other._w;
        return *this;
    }

    template<typename U>
    bool operator==(EVector4<U> const &other) const {
        return _x == other._x && _y == other._y && _z == other._z && _w == other._w;
    }

    template<typename U>
    bool operator!=(EVector4<U> const & other) const {
        return !(*this == other);
    }

    T _x;
    T _y;
    T _z;
    T _w;
};

template<typename T>
std::ostream &operator<<(std::ostream &stream, EVector4<T> const &other) {
    stream << "x: " << other._x << ", y: " << other._y << ", z: " << other._z << ", w: " << other._w;
    return stream;
}
}  // namespace bmb::rlib
