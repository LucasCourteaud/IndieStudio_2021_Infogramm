/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** EMatrix
*/

#ifndef EMATRIX_H_
#define EMATRIX_H_

#include "raymath.h"
#include "encapsulation/Vector/vector.h"

namespace bmb::rmath::matrix {
    /**
     * @brief rotate matrix Vector3
     *
     * @param ang
     * @return Matrix
     */
    Matrix rotateXYZ(const Vector3f &ang) {
        Vector3 tmpAng = {ang._x, ang._y, ang._z};

        return MatrixRotateXYZ(tmpAng);
    }
}  // namespace bmb::rmath::matrix

#endif /* !EMATRIX_H_ */
