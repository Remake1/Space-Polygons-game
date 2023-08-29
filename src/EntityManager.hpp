#ifndef CPPGAME_ENTITYMANAGER_HPP
#define CPPGAME_ENTITYMANAGER_HPP

#include <vector>
#include <map>
#include <memory>

#include "Entity.hpp"

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map   <std::string, EntityVec>     EntityMap;

class EntityManager {
    EntityVec m_entities;
    EntityMap m_entityMap;
    size_t m_totalEntities = 0;
public:
    EntityManager();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    EntityVec& getEntities();
    EntityVec& getEntities(const std::string& tag);
};


#endif //CPPGAME_ENTITYMANAGER_HPP
