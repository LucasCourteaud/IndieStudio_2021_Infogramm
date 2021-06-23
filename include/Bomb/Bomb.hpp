/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Bomb
*/

#include <list>
#include "Block/Block.hpp"
#include "Items/Items.hpp"
#include "encapsulation/Model/EModel.hpp"
#include "Clock/Clock.hpp"

#define DEFAULT_PATH_BOMB_MODEL     "assets/model/Bomb3D/Bomb.iqm"

#define TIME_TO_EXPLOSE             2

#define DEFAULT_RANGE_EXPLOSION     3

#pragma once

namespace bmb::items {
 typedef enum {
    WAITING,
    EXPLOSED,
    DESACTIVED
} BombState_t;

class Bomb : public Items {
 public:
    /**
     * @brief Construct a new Bomb object
     *
     */
    Bomb(void);

    /**
     * @brief Destroy the Bomb object
     *
     */
    ~Bomb(void);

    /**
     * @brief Get the Model object
     *
     * @return bmb::rlib::EModel&
     */
    bmb::rlib::EModel &getModel(void);

    /**
     * @brief Active the bomb
     *
     * @return Bomb&
     */
    Bomb &activate(const bmb::clock::Clock &clock);

    /**
     * @brief Desactive the bomb
     *
     * @return Bomd&
     */
    Bomb &desactivate(void);

    /**
     * @brief Draw the model of the bomb on the screen
     *
     * @return Bomb&
     */
    Bomb &draw(void);

    /**
     * @brie Get the state of items bombs
     *
     * @return BombState_t
     */
    BombState_t state(void) const;

    /**
     * @brief Update the bomb
     *
     * @return Bomb&
     */
    std::list<std::shared_ptr<bmb::block::Block>> update(const bmb::clock::Clock &clock);

    /**
     * @brief Set the Position Map object
     *
     * @param pos
     * @return Bomb&
     */
    Bomb &setPositionMap(const Vector2i &pos);

    /**
     * @brief Get the Position Map object
     *
     * @return Vector2i
     */
    Vector2i getPositionMap(void) const;

    /**
     * @brief get the range of bomb
     *
     * @return int&
     */
    int &range(void);

 private:
    bmb::rlib::EModel                               _model;
    BombState_t                                     _state;
    int                                             _stateTime;
    Vector2i                                        _posInMap;
    int                                             _explosionRange;
    int                                             _startTime;
    std::list<std::shared_ptr<bmb::block::Block>>   _destroyedBlocks;
    float                                            _size;
};
} // namespace bmb::items
