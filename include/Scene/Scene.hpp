/*
** EPITECH PROJECT, 2021
** B-YEP-400-RUN-4-1-indiestudio-lucas.courteaud
** File description:
** Scene
*/

#include "Character/CharacterManager.hpp"
#include "encapsulation/Camera/ECamera.hpp"
#include "encapsulation/Window/EWindow.hpp"
#include "encapsulation/Audio/AudioManager.hpp"
#include "encapsulation/Image/EImage.hpp"
#include "System/System.hpp"
#include "Widget/Button.hpp"
#include "Clock/Clock.hpp"

#pragma once

namespace bmb::scene {
    typedef enum {
        SCENE_EXIT = -1,
        SCENE_MENU,
        SCENE_SETTINGS,
        SCENE_GAME,
        SCENE_PAUSE,
        SCENE_OPTIONS,
        SCENE_SELECT_MAP,
        SCENE_LOADING,
        SCENE_HOW_TO_PLAY,
        SCENE_TRANSITION,
        SCENE_SCOREBOARD
    } SceneTag_t;

class IndexScene {
 public:
    IndexScene(const IndexScene &other) = delete;

    void operator=(const IndexScene &other) = delete;

    /**
     * @brief Get the Singleton IndexScene Object
     *
     * @return IndexScene*
     */
    static IndexScene *get(void) {
        if (_indexScene == nullptr)
            _indexScene = new IndexScene(SCENE_LOADING);
        return _indexScene;
    }

    /**
     * @brief Set the singleton IndexScene Object
     *
     * @param index
     */
    static void set(const SceneTag_t &index) {
        if (_indexScene == nullptr)
            _indexScene = new IndexScene(index);
        else {
            if (_indexScene->_index != index)
                _indexScene->_lastIndex = _indexScene->_index;
            _indexScene->_index = index;
        }
    }

    /**
     * @brief Get the value of the singleton
     *
     * @return SceneTag_t
     */
    SceneTag_t value(void) const {
        return _index;
    }

    SceneTag_t lastValue(void) const {
        return _lastIndex;
    }

    /**
     * @brief Delete the singleton
     *
     */
    void deleteI(void) {
        if (_indexScene != nullptr)
            delete _indexScene;
        _indexScene = nullptr;
    }

 protected:
    /**
     * @brief Construct a new Index Scene object
     *
     * @param index
     */
    IndexScene(const SceneTag_t &index)
        : _index(index), _lastIndex(index) {}

    static IndexScene *_indexScene;

    SceneTag_t _index;
    SceneTag_t _lastIndex;
};
    static IndexScene *index = IndexScene::get();
};

namespace bmb {
    using uniqueWindow = std::unique_ptr<bmb::rlib::EWindow>;

class Scene {
 public:

    /**
     * @brief Construct a new Scene object
     *
     */
    Scene(void)
        : _isLoaded(false) {
    }

    /**
     * @brief Destroy the Scene object
     *
     */
    virtual ~Scene(void) {}

    /**
     * @brief Load the scene
     *
     */
    virtual void load(void) = 0;

    /**
     * @brief Unload the scene
     *
     */
    virtual void unload(void) = 0;

    /**
     * @brief
     *
     * @return false / false
     */
    bool isLoaded(void) const {
        return _isLoaded;
    }

    /**
     * @brief
     *
     * @param tag
     */
    void switchScene(const bmb::scene::SceneTag_t &tag) {
        bmb::scene::index->set(tag);
        unload();
    }

    /**
     * @brief Set the Up object
     *
     * @param window
     * @param cManager
     */
    virtual void setUp(uniqueWindow &window, bmb::character::CharacterManager &cManager) = 0;

    /**
     * @brief
     *
     * @param window
     * @param cManager
     */
    virtual void loop(uniqueWindow &window, bmb::character::CharacterManager &cManager, bmb::rlib::AudioManager &audioManager) = 0;

 protected:
    bool                                                    _isLoaded;
    bmb::rlib::ECamera                                      _mainCamera;
    std::unordered_map<std::string, bmb::widget::Button>    _buttons;
    std::unordered_map<std::string, bmb::rlib::EText>       _texts;
    std::unordered_map<std::string, bmb::rlib::EImage>      _images;
    bmb::clock::Clock                                       _clock;
};
}  // namespace bmb
