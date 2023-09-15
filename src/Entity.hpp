#ifndef CPPGAME_ENTITY_HPP
#define CPPGAME_ENTITY_HPP

#include <iostream>
#include <memory>

class Entity{
    const size_t      m_id    = 0;
    const std::string m_tag   = "Default";
    bool              m_alive = true;

    Entity(const std::string& tag, size_t id);
    friend class EntityManager;
public:
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CName>      cName;
    std::shared_ptr<CShape>     cShape;
    std::shared_ptr<CBBox>      cBBox;
    void destroy() { m_alive = false; }
    const std::string& tag() { return m_tag; }
    const bool alive() { return m_alive; }
};


#endif //CPPGAME_ENTITY_HPP
