#ifndef CPPGAME_SCENE_HPP
#define CPPGAME_SCENE_HPP

#include "Common.hpp"
#include "EntityManager.hpp"
#include "GameEngine.hpp"

class GameEngine;

class Scene {
protected:
    GameEngine *m_game = nullptr;
    EntityManager m_entityManager;
    size_t m_currentFrame = 0;
    bool m_paused = false;
    bool m_hasEnded = false;

    void setPaused(bool paused);
    virtual void onEnd()=0;
public:
    Scene();
    explicit Scene(GameEngine * gameEngine);

    virtual void update()=0;
    virtual void sRender()=0;

    void simulate(const size_t frames);


    int getWidth() const;
    int getHeight() const;
    size_t getCurrentFrame() const;

    bool hasEnded() const;
};


#endif //CPPGAME_SCENE_HPP
