#ifndef CPPGAME_SCENEPLAY_HPP
#define CPPGAME_SCENEPLAY_HPP

#include "Scene.hpp"


class Scene_Play : public Scene {
private:
    std::shared_ptr<Entity> m_player;

    const int W_WIDTH = getWidth();
    const int W_HEIGHT = getHeight();

    sf::RenderWindow m_window; // Game window where we draw
    EntityManager m_entities; // Vector of Entities
    sf::Font m_font; // Font that is used to draw text
    sf::Text m_text; // Scope text to be drawn
    int m_score = 0;
    int m_currentFrame = 0;
    int lastEnemySpawnTime = 0;
    int enemySpawnInterval = 180;
    bool m_paused = false; // Whether game is paused
    bool m_running = true; // Whether game is running

public:
    Scene_Play()=default;
    explicit Scene_Play(GameEngine * gameEngine);

    void spawnPlayer();
    void spawnEnemy();
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & target);
    void spawnEnemyBullet(std::shared_ptr<Entity> entity, int bullet_velocity);

    bool isInWindow(Vec2 & point) const;

    void init();
    void setPaused(); // pause the game

    // Systems
    void sMovement();       // System: Entity positioning and movement update
    void sUserInput();      // System: User input
    void sLifespan();       // System: Lifespan
    void sRender();         // System: Rendering and drawing
    void sEnemySpawner();   // System: Spawn Enemies
    void sCollision();      // System: Collisions

};


#endif //CPPGAME_SCENEPLAY_HPP
