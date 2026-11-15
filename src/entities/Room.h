// This makes it so it is only declared once
#pragma once

// These are the libraries I'll need
#include <vector>
#include <string>
#include <unordered_map>

// These are the structures of the Room file that I made
// Since this is the header file, we are only declaring them
struct Exit {
    std::string targetRoomId;
    std::vector<std::string> aliases;
};

struct Room {
    // These are the variables of a room
    std::string id;
    std::string name;
    std::string description;
    std::unordered_map<std::string, Exit> exits; 
    
    const Exit* findExit(const std::string& phrase) const;
};