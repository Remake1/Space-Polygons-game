#include "EntityManager.hpp"

void EntityManager::update() {
    for (auto e : m_toAdd) {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    for (auto e : m_entities) {
        // Remove from m_entities using std::remove_if if e->m_alive() == false


        // Remove from m_entityMap[e->tag()] using std::remove_if if e->m_alive() == false

    }
    m_toAdd.clear();
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
    auto e = std::make_shared<Entity>(tag, m_totalEntities++);
    m_toAdd.push_back(e); // Add entity to queue
    return e;
}