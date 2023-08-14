#include <SFML/Graphics.hpp>
#include <iostream>

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

// Changes the speed, so figure can move to the opposite direction
void figureBounce(sf::CircleShape &circle, float &sx, float &sy)
{
    // left or right
    if (circle.getPosition().x <= 0.f
    || circle.getPosition().x+(2*circle.getRadius()) >= (float)WINDOW_WIDTH)
        sx = -sx;
    // top or bottom
    if (circle.getPosition().y <= 0.f
    || circle.getPosition().y+(2*circle.getRadius()) >= (float)WINDOW_HEIGHT)
        sy = -sy;
}
void figureBounce(sf::RectangleShape &rectangle, float &sx, float &sy)
{
    // left or right
    if (rectangle.getPosition().x <= 0.f
        || rectangle.getPosition().x+(rectangle.getSize().x) >= (float)WINDOW_WIDTH)
        sx = -sx;
    // top or bottom
    if (rectangle.getPosition().y <= 0.f
        || rectangle.getPosition().y+(rectangle.getSize().y) >= (float)WINDOW_HEIGHT)
        sy = -sy;
}

void centerTextByFigure(sf::Text &text, sf::CircleShape &circle)
{
    float roundCenterX = circle.getPosition().x + circle.getRadius();
    float roundCenterY = circle.getPosition().y + circle.getRadius();

    float textX = roundCenterX - text.getGlobalBounds().width / 2.f;
    float textY = roundCenterY - text.getGlobalBounds().height / 2.f;

    text.setPosition(textX, textY);
}
void centerTextByFigure(sf::Text &text, sf::RectangleShape &rectangle)
{
    float roundCenterX = rectangle.getPosition().x + rectangle.getSize().x/2.f;
    float roundCenterY = rectangle.getPosition().y + rectangle.getSize().y/2.f;

    float textX = roundCenterX - text.getGlobalBounds().width / 2.f;
    float textY = roundCenterY - text.getGlobalBounds().height / 2.f;

    text.setPosition(textX, textY);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);

    // Circle
    float sx = 2.0f;
    float sy = 2.0f;

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(500, 150);

    // Rectangle
    float sx_1 = 3.5f;
    float sy_1 = 3.5f;

    sf::RectangleShape rect({170.f, 120.f});
    rect.setFillColor(sf::Color::Green);

    // Font
    sf::Font myFont;
    if (!myFont.loadFromFile("Arial.ttf"))
    {
        std::cerr << "Couldn't load the font!\n";
        exit(-1);
    }

    // Text
    sf::Text text_c("CRed", myFont, 24);
    sf::Text text_r("CGreen", myFont, 20);
    text_c.setFillColor(sf::Color::White);
    text_r.setFillColor(sf::Color::White);

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
        figureBounce(circle, sx, sy);
        centerTextByFigure(text_c, circle);

        rect.setPosition(rect.getPosition().x + sx_1, rect.getPosition().y + sy_1);
        figureBounce(rect, sx_1, sy_1);
        centerTextByFigure(text_r, rect);



        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(text_c);
        window.draw(rect);
        window.draw(text_r);
        window.display();
    }

    return 0;
}