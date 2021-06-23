/*
** EPITECH PROJECT, 2021
** Boostrap_Indie
** File description:
** App
*/

#include <thread>
#include "App/App.hpp"

enum StateLoad {
    STATE_LOADING,
    STATE_FINISHED
};

static StateLoad state = STATE_FINISHED;

bmb::scene::IndexScene *bmb::scene::IndexScene::IndexScene::_indexScene = nullptr;
bmb::System *bmb::System::_system = nullptr;

bmb::App::App(void)
    : _window(new bmb::rlib::EWindow(R_800x600, "Bomberman")) {
    srand(time(NULL));
    _window->setFPS(60);
    _audioManager.addSound("assets/sound/click.mp3", "click");
    _audioManager.addSound("assets/sound/hover.mp3", "hover");
    _audioManager.addSound("assets/sound/limit.mp3", "limit");
    _audioManager.addSound("assets/sound/explosion.wav", "explosion");
    _audioManager.addMusic("assets/music/Menu.mp3", "menu");
    _audioManager.addMusic("assets/music/Game.mp3", "game");
    _audioManager.addMusic("assets/music/Scoreboard.mp3", "scoreboard");
    _listScenes[bmb::scene::SCENE_LOADING]      = std::shared_ptr<bmb::Scene>(new bmb::scene::Loading());
    _listScenes[bmb::scene::SCENE_LOADING]->loop(_window, _manager, _audioManager);
    _manager.add(bmb::character::T_PLAYER, 1);
    _listScenes[bmb::scene::SCENE_HOW_TO_PLAY]  = std::shared_ptr<bmb::Scene>(new bmb::scene::HowToPlay());
    _listScenes[bmb::scene::SCENE_MENU]         = std::shared_ptr<bmb::Scene>(new bmb::scene::Menu());
    _listScenes[bmb::scene::SCENE_GAME]         = std::shared_ptr<bmb::Scene>(new bmb::scene::Game());
    _listScenes[bmb::scene::SCENE_PAUSE]        = std::shared_ptr<bmb::Scene>(new bmb::scene::Pause());
    _listScenes[bmb::scene::SCENE_SETTINGS]     = std::shared_ptr<bmb::Scene>(new bmb::scene::Settings());
    _listScenes[bmb::scene::SCENE_OPTIONS]      = std::shared_ptr<bmb::Scene>(new bmb::scene::Options());
    _listScenes[bmb::scene::SCENE_SELECT_MAP]   = std::shared_ptr<bmb::Scene>(new bmb::scene::SelectMap());
    _listScenes[bmb::scene::SCENE_SCOREBOARD]   = std::shared_ptr<bmb::Scene>(new bmb::scene::Scoreboard());
    _listScenes[bmb::scene::SCENE_TRANSITION]   = std::shared_ptr<bmb::Scene>(new bmb::scene::Transition());
    _listScenes[bmb::scene::SCENE_TRANSITION]->setUp(_window, _manager);
}

bmb::App::~App(void) {
    bmb::scene::index->deleteI();
    bmb::sys->deleteS();
}

void loadScene(bmb::uniqueWindow &window, bmb::character::CharacterManager &cManager, std::shared_ptr<bmb::Scene> &scene) {
    scene->setUp(window, cManager);
    state = STATE_FINISHED;
}

void bmb::App::run(void) {
    std::thread loader;

    _audioManager.playMusic("menu");
    _audioManager.playMusic("game");
    _audioManager.playMusic("scoreboard");
    while (!_window->shouldClose()) {
        if (bmb::scene::index->value() == bmb::scene::SCENE_EXIT)
            break;
        if (!_listScenes[bmb::scene::index->value()]->isLoaded() && state != STATE_LOADING) {
            state = STATE_LOADING;
            loader = std::thread{loadScene, std::ref(_window), std::ref(_manager), std::ref(_listScenes[bmb::scene::index->value()])};
            loader.detach();
        }
        switch (state) {
            case STATE_LOADING: {
                _listScenes[bmb::scene::SCENE_TRANSITION]->loop(_window, _manager, _audioManager);
            } break;
            case STATE_FINISHED: {
                _listScenes[bmb::scene::index->value()]->loop(_window, _manager, _audioManager);
            } break;
            default: break;
        }
    }
}