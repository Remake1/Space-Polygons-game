#ifndef CPPGAME_ENTITY_HPP
#define CPPGAME_ENTITY_HPP

#include <iostream>
#include <memory>

#include "CTransform.hpp"
#include "CScore.hpp"
#include "CLifespan.hpp"
#include "CInput.hpp"
#include "CCircleShape.hpp"
#include "CCircleCollision.hpp"


class Entity{
    friend class EntityManager;

    const size_t      m_id    = 0;
    const std::string m_tag   = "Default";
    bool              m_active = true;

    Entity(const std::string& tag, size_t id);
public:
    // Component pointers
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CScore> cScore;
    std::shared_ptr<CLifespan> cLifespan;
    std::shared_ptr<CInput> cInput;
    std::shared_ptr<CCircleShape> cCircleShape;
    std::shared_ptr<CCircleCollision> cCircleCollision;

    void destroy() { m_active = false; }
    const std::string& tag() { return m_tag; }
    const bool active() { return m_active; }
};


#endif //CPPGAME_ENTITY_HPP
