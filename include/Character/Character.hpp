/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Character
*/

#include "Entity/Entity.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "encapsulation/Controller/Controller.hpp"
#include "encapsulation/Camera/ECamera.hpp"
#include "encapsulation/Text/EText.hpp"
#include "encapsulation/Model/EModel.hpp"
#include "encapsulation/Shapes/Shapes2D/ERectangle.hpp"
#include "Block/Block.hpp"
#include "Bomb/Bomb.hpp"
#include "System/System.hpp"

#pragma once

#define PATH_DEFAULT_MODEL_CHARACTER    "assets/model/poppy.iqm"

#define PATH_DEFAULT_MODEL_ANIMATION     "assets/model/poppywalk.iqm"

namespace bmb::character {

    typedef enum {
        UNKNOWN = -1,
        T_PLAYER,
        T_AI
    } CharacterTag_t;

    typedef enum {
        MODEL,
        CURSOR
    } DisplayMode_t;

    using indexController_u   = int;
    using indexEntity_u       = int;
    using tagEntity_u         = bmb::entity::TAG_ENTITY;

class Character : public bmb::entity::Entity {
 public:

    /**
     * @brief Construct a new Character object
     *
     * @param tag
     */
    Character(bmb::entity::TAG_ENTITY tag, const std::string &title, int indexEntity)
        : _tag(tag), _spawn(0, 0, 0), _indexEntity(indexEntity), _title(title),
        _mode(MODEL), _cursor(Vector2f(15.f, 15.f), Vector2f(0.f, 0.f)),
        _score(0), _alive(true), _rangeBomb(DEFAULT_RANGE_EXPLOSION), _speedBonus(0), _multi(1) {
        _model
        .load(PATH_DEFAULT_MODEL_CHARACTER)
        .setPosition(Vector3f(0.f, 1.0f, 2.0f))
        .setSize(Vector3f(5.0f, 5.0f, 5.0f))
        .setTexture(*bmb::sys->textures()["poppy"])
        .loadAnimation(PATH_DEFAULT_MODEL_ANIMATION);

        _cursor
        .setThick(2)
        .setColor(bmb::rlib::color::Red)
        .setPosition(Vector2f(400.f , 160.f));

        _texts["score"].setFontSize(50);
        _texts["bomb"].setFontSize(40);
        _texts["range"].setFontSize(40);
        _texts["speed"].setFontSize(40);
        _listBomb.push_back(std::shared_ptr<bmb::items::Bomb>(new bmb::items::Bomb()));
    }

    /**
     * @brief Destroy the Character object
     *
     */
    virtual ~Character(void) {};

    /**
     * @brief Get the Input object
     *
     * @return bmb::event::InputUser
     */
    virtual bmb::event::InputUser getInput(void) = 0;

    /**
     * @brief Move character
     *
     * @param input
     */
    virtual bool move(const bmb::event::InputUser &input) = 0;

    /**
     * @brief Action for character
     *
     * @param input
     */
    virtual void action(const bmb::event::InputUser &input, const bmb::clock::Clock &clock) = 0;

    /**
     * @brief Set the Spawn object
     *
     * @param _spawn
     */
    void setSpawn(const bmb::rlib::EVector3<float> spawn) {
        _spawn = spawn;
    }

    /**
     * @brief Respawn the player to is spawn
     *
     */
    void respawn(void) {
        _model.setPosition(_spawn);
    }

    /**
     * @brief Set the Mode Display object
     *
     * @param mode
     */
    void setModeDisplay(const DisplayMode_t &mode) {
        _mode = mode;
    }

    /**
     * @brief Display the character
     *
     */
    virtual void display(void) {
        if (!_alive)
            return;
        _model.display(Vector3f(1.0f, 0.0f, 0.0f), -90.f);
    }

    /**
     * @brief Get the Tag object
     *
     * @return tagEntity_u
     */
    tagEntity_u getTag(void) const {
        return _tag;
    }

    /**
     * @brief Draw Title
     *
     * @param camera
     */
    void drawTitle(bmb::rlib::ECamera &camera) {
        if (DISCONNECTED(getInput()))
            return;
        drawUI();
        if (!_alive)
            return;
        Vector3 tmpPos = {_model.getPosition()._x, _model.getPosition()._y + 21.0f, _model.getPosition()._z};
        Vector2 screenPos = GetWorldToScreen(tmpPos, camera.getCamera());
        screenPos.x -= MeasureText((_title + " " + std::to_string(_indexEntity)).c_str(), 20) / 2;
        bmb::rlib::EText text(_title + " " + std::to_string(_indexEntity), Vector2f(screenPos.x, screenPos.y));
        text.draw();
    }

    /**
     * @brief Get the Model object
     *
     * @return bmb::rlib::EModel&
     */
    bmb::rlib::EModel &getModel(void) {
        return _model;
    }

    /**
     * @brief Get the Cursor object
     *
     * @return bmb::rlib::shapes2D::ERectangle&
     */
    bmb::rlib::shapes2D::ERectangle &getCursor(void) {
        return _cursor;
    }

    /**
     * @brief check collision with block
     *
     * @return true
     * @return false
     */
    bool isCollision(std::shared_ptr<bmb::block::Block> &block) {
        if (!_alive)
            return false;
        if (block->type() == bmb::block::EMPTY && block->isBonus() && isCollisionB(block)) {
            auto bonus = block->getPowerUp();
            if (bonus->tag() == bmb::items::SPEED)
                _speedBonus += bonus->getBonus();
            if (bonus->tag() == bmb::items::RANGE)
                _rangeBomb += static_cast<int>(bonus->getBonus());
            if (bonus->tag() == bmb::items::BOMB)
                _listBomb.push_back(std::shared_ptr<bmb::items::Bomb>(new bmb::items::Bomb()));
        }
        if (block->type() == bmb::block::EMPTY || block->type() == bmb::block::SPAWN)
            return false;
        BoundingBox box1 = block->getModel().getBoundingBox();
        BoundingBox box2 = getModel().getBoundingBox();

        if (CheckCollisionBoxes(box1, box2)) {
            _model.setPosition(_oldPosition);
            return true;
        }
        return false;
    }

    /**
     * @brief check collision with block by BoundingBox
     *
     * @param block
     * @return true
     * @return false
     */
    bool isCollisionB(std::shared_ptr<bmb::block::Block> &block) {
        if (!_alive)
            return false;
        BoundingBox box1 = block->getModel().getBoundingBox();
        BoundingBox box2 = getModel().getBoundingBox();

        return CheckCollisionBoxes(box1, box2);
    }

    /**
     * @brief Reset the list of bomb
     *
     */
    void resetBombs(void) {
        _listBomb.clear();
        _listBomb.push_back(std::shared_ptr<bmb::items::Bomb>(new bmb::items::Bomb()));
    }

    /**
     * @brief Get the Bombs object
     *
     * @return std::vector<std::shared_ptr<bmb::items::Bomb>>&
     */
    std::vector<std::shared_ptr<bmb::items::Bomb>> &getBombs(void) {
        return _listBomb;
    }

    /**
     * @brief Update the bomb
     *
     * @param clock
     * @return Character&
     */
     std::list<std::shared_ptr<bmb::block::Block>> updateBomb(const bmb::clock::Clock &clock, bmb::rlib::AudioManager &audioManager) {
        std::list<std::shared_ptr<bmb::block::Block>> listBlock;

        if (!_alive)
            return listBlock;
        for (auto it : _listBomb) {
            auto tmp = it->update(clock);
            if (tmp.size())
                audioManager.playSound("explosion", true);
            for (auto it2 : tmp)
                listBlock.push_back(it2);
        }
        return listBlock;
    }

    /**
     * @brief Get the Speed Bonus object
     *
     * @return float
     */
    float getSpeedBonus(void) const {
        return _speedBonus;
    }

    /**
     * @brief Set the Speed Bonus object
     *
     * @param speed
     * @return Character&
     */
    Character &setSpeedBonus(const float &speed) {
        _speedBonus = speed;

        return *this;
    }

    /**
     * @brief Get type of character
     *
     * @return bmb::character::CharacterTag_t
     */
    virtual bmb::character::CharacterTag_t type(void) const = 0;

    /**
     * @brief Increment Score
     *
     * @return Character&
     */
    Character &addScore(void) {
        _score +=1;

        return *this;
    }

    /**
     * @brief Put Score to 0
     *
     * @return Character&
     */
    Character &clearScore(void) {
        _score = 0;

        return *this;
    }

    /**
     * @brief Get Score
     *
     * @return int
     */
    int score(void) const {
        return _score;
    }

    /**
     * @brief Get is character is alive
     *
     * @return true
     * @return false
     */
    bool isAlive(void) const {
        return _alive;
    }

    /**
     * @brief Set the State object
     *
     * @param alive
     * @return Character&
     */
    Character &setState(const bool &alive) {
        _alive = alive;

        return *this;
    }

    /**
     * @brief Draw Score
     *
     * @return Character&
     */
    Character &drawScore(void) {
        _texts["score"].setColor(_model.getColor());
        _texts["score"].setString(std::to_string(_score));
        _texts["score"].draw();

        return *this;
    }

    Character &drawUI(void) {
        drawScore();
        _texts["bomb"].setColor(bmb::rlib::color::Black);
        _texts["bomb"].setString(std::to_string(_listBomb.size()));
        _texts["bomb"].draw();

        _texts["range"].setColor(bmb::rlib::color::Black);
        _texts["range"].setString(std::to_string(_rangeBomb-1));
        _texts["range"].draw();

        _texts["speed"].setColor(bmb::rlib::color::Black);
        _texts["speed"].setString(std::to_string(static_cast<int>(_speedBonus)));
        _texts["speed"].draw();
        return *this;
    }

    /**
     * @brief Get the Text Score object
     *
     * @return bmb::rlib::EText&
     */
    bmb::rlib::EText &getText(const std::string &text) {
        return _texts[text];
    }

    /**
     * @brief Get the Buff Input object
     *
     * @return std::vector<bmb::event::InputUser>&
     */
    inline std::vector<bmb::event::InputUser> &getBuffInput() {return _inputs;}

    /**
     * @brief Get the Mutliplicator Speed
     *
     * @return float&
     */
    inline float &multiplicatorSpeed(void) { return _multi; }

    /**
     * @brief Get the range of Bomb
     *
     * @return int&
     */
    inline int &rangeBomb(void) { return _rangeBomb; }

 protected:
    tagEntity_u                                         _tag;
    const std::string                                   _title;
    int                                                 _indexEntity;
    bmb::rlib::EModel                                   _model;
    Vector3f                                            _spawn;
    DisplayMode_t                                       _mode;
	bmb::rlib::shapes2D::ERectangle                     _cursor;
    Vector3f                                            _oldPosition;
    std::vector<std::shared_ptr<bmb::items::Bomb>>      _listBomb;
    float                                               _speedBonus;
    int                                                 _score;
    bool                                                _alive;
    std::unordered_map<std::string, bmb::rlib::EText>   _texts;
    std::vector<bmb::event::InputUser>                  _inputs;
    float                                               _multi;
    int                                                 _rangeBomb;
};
}  // namespace bmb::char
