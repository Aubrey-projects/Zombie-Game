#include "entities/Room.h"

const Exit* Room::findExit(const std::string& phrase) const {
    for (const auto& [name, exit] : exits) {
        if (name == phrase) return &exit;
        for (const std::string& alias : exit.aliases) {
            if (alias == phrase) return &exit;
        }
    }
    return nullptr;
}