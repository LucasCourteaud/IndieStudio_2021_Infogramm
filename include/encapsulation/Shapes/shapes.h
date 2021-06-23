/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** shapes
*/

#ifndef SHAPES_H_
#define SHAPES_H_

#include "raylib.h"
#include "encapsulation/Vector/vector.h"

#define makeBoundingBox(pos, size) (BoundingBox){(Vector3_t)\
                                    { pos._x - size._x/2,\
                                    pos._y - size._y/2,\
                                    pos._z - size._z/2 },\
                                    (Vector3_t){ pos._x + size._x/2,\
                                    pos._y + size._y/2,\
                                    pos._z + size._z/2 }}

namespace bmb::rlib::shapes {
    typedef enum {
        CUBE,
        RECTANGLE,
        CIRCLE,
        SPHERE
    } ShapesTag_t;

}  // namespace bmb::rlib::shapes

#endif /* !SHAPES_H_ */
