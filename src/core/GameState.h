// This is the container for the player's progress,
// so far I am only having it hold the ID of the room the player is in
// but when I continue expanding the program it would do more.
#pragma once
#include <string>

struct GameState {
    std::string currentRoomId;
};