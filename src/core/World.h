// this is to make sure there are no errors when it compiles from it being declared twice
#pragma once

// We will need these libaries
#include <string>
#include <unordered_map>

// This makes it so we can use Room, which we will have many of in the world
#include "entities/Room.h"

// This just declares the structure, but not the code itself
class World {
    public:
        void addRoom(const Room& room);

        const Room* getRoom(const std::string& id) const;

    private:
        // This is essentially a dictionary to allow for quick lookup
        std::unordered_map<std::string, Room> rooms_;
};
