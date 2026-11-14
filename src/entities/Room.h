#pragma once
#include <vector>
#include <string>
#include <unordered_map>

struct Exit {
    std::string targetRoomId;
    std::vector<std::string> aliases;
};

struct Room {
    std::string id;
    std::string name;
    std::string description;
    std::unordered_map<std::string, Exit> exits; 
    
    const Exit* findExit(const std::string& phrase) const;
};