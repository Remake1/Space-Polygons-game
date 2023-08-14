#include <SFML/Graphics.hpp>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Changes the speed, so circle can move to the opposite direction
void circleBounce(sf::CircleShape &circle, float &sx, float &sy)
{
    // left
    if (circle.getPosition().x <= 0.f)
        sx = -sx;
    // top
    if (circle.getPosition().y <= 0.f)
        sy = -sy;
    // right
    if (circle.getPosition().x+(2*circle.getRadius()) >= (float)WINDOW_WIDTH)
        sx = -sx;
    // bottom
    if (circle.getPosition().y+(2*circle.getRadius()) >= (float)WINDOW_HEIGHT)
        sy = -sy;

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);

    // Circle
    float sx = 0.5f;
    float sy = 0.5f;

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(300, 150);

    // Font
    sf::Font myFont;
    if (!myFont.loadFromFile("Arial.ttf"))
    {
        std::cerr << "Couldn't load the font!\n";
        exit(-1);
    }

    // Text
    sf::Text text("Sample text", myFont, 24);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, WINDOW_HEIGHT-(float)text.getCharacterSize());

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up){
                    sx += 0.1f;
                    sy += 0.1f;
                } if (event.key.code == sf::Keyboard::Down) {
                    sx -= 0.1f;
                    sy -= 0.1f;
                }
            }
        }

        circle.setPosition(circle.getPosition().x + sx, circle.getPosition().y + sy);
        circleBounce(circle, sx, sy);

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(text);
        window.display();
    }

    return 0;
}