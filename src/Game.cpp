#include "Game.hpp"

Game::Game(const std::string &config) {
    init(config);
}

void Game::init(const std::string &config) {
    // TODO: read the config

    // default windows parameters
    m_window.create(sf::VideoMode(1280, 720), "Ball game");
    m_window.setFramerateLimit(60);

    spawnPlayer();
}

void Game::run() {
    // TODO: add pause functionality
    while (m_running){
        m_entities.update();

        if(!m_paused){
            sEnemySpawner();
            sMovement();
            sCollision();
            sUserInput();
        }

        sRender();

        m_currentFrame++;
    }
}

void Game::setPaused() {
    m_paused = !m_paused;
}

void Game::spawnPlayer() {
    auto entity = m_entities.addEntity("player");

    // Set components to player
    // TODO: config support

    // Move player to starting position and change velocity
    float mx = m_window.getSize().x / 2;
    float my = m_window.getSize().y / 2;
    entity->cTransform = std::make_shared<CTransform>(Vec2(mx, my), Vec2(1.0f, 1.0f), 0.f);

    // Set player shape (Circle) and color
    entity->cCircleShape = std::make_shared<CCircleShape>(28.0f, 8, sf::Color::Cyan, sf::Color::Magenta, 4.0f);

    // Set circle collision
    // TODO: make the same radius as at Circle Shape
    entity->cCircleCollision = std::make_shared<CCircleCollision>(28.0f);

    // Set input state inside player by adding Input component
    entity->cInput = std::make_shared<CInput>();

    // TODO: Add Lifespan and Score

    // Set local player to player entity (against entity manager paradigm)
    m_player = entity;
}

void Game::spawnEnemy() {
    // TODO: enemy spawner

    // use m_lastEnemySpawnTime and m_currentFrame to spawn enemies timmed
}


// SYSTEMS

void Game::sUserInput() {
    sf::Event event;

    while(m_window.pollEvent(event)){
        // trigger event when window is closed
        if(event.type == sf::Event::Closed){
            m_running = false;
        }

        // triggers when key is pressed
        if(event.type == sf::Event::KeyPressed){
            switch (event.key.code) {
                case sf::Keyboard::W:
                    m_player->cInput->up = true;
                    break;
                case sf::Keyboard::A:
                    m_player->cInput->left = true;
                    break;
                case sf::Keyboard::S:
                    m_player->cInput->down = true;
                    break;
                case sf::Keyboard::D:
                    m_player->cInput->right = true;
                    break;
                default:
                    break;
            }
        }

        // triggers when key is released
        if(event.type == sf::Event::KeyReleased){
            switch (event.key.code) {
                case sf::Keyboard::W:
                    m_player->cInput->up = false;
                    break;
                case sf::Keyboard::A:
                    m_player->cInput->left = false;
                    break;
                case sf::Keyboard::S:
                    m_player->cInput->down = false;
                    break;
                case sf::Keyboard::D:
                    m_player->cInput->right = false;
                    break;
                default:
                    break;
            }
        }


    }
}

void Game::sRender() {
    m_window.clear();

    // TODO: Update all Entities
    // TODO: HUD: score, etc...
    // TODO: Rotations

    // Handle new entity properties:
    // Set player shape actual position to Transform position value
    m_player->cCircleShape->circle.setPosition(m_player->cTransform->pos.x, m_player->cTransform->pos.y);

    // Draw player entity
    m_window.draw(m_player->cCircleShape->circle);

    // Render all circle entities
    for (auto e : m_entities.getEntities()) {
        // Handle new entity properties:
        e->cCircleShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);
        // Draw entity
        m_window.draw(e->cCircleShape->circle);
    }

    // Render changes (kinda like swapbuffers).
    m_window.display();
}

void Game::sMovement() {
    // TODO
}

void Game::sCollision() {
    // TODO
}

void Game::sEnemySpawner() {
    // TODO
}
