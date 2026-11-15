// This connects it to its header
#include "content/Content.h"

// This function is to build the world
void buildWorld(World& world, GameState& state) {
    // This creates the airlock in the bunker and defines its variables
    Room airlock;
    airlock.id = "airlock";
    airlock.name = "Airlock";
    airlock.description = "You are in a small concrete room with a rusted steel ladder leading up to a hatch\nthat you assume leads to the surface.\nThe room is empty aside from a heavy steel door to the left of you.";
    airlock.exits["heavy steel door"] = {"common_area", {"steel door", "door", "left"}};
    airlock.exits["hatch"] = {"outside", {"rusted steel ladder", "steel ladder", "rusted ladder", "ladder"}};

    // This creates the common area in the bunker and defines its variables
    Room common_area;
    common_area.id = "common_area";
    common_area.name = "Common Area";
    common_area.description = "You are in a large room with concrete walls and a wooden plank floor.\nOn one wall there is a heavy steel door with a coat rack standing to the right of it\nand a doorway to the left of it leading out into a hallway.\nThe opposite wall has a wooden door and a countertop with a stove burner and drawers.\nThe wall inbetween has a large yellow door that looks industrial.\nInside the room, there is a rectangular wooden table with five chairs at it,\nand a seating area with a sofa and an end table with a radio sitting on top of it.";
    common_area.exits["heavy steel door"] = {"airlock", {"steel door"}};
    common_area.exits["wooden door"] = {"food_storage"};
    common_area.exits["large yellow door"] = {"generator_room", {"yellow door"}};
    common_area.exits["doorway"] = {"hallway", {"hallway"}};

    // This creates the food storage area in the bunker and defines its variables
    Room food_storage;
    food_storage.id = "food_storage";
    food_storage.name = "Food Storage";
    food_storage.description = "You are in a long room with mostly empty shelves of food, with just a few cans sitting ontop of them.\nOn one side of the room there is a large refrigerator and freezer.\nThere is also the wooden door that you just came through.";
    food_storage.exits["wooden door"] = {"common_area"};

    // This creates the generator room in the bunker and defines its variables
    Room generator_room;
    generator_room.id = "generator_room";
    generator_room.name = "Generator Room";
    generator_room.description = "Inside the large yellow door, there is a dark concrete room with blinking lights and heavy sounds of machinery.\nIt appears to be a generator room. To the left of you, you see cans of propane.";
    generator_room.exits["large yellow door"] = {"common_area", {"yellow door"}};

    // This creates the hallway in the bunker and defines its variables
    Room hallway;
    hallway.id = "hallway";
    hallway.name = "Hallway";
    hallway.description = "You are in a hallway with three wooden doors across it, each labeled with a different plaque.\nThe first plaque has the name jamie, the second plaque has the name cody, and the third plaque is blank.\nAt the very end of the hallway there is a white door,\nand the other end is a doorway leading into what appears to be a common area.";
    hallway.exits["doorway"] = {"common_area", {"common area"}};
    hallway.exits["wooden door with jamie's plaque"] = {"bedroom_1", {"jamie's door", "jamie's room"}};
    hallway.exits["wooden door with cody's plaque"] = {"bedroom_2", {"cody's door", "cody's room"}};
    hallway.exits["wooden door with no plaque"] = {"bedroom_3", {"nobody's room", "door with no plaque"}};
    hallway.exits["white door"] = {"showers"};

    // This creates a bedroom in the bunker and defines its variables
    Room bedroom_1;
    bedroom_1.id = "bedroom_1";
    bedroom_1.name = "Your Bedroom.";
    bedroom_1.description = "You are in a room with a wooden door on one side, and a bed on the other.\nThe bed is messily made, and to the right of it there is a desk with a medical kit.\nThere is also a closet holding a few different t-shirts and pants.";
    bedroom_1.exits["wooden door"] = {"hallway", {"door"}};

    // This creates another bedroom in the bunker and defines its variables
    Room bedroom_2;
    bedroom_2.id = "bedroom_2";
    bedroom_2.name = "Cody's Bedroom";
    bedroom_2.description = "You are in a room with a neatly made bed with a desk next to it that has a potted plant.\nOn one side of the room there is a closet sporting many kinds of clothes, and a wooden door that you came through.";
    bedroom_2.exits["wooden door"] = {"hallway", {"door"}};

    // This creates another bedroom in the bunker and defines its variables
    Room bedroom_3;
    bedroom_3.id = "bedroom_3";
    bedroom_3.name = "Unclaimed Bedroom";
    bedroom_3.description = "You are in a room with a bare mattress, desk, and an empty closet.\nThere is also the wooden door you came from.";
    bedroom_3.exits["wooden door"] = {"hallway", {"door"}};

    // This creates the room with the showers in the bunker and defines its variables
    Room showers;
    showers.id = "showers";
    showers.name = "Showers";
    showers.description = "You are in a room with a white door against one wall, and two showers along the other.\nThe wall inbetween has a sink and cabinet to one side and a curtain separating another room to the other side.";
    showers.exits["white door"] = {"hallway", {"door"}};
    showers.exits["curtain"] = {"bathroom"};

    // This creates the bathroom in the bunker and defines its variables
    Room bathroom;
    bathroom.id = "bathroom";
    bathroom.name = "Bathroom";
    bathroom.description = "You are in a room with a curtain separating another room on one side, and a large steel door on the other side.\nIn between them, there is a small toilet and a shelf holding stacks of toilet paper.";
    bathroom.exits["curtain"] = {"showers"};
    bathroom.exits["large steel door"] = {"escape_tunnel", {"steel door", "door"}};

    // This creates the escape tunnel in the bunker and defines its variables
    Room escape_tunnel;
    escape_tunnel.id = "escape_tunnel";
    escape_tunnel.name = "Escape Tunnel";
    escape_tunnel.description = "You are in a narrow room with a large steel door and stairs leading up to what appears to be an emergency exit.";
    escape_tunnel.exits["large steel door"] = {"bathroom", {"steel door", "door"}};
    escape_tunnel.exits["stairs"] = {"surface"};

    // This will add each one to the world
    world.addRoom(airlock);
    world.addRoom(common_area);
    world.addRoom(food_storage);
    world.addRoom(generator_room);
    world.addRoom(hallway);
    world.addRoom(bedroom_1);
    world.addRoom(bedroom_2);
    world.addRoom(bedroom_3);
    world.addRoom(showers);
    world.addRoom(bathroom);
    world.addRoom(escape_tunnel);

    // This defines which of these rooms will be the one that you start in
    state.currentRoomId = "bedroom_1";
}