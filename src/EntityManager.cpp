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
    for (auto &key_values: m_entityMap) {
        // kv is a key-value pair contained in the map
        //    key   (kv.first):  the tag string
        //    value (kv.second): the vector storing entities
        removeDeadEntities(key_values.second);
    }
}

void EntityManager::removeDeadEntities(EntityVec &vec) {
    // use std::remove_if to remove dead entities
    // probably not the fastest solution, but it is safe
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                             [](const std::shared_ptr<Entity> &entity) { return !entity->active(); }),
              vec.end());
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string &tag) {
    // Instead of:
    //    auto e = std::make_shared<Entity>(tag, m_totalEntities++);
    // We create Entity with "old" way, because Entity constructor is private and EntityManager is friend class
    auto e = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_toAdd.push_back(e); // Add entity to queue
    return e;
}

EntityVec &EntityManager::getEntities() {
    return m_entities;
}

EntityVec &EntityManager::getEntities(const std::string &tag) {
    // TODO: retern Entities with tag
    return m_entities;
}