// This once again prevents the header from being included twice
#pragma once

// This will allow me to use these files that I made inside the project
#include "core/GameState.h"
#include "core/World.h"


// This declares buildWorld, but doesn't include its code
void buildWorld(World& world, GameState& state);