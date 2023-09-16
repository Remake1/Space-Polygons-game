#ifndef CPPGAME_CCIRCLESHAPE_HPP
#define CPPGAME_CCIRCLESHAPE_HPP

#include <SFML/Graphics.hpp>


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


#endif //CPPGAME_CCIRCLESHAPE_HPP
