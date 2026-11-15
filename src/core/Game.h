// This is a header I made for the Game.cpp to just declare what Game is made of, but doesn't include the actual code.

// This will stop the header from being declared twice
// The reason I write this is to avoid errors when it compiles
#pragma once

// This allows be to use strings (std::string), which we will be using
#include <string>

// This just allows me to use the stuff I wrote in GameState, World, and Parser
#include "core/GameState.h"
#include "core/World.h"
#include "input/Parser.h"

// This is just the structure of my Game file
class Game {
    public:
        void run();

    private:
        void describeCurrentRoom() const;
        void handleGo(const std::string& direction);

        GameState state_;
        World world_;
        Parser parser_;
};