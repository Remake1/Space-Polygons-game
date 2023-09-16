#ifndef CPPGAME_GAME_HPP
#define CPPGAME_GAME_HPP

#include "SFML/Graphics.hpp"
#include "EntityManager.hpp"

class Game {
    sf::RenderWindow m_window; // Game window where we draw
    EntityManager m_entities; // Vector of Entities
    sf::Font m_font; // Font that is used to draw text
    sf::Text m_text; // Scope text to be drawn
    int m_score = 0;
    int m_currentFrame = 0;
    bool m_paused = false; // Whether game is paused
    bool m_running = true; // Whether game is running

    std::shared_ptr<Entity> m_player;

    void init(const std::string & config); // Initialize the game state with config
    void setPaused(); // pause the game

    // TODO: Systems realization
};


#endif //CPPGAME_GAME_HPP
