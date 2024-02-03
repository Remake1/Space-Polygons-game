#ifndef CPPGAME_ANIMATION_HPP
#define CPPGAME_ANIMATION_HPP

#include "Vec2.hpp"

#include <vector>
#include <SFML/Graphics.hpp>

enum eAnimationTypes {

};

class Animation {
    sf::Sprite m_sprite;
    size_t m_frameCount = 1;  // total number of frames of animation
    size_t m_currentFrame = 0;// the current frame of animation being played
    size_t m_speed = 0;       // the speed to play this animation
    Vec2 m_size = {1, 1};     // size of the animation frame
    eAnimationTypes m_name;

public:
    Animation();
    Animation(eAnimationTypes &name, const sf::Texture &t);
    Animation(eAnimationTypes &name, const sf::Texture &t, size_t frameCount,
              size_t speed);

    void update();
    bool hasEnded() const;
    eAnimationTypes getName() const;
    const Vec2 &getSize() const;
    sf::Sprite &getSprite();
};

#endif //CPPGAME_ANIMATION_HPP
