#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);

    sf::CircleShape circle(90.f);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}