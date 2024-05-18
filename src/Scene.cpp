#include "Scene.hpp"
#include "GameEngine.hpp"

Scene::Scene(GameEngine *gameEngine) : m_game(gameEngine) {}

Scene::Scene() = default;

void Scene::simulate(const size_t frames) {}

void Scene::setPaused(bool paused) {
    m_paused = paused;
}

int Scene::getWidth() const {
    return m_game->window().getSize().x;
}

int Scene::getHeight() const {
    return m_game->window().getSize().y;
}

size_t Scene::getCurrentFrame() const {
    return m_currentFrame;
}

bool Scene::hasEnded() const { return m_hasEnded; }
