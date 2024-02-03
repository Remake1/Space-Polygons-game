#ifndef CPPGAME_GAMEENGINE_HPP
#define CPPGAME_GAMEENGINE_HPP

#include <iostream>
#include <map>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include "Action.hpp"
#include "Assets.hpp"

enum eGameEngineScenes {
    MENU = 0,
    PLAY = 1
};

class Scene;

typedef std::map<eGameEngineScenes, std::shared_ptr<Scene>> SceneMap;

class GameEngine {
protected:
    sf::RenderWindow m_window;
    Assets m_assets;
    eGameEngineScenes m_currentScene;

    SceneMap m_sceneMap;

    size_t m_simulationSpeed = 1;
    bool m_running = true;
    size_t m_currentFrames = 0;

    void init(const std::string & config); // Initialize the game state with config
    void update();

    void sUserInput();

    std::shared_ptr<Scene> currentScene();

public:
    explicit GameEngine(const std::string & config);

    void changeScene(eGameEngineScenes scenes,
                     const std::shared_ptr<Scene> &scene,
                     bool endCurrentScene = false);

    void quit();
    void run();

    sf::RenderWindow &window();
    const Assets &getAssets() const;
    bool isRunning();
    std::shared_ptr<Scene> getScene(eGameEngineScenes);
};


#endif //CPPGAME_GAMEENGINE_HPP
