#include "entities/Room.h"

// This looks through the room's exits for the one that matches the user's input
const Exit* Room::findExit(const std::string& phrase) const {
    for (const auto& [name, exit] : exits) {
        if (name == phrase) return &exit;
        for (const std::string& alias : exit.aliases) {
            if (alias == phrase) return &exit;
        }
    }
    // If it does not match, then it returns nullptr
    return nullptr;
}