#ifndef CPPGAME_SCENE_HPP
#define CPPGAME_SCENE_HPP

#include "Common.hpp"
#include "EntityManager.hpp"

class GameEngine;

class Scene {
public:
    Scene()=default;

    explicit Scene(GameEngine * gameEngine);
protected:
    GameEngine * m_game=nullptr;
    EntityManager m_entityManager;
    size_t m_currentFrame = 0;
    bool m_paused = false;
    bool m_hasEnded = false;
public:
    virtual void update()=0;
    virtual void sRender()=0;
    void simulate(int);

    void setPaused(bool paused);
    size_t getWidth() const;
    size_t getHeight() const;
    size_t getCurrentFrame()const;
};


#endif //CPPGAME_SCENE_HPP
