#include "core/World.h"
#include <iostream>

void World::addRoom(const Room& room) {
    // This will add the room
    rooms_[room.id] = room;
}

const Room* World::getRoom(const std::string& id) const {
    // searches the map and finds the room
    auto it = rooms_.find(id);

    // If it wasn't found, it returns none
    if (it == rooms_.end()) {
        return nullptr;
    }

    // it->second is the Room, it->first is the id
    return &it->second;
}