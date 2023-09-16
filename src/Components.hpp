#ifndef CPPGAME_COMPONENTS_HPP
#define CPPGAME_COMPONENTS_HPP

#include <SFML/Graphics.hpp>
#include "Vec2.hpp"

class CCircleCollision {
public:
    float radius = 0;
    CCircleCollision(float r)
            : radius(r) {}
};

class CCircleShape {
public:
    sf::CircleShape circle;

    CCircleShape(float radius, int points, const sf::Color & fill, const sf::Color & outline, float thickness)
            : circle(radius, points)
    {
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        // Setting the center of rotation, transformation, scaling to the circle center (radius, radius)
        circle.setOrigin(radius, radius);
    }

};

class CInput {
public:
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool shoot = false;

    CInput() {}
};

class CLifespan {
public:
    int total = 0; // total amount of lifespan
    int remaining = 0; // remaining amount of lifespan on the entity
    CLifespan(int t)
            : total(t), remaining(t) {}
};

class CScore {
public:
    int score = 0;
    CScore(int s)
            : score(s) {}
};

class CTransform {
public:
    Vec2 pos = {0.0, 0.0};
    Vec2 velocity = {0.0, 0.0};
    float angle = 0;

    CTransform(const Vec2 & p, const Vec2 & v, float a)
            : pos(p), velocity(v), angle(a) {}
};

#endif //CPPGAME_COMPONENTS_HPP
