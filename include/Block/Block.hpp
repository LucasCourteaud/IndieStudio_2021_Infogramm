/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Block
*/

#include "Entity/Entity.hpp"
#include "encapsulation/Model/EModel.hpp"
#include "PowerUp/Speed.hpp"

#pragma once

namespace bmb::block {
    typedef enum {
        UNKNOWN = -1,
        WALL,
        BARREL,
        SPAWN,
        EMPTY
    } BlockTag;

class Block {
 public:

    /**
     * @brief Construct a new Block object
     *
     */
    Block(const std::string &modelName, const Texture &texture)
    : _tag(bmb::entity::BLOCK), _blockTag(EMPTY), _isDestructible(false), _bonus(false) {
        _model
        .load(modelName)
        .setTexture(texture)
        .setColor(bmb::rlib::color::White);
        _model.isVisible() = true;
    };

    /**
     * @brief Construct a new Block object
     *
     */
    Block(void)
        : _tag(bmb::entity::BLOCK), _blockTag(EMPTY), _isDestructible(false), _bonus(false) {
    }

    /**
     * @brief Destroy the Block object
     *
     */
    virtual ~Block(void) {};

    /**
     * @brief Construct a new display object
     *
     */
    virtual void display(void) {};

    /**
     * @brief return reference to _isVisible
     *
     * @return true
     * @return false
     */
    bool &isVisible(void) {
        return _model.isVisible();
    }

    /**
     * @brief Get the Tag object
     *
     * @return bmb::entity::TAG_ENTITY
     */
    bmb::entity::TAG_ENTITY getTag(void) const {
        return _tag;
    }

    /**
     * @brief Get the Model object
     *
     * @return bmb::rlib::EModel
     */
    bmb::rlib::EModel &getModel(void) {
        return _model;
    }

    /**
     * @brief Get the Position object
     *
     * @return Vector3f
     */
    Vector3f getPosition(void) const {
        return _model.getPosition();
    }

    /**
     * @brief Get the State object
     *
     * @return true
     * @return false
     */
    bool getIsDestructible(void) const {
        return _isDestructible;
    }

    /**
     * @brief Set the Position object
     *
     * @param position
     * @return Block&
     */
    Block &setPosition(Vector3f position) {
        _model.setPosition(position);
        return *this;
    }

    /**
     * @brief Set the State object
     *
     * @param state
     * @return Block&
     */
    Block &setDestructible(bool state) {
        _isDestructible = state;
        return *this;
    }

    /**
     * @brief get type of block
     *
     * @return BlockTags
     */
    BlockTag type(void) const {
        return _blockTag;
    }

    /**
     * @brief get if the block contain a bonus
     *
     * @return true
     * @return false
     */
    bool isBonus(void) const {
        return _bonus;
    }

    /**
     * @brief destroy Block
     *
     * @return Block&
     */
    virtual bool destroy(void) {
        return false;
    }

    std::shared_ptr<bmb::items::PowerUp> &getPowerUp(void) {
        _bonus = false;
        return _powerUp;
    }

 protected:
    bmb::entity::TAG_ENTITY _tag;
    bmb::block::BlockTag    _blockTag;
    bmb::rlib::EModel       _model;
    bool                    _isDestructible;
    bool                    _bonus;
    std::shared_ptr<bmb::items::PowerUp> _powerUp;
};
}
