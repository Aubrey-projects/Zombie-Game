#include "core/Game.h"
#include "content/Content.h"
#include <iostream>

void Game::run() {
    buildWorld(world_, state_);
    describeCurrentRoom();

    std::string line;
    while (true) {
        std::cout << "\n ";
        if (!std::getline(std::cin, line)) break;

        Command command = parser_.parse(line);
        if (command.verb.empty()) continue;

        if (command.verb == "quit") {
            std::cout << "Goodbye.\n";
            break;
        } else if (command.verb == "look") {
            describeCurrentRoom();
        } else if (command.verb == "go") {
            handleGo(command.noun);
        } else {
            std::cout << "I don't understand that.\n";
        }
    }
}

void Game::describeCurrentRoom() const {
    const Room* room = world_.getRoom(state_.currentRoomId);
    if (room == nullptr) {
        std::cout << "Bad room id: " << state_.currentRoomId << "\n";
        return;
    }
    std::cout << "\n" << room->name << "\n" << room->description << "\n";
    std::cout << "Exits:";
    for (const auto& [direction, exit] : room-> exits) {
        std::cout << " " << direction;
    }
    std::cout << "\n";
}

void Game::handleGo(const std::string& direction) {
    if (direction.empty()) {
        std::cout << "Go where?\n";
        return;
    }
    const Room* room = world_.getRoom(state_.currentRoomId);
    if (room == nullptr) return;

    auto it = room->exits.find(direction);
    if (it == room->exits.end()) {
        std::cout << "You can't go that way.\n";
        return;
    }
    state_.currentRoomId = it->second.targetRoomId;
    describeCurrentRoom();
}