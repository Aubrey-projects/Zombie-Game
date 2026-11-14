#pragma once
#include <string>
#include <unordered_map>

struct Exit {
    std::string targetRoomId;
};

struct Room {
    std::string id;
    std::string name;
    std::string description;
    std::unordered_map<std::string, Exit> exits;  
};