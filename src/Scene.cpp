#include "Scene.hpp"
#include "GameEngine.hpp"

Scene::Scene(GameEngine *gameEngine) : m_game(gameEngine) {}

void Scene::simulate(int simulationSpeed) {
    // TODO: Implement simulation
}

void Scene::setPaused(bool paused) {
    m_paused = paused;
}

size_t Scene::getWidth() const {
    return m_game->window().getSize().x;
}

size_t Scene::getHeight() const {
    return m_game->window().getSize().y;
}

size_t Scene::getCurrentFrame() const {
    return m_currentFrame;
}

