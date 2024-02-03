#include "GameEngine.hpp"

GameEngine::GameEngine(const std::string &config) { init(config); }
void GameEngine::update() {
    sUserInput();
    m_sceneMap.at(m_currentScene)->update();
    m_currentFrames++;
}

void GameEngine::init(const std::string &path) {
    m_assets.loadFromFile(path);

    m_window.create(sf::VideoMode(1920, 1080), "Ball game");
    m_window.setFramerateLimit(60);
    // m_window.setPosition(sf::Vector2i(350, 200));

    changeScene(eGameEngineScenes::MENU, std::make_shared<Scene_Menu>(this));
}

std::shared_ptr<Scene> GameEngine::currentScene() {
    return m_sceneMap[m_currentScene];
}

bool GameEngine::isRunning() { return m_running & window().isOpen(); }

sf::RenderWindow &GameEngine::window() { return m_window; }

void GameEngine::run() {
    while (isRunning())
        update();
}

void GameEngine::sUserInput() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            quit();
        if (event.type == sf::Event::KeyPressed ||
            event.type == sf::Event::KeyReleased) {
            // if the current scene does not have an action associated with this key,
            // skip the event
            if (currentScene()->getActionMap().find(event.key.code) ==
                currentScene()->getActionMap().end())
                continue;
            // determinate start or end action whether it was pres or release
            eActionTypes actionType = (event.type == sf::Event::KeyPressed)
                                      ? eActionTypes::START
                                      : eActionTypes::END;
            // look up the action and send the action to the scene
            currentScene()->sDoAction(Action(
                    currentScene()->getActionMap().at(event.key.code), actionType));
        }
    }
}

void GameEngine::changeScene(eGameEngineScenes scenes,
                             const std::shared_ptr<Scene> &scene,
                             bool endCurrentScene) {
    // review this one
    m_currentScene = scenes;
    if (scene)
        m_sceneMap[scenes] = scene;
}

const Assets &GameEngine::getAssets() const { return m_assets; }

void GameEngine::quit() { m_running = false; }

std::shared_ptr<Scene> GameEngine::getScene(eGameEngineScenes scenes) {
    return m_sceneMap[scenes];
}