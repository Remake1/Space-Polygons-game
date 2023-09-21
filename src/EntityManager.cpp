#include "EntityManager.hpp"

EntityManager::EntityManager() {

}

void EntityManager::update() {
    for (auto e : m_toAdd) {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAdd.clear();

    removeDeadEntities(m_entities);
    for (auto& [tag, entityVec]: m_entityMap) {
        removeDeadEntities(entityVec);
    }
}

// Remove Vector if isActive equals false.
void EntityManager::removeDeadEntities(EntityVec &vec) {
    std::erase_if(vec, [](auto& entity) { return !entity->isActive(); });
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
    // Instead of:
    //    auto e = std::make_shared<Entity>(tag, m_totalEntities++);
    // We create Entity with "old" way, because Entity constructor is private and EntityManager is friend class
    auto e = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_toAdd.push_back(e); // Add entity to queue
    return e;
}

// Returns all entities.
EntityVec &EntityManager::getEntities() {
    return m_entities;
}

// Returns all entities with specified tag.
EntityVec &EntityManager::getEntities(const std::string &tag) {
    return m_entityMap[tag];
}