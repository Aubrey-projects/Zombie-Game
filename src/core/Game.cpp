// This allows me to use these project files I made
#include "core/Game.h"
#include "content/Content.h"

// This allows me to read input or display output in the console, 
// which is important to use in a text adventure where you type
#include <iostream>

// Game
void Game::run() {
    // I wrote buildWorld in my Content file
    // This will just fill in the world that I made (so far, I have only made the underground bunker)
    buildWorld(world_, state_);

    // This will call describeCurrentRoom, defined below, so that we see something when we run the game
    describeCurrentRoom();

    std::string line;

    // This while true will continue to repeat until we break it
    while (true) {

        // This will write a new line, so it looks cleaner
        std::cout << "\n ";


        if (!std::getline(std::cin, line)) break;

        // This will turn the input from the user into a command that we can use
        Command command = parser_.parse(line);
        
        // This makes it so that if the user accidentally just pushes enter without typing, it'll iterate again
        if (command.verb.empty()) continue;

        // if the command is to quit, it'll stop the loop, ending the game
        if (command.verb == "quit") {
            std::cout << "Goodbye.\n";
            break;
        } else if (command.verb == "look") { // This is for if the command is not to quit, but instead to look
            describeCurrentRoom(); // However, I haven't fully implemented the look feature, so it is still incomplete
        } else if (command.verb == "go") {
            handleGo(command.noun); // If the command is "go" then you will move to that room
        } else {
            std::cout << "I don't understand that.\n"; // If the command is none of these, it tells the user that it can't understand that
        }
    }
}

void Game::describeCurrentRoom() const {
    // This looks up the room using its room id
    const Room* room = world_.getRoom(state_.currentRoomId);
    
    // If the room id doesn't match any of the predefined rooms, then it throws an error
    // This is useful for troubleshooting and knowing where the program went wrong.
    if (room == nullptr) {
        std::cout << "Bad room id: " << state_.currentRoomId << "\n";
        return;
    }

    // This prints out the room name and description on different lines
    // We obviously want this when we are exploring a place in a text adventure game
    std::cout << "\n" << room->name << "\n" << room->description << "\n";
}

// This is to allow you to move between rooms
void Game::handleGo(const std::string& direction) {
    // if you have the command to "go" but you do not specify the location, then it asks you where
    if (direction.empty()) {
        std::cout << "Go where?\n";
        return;
    }

    // This is to fetch the current room
    const Room* room = world_.getRoom(state_.currentRoomId);
    // If it is null, it returns
    if (room == nullptr) return;

    // This searches your room to see if where you want to go matches one of the exits of the room
    const Exit* exit = room->findExit(direction);
    
    // If that exit does not exist, then it says so to the user
    if (exit == nullptr) {
        std::cout << "You can't go that way.\n";
        return;
    }

    // However, if it does exist, then we will want to change the current room to that new room we entered
    state_.currentRoomId = exit->targetRoomId;

    // Then we'll want to describe it to the user
    describeCurrentRoom();
}