#include "content/Content.h"

void buildWorld(World& world, GameState& state) {
    Room airlock;
    airlock.id = "airlock";
    airlock.name = "Airlock";
    airlock.description = "";
    airlock.exits[""] = {"outside"};
    airlock.exits[""] = {"common_area"};

    Room common_area;
    common_area.id = "common_area";
    common_area.name = "Common Area";
    common_area.description = "";
    common_area.exits[""] = {"airlock"};
    common_area.exits[""] = {"food_storage"};
    common_area.exits[""] = {"generator_room"};
    common_area.exits[""] = {"hallway"};


    Room food_storage;
    food_storage.id = "food_storage";
    food_storage.name = "Food Storage";
    food_storage.description = "";
    food_storage.exits[""] = {"common_area"};

    Room generator_room;
    generator_room.id = "generator_room";
    generator_room.name = "Generator Room";
    generator_room.description = "";
    generator_room.exits[""] = {"common_area"};

    Room hallway;
    hallway.id = "hallway";
    hallway.name = "Hallway";
    hallway.description = "";
    hallway.exits[""] = {"common_area"};
    hallway.exits[""] = {"bedroom_1"};
    hallway.exits[""] = {"bedroom_2"};
    hallway.exits[""] = {"bedroom_3"};
    hallway.exits[""] = {"showers"};

    Room bedroom_1;
    bedroom_1.id = "bedroom_1";
    bedroom_1.name = "";
    bedroom_1.description = "";
    bedroom_1.exits[""] = {"hallway"};

    Room bedroom_2;
    bedroom_2.id = "bedroom_2";
    bedroom_2.name = "";
    bedroom_2.description = "";
    bedroom_2.exits[""] = {"hallway"};

    Room bedroom_3;
    bedroom_3.id = "bedroom_3";
    bedroom_3.name = "";
    bedroom_3.description = "";
    bedroom_3.exits[""] = {"hallway"};

    Room showers;
    showers.id = "showers";
    showers.name = "Showers";
    showers.description = "";
    showers.exits[""] = {"hallway"};
    showers.exits[""] = {"bathroom"};

    Room bathroom;
    bathroom.id = "bathroom";
    bathroom.name = "Bathroom";
    bathroom.description = "";
    bathroom.exits[""] = {"showers"};
    bathroom.exits[""] = {"escape_tunnel"};

    Room escape_tunnel;
    escape_tunnel.id = "escape_tunnel";
    escape_tunnel.name = "Escape Tunnel";
    escape_tunnel.description = "";
    escape_tunnel.exits[""] = {"bathroom"};
    escape_tunnel.exits[""] = {"surface"};


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

    state.currentRoomId = "bedroom_1";   // starting room

}