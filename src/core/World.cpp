#include "core/World.h"

void World::addRoom(const Room& room) {
    rooms_[room.id] = room;
}

const Room* World::getRoom(const std::string& id) const {
    auto it = rooms_.find(id);
    if (it == rooms_.end()) {
        return nullptr;
    }
    return &it->second;
}