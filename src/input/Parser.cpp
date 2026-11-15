// These are my project files I am uncluding
#include "input/Parser.h"
#include "util/Utils.h"

// These are the libaries I am using
#include <unordered_map>
#include <unordered_set>

Command Parser::parse(const std::string& line) const {
    // if the player types alternative words that mean "go", or "look" or "quit", then it'll treat it the same
    static const std::unordered_map<std::string, std::string> synonyms = {
        {"walk", "go"}, {"move", "go"},
        {"enter", "go"}, {"climb", "go"},
        {"l", "look"}, {"examine", "look"},
        {"q", "quit"}, {"exit", "quit"}
    };
    // The program will ignore these filler words
    static const std::unordered_set<std::string> fillers = {"the", "a", "an", "to"};
    
    // Creates an empty command
    Command command;

    // Creates an empty list of strings
    std::vector<std::string> words;

    // This takes the users input and the util::toLower makes it lowercase and the 
    // util::split breaks it up into a list of words
    // The for loop then iterates through all those words
    for (const std::string& word : util::split(util::toLower(line))) {
        if (fillers.count(word) == 0) { // This checks to see if it is not a filler word
            words.push_back(word); // it is not, we are going to add that to the end of words
        }
    }
    // If there are no words in words (meaning it was empty or just filler words) then we'll just return
    if (words.empty()) {
        return command;
    }

    // We assume the first word is a verb, because in text adventure games, you typically type "grab [item]",
    // or "move [location]", or "hit [something]"
    command.verb = words[0];

    // This will then ehck out synonym map for words to a verb that we made above
    auto synonym = synonyms.find(command.verb);
    if (synonym != synonyms.end()) {
        // This will replace the user's verb with the standard one in the map I made
        command.verb = synonym->second;
    }

    // after we determine the verb we need to find the noun,
    // so what this does is if there are more than one word left after the verb,
    // it will loop through them and add a space before the word (except for the first one)
    // the purpose of this is if we have ["heavy", "steel", "door"]
    // we want it to become "heavy steel door"
    for (size_t i = 1; i < words.size(); ++i) {
        if (!command.noun.empty()) command.noun += " ";
        command.noun += words[i];
    }
    // it will finally return our resulting command
    // for example: {verb: "go", noun: "heavy steel door"}
    return command;
}