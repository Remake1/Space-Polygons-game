#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

class Vec2{
public:
    float x = 0;
    float y = 0;

    Vec2() = default;
    Vec2(float xInit, float yInit)
    : x(xInit), y(yInit)
    {}

    Vec2 operator + (const Vec2& rhs) const {
        return {x+rhs.x, y+rhs.y};
    }

    void operator += (const Vec2& rhs) {
        x += rhs.x;
        y += rhs.y;
    }

    Vec2 operator * (const Vec2& rhs) const {
        return {x*rhs.x, y*rhs.y};
    }

    Vec2& add(const Vec2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2& scale(float s) {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2& rotate(float deg) {
        return *this;
    }

    float dist(const Vec2& v) const {
        return sqrtf((v.x-x) * (v.x-x) + (v.y-y) * (v.y-y));
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);

    sf::CircleShape circle(90.f);

    Vec2 v1(10, 10);
    Vec2 v2(20, 20);

    Vec2 v3 = v1 + v2;

    float dist = v1.dist(v2);

    std::cout << v3.x << " " << v3.y << " " << dist << "\n";

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