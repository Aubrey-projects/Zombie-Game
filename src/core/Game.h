#pragma once
#include <string>
#include "core/GameState.h"
#include "core/World.h"
#include "input/Parser.h"

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