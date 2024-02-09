#ifndef CPPGAME_GAME_HPP
#define CPPGAME_GAME_HPP

#include "SFML/Graphics.hpp"
#include "EntityManager.hpp"

class Game {
    const int W_WIDTH = 1280;
    const int W_HEIGHT = 720;

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

    std::shared_ptr<Entity> m_player;

    void init(const std::string & config); // Initialize the game state with config
    void setPaused(); // pause the game

    void sMovement();       // System: Entity positioning and movement update
    void sUserInput();      // System: User input
    void sLifespan();       // System: Lifespan
    void sRender();         // System: Rendering and drawing
    void sEnemySpawner();   // System: Spawn Enemies
    void sCollision();      // System: Collisions

    void spawnPlayer();
    void spawnEnemy();
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & target);
    void spawnEnemyBullet(std::shared_ptr<Entity> entity, int bullet_velocity);

    bool isInWindow(Vec2 & point) const;
//    void spawnSpecialWeapon();

public:
    Game(const std::string & config);
    void run();
};


#endif //CPPGAME_GAME_HPP
