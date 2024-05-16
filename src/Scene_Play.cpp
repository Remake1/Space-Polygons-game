#include "Scene_Play.hpp"

Scene_Play::Scene_Play(GameEngine *gameEngine) : Scene(gameEngine) {
    init();
}

void Scene_Play::init() {
    spawnPlayer();
}

void Scene_Play::setPaused() {
    m_paused = !m_paused;
}

void Scene_Play::spawnPlayer() {
    auto entity = m_entities.addEntity("player");

    // Set components to player
    // TODO: config support

    // Move player to starting position and change velocity
    float mx = m_window.getSize().x / 2;
    float my = m_window.getSize().y / 2;
    entity->cTransform = std::make_shared<CTransform>(Vec2(mx, my), Vec2(0.0f, 0.0f), 0.f);

    // Set player shape (Circle) and color
    entity->cCircleShape = std::make_shared<CCircleShape>(28.0f, 8, sf::Color::Cyan, sf::Color::Magenta, 4.0f);

    // Set circle collision
    // TODO: make the same radius as at Circle Shape
    entity->cCircleCollision = std::make_shared<CCircleCollision>(28.0f);

    // Set input state inside player by adding Input component
    entity->cInput = std::make_shared<CInput>();

    // TODO: Add Lifespan and Score
    entity->cLifespan = std::make_shared<CLifespan>(3, 10);

    // Set local player to player entity (against entity manager paradigm)
    m_player = entity;
}

// Spawns a bullet.
// entity - entity, that "shots".
// target - mouse position, for direction where bullet in shot.
void Scene_Play::spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & target) {
    // Add bullet entity.
    auto bullet = m_entities.addEntity("bullet");
    // Set bullet position to the mouse, and velocity to 0.
    bullet->cTransform = std::make_shared<CTransform>(entity->cTransform->pos, entity->cTransform->pos.getNormalizedVelocity(target)*5, 0);
    // Add shape and color.
    bullet->cCircleShape = std::make_shared<CCircleShape>(10.0f, 8, sf::Color::Yellow, sf::Color(82, 58, 0), 2);
    // Add collision radius
    bullet->cCircleCollision = std::make_shared<CCircleCollision>(10.0f);
}

// Spawns an enemy
void Scene_Play::spawnEnemy() {
    auto entity = m_entities.addEntity("enemy");

    float ex = 10 + (rand() % (m_window.getSize().x - 10));
    float ey = 10 + (rand() % (m_window.getSize().y - 10));

    entity->cTransform = std::make_shared<CTransform>(Vec2(ex, ey), Vec2(0.0f, 0.0f), 0.0f);

    entity->cCircleShape = std::make_shared<CCircleShape>(24.0f, 20, sf::Color::Red, sf::Color::White, 3.0f);
    // TODO: make the same radius as at Circle Shape
    entity->cCircleCollision = std::make_shared<CCircleCollision>(24.0f);

    entity->cLifespan = std::make_shared<CLifespan>(1, 60);
}

void Scene_Play::spawnEnemyBullet(std::shared_ptr<Entity> entity, int bullet_velocity = 5) {
    // Spawn bullet to the player position.
    auto bullet = m_entities.addEntity("enemy_bullet");
    bullet->cTransform = std::make_shared<CTransform>(entity->cTransform->pos, entity->cTransform->pos.getNormalizedVelocity(m_player->cTransform->pos)*bullet_velocity, 0);
    bullet->cCircleShape = std::make_shared<CCircleShape>(10.0f, 8, sf::Color::Red, sf::Color(82, 58, 0), 2);
    bullet->cCircleCollision = std::make_shared<CCircleCollision>(10.0f);
}

bool Scene_Play::isInWindow(Vec2 &point) const {
    // TODO: Window x y from config
    if (point.x <= m_window.getSize().x && point.x >=0 && point.y <= m_window.getSize().y && point.y >= 0){
        return true;
    } else return false;
}

// -------------------
// SYSTEMS
// -------------------