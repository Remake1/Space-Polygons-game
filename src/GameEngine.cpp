#include "GameEngine.hpp"

GameEngine::GameEngine(const std::string &path) {
    init(path);
}

void GameEngine::init(const std::string &path) {
    // TODO: Config file load

    m_window.create(sf::VideoMode(1280, 720), "Space Shooter");
    m_window.setFramerateLimit(60);

    if (!m_font.loadFromFile("Arial.ttf"))
    {
        std::cout << "[Font Error] Error loading font!\n";
    }

    changeScene("MENU", std::make_shared<Scene_Menu>(this));
}

std::shared_ptr<Scene> GameEngine::currentScene() {
    return m_sceneMap[m_currentScene];
}

void GameEngine::update() {
    sUserInput();
    if(currentScene()) {
        currentScene()->update();
    }

    window().display();
}

void GameEngine::sUserInput() {
    sf::Event event;
    while (window().pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit();
        }
        if(currentScene()) {
            currentScene()->sUserInput(event);
        }
    }
}

void GameEngine::quit() {
    m_running = false;
}

void GameEngine::changeScene(const std::string &sceneName, std::shared_ptr<Scene> scene, bool endCurrentScene) {
    if(scene) {
        m_sceneMap[sceneName] = scene;
        if(endCurrentScene && currentScene()) {
            currentScene()->end();
        }
        m_currentScene = sceneName;
        currentScene()->start();
    }
}

sf::RenderWindow &GameEngine::window() {
    return m_window;
}

void GameEngine::run() {
    while (isRunning()) {
        update();
    }
}

bool GameEngine::isRunning() const {
    return m_running;
}