#pragma once
#include <string>
#include <unordered_map>
#include "entities/Room.h"

class World {
    public:
        void addRoom(const Room& room);

        const Room* getRoom(const std::string& id) const;

    private:
        std::unordered_map<std::string, Room> rooms_;
};