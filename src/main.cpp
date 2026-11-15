// This allows main.cpp to use the Game file I created so that I can create a Game object 
#include "core/Game.h"

int main() {
    
    // This is where I make the game object which will run my game
    Game game;

    // After creating it, I have to run it, otherwise nothing will happen
    game.run();
    return 0;
}