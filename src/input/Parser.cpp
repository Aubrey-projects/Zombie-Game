#include "input/Parser.h"
#include "util/Utils.h"
#include <unordered_map>
#include <unordered_set>

Command Parser::parse(const std::string& line) const {
    static const std::unordered_map<std::string, std::string> synonyms = {
        {"walk", "go"}, {"move", "go"},
        {"enter", "go"}, {"climb", "go"},
        {"l", "look"}, {"examine", "look"},
        {"q", "quit"}, {"exit", "quit"}
    };
    static const std::unordered_set<std::string> fillers = {"the", "a", "an", "to"};
    
    Command command;

    std::vector<std::string> words;
    for (const std::string& word : util::split(util::toLower(line))) {
        if (fillers.count(word) == 0) {
            words.push_back(word);
        }
    }
    if (words.empty()) {
        return command;
    }

    command.verb = words[0];
    auto synonym = synonyms.find(command.verb);
    if (synonym != synonyms.end()) {
        command.verb = synonym->second;
    }

    for (size_t i = 1; i < words.size(); ++i) {
        if (!command.noun.empty()) command.noun += " ";
        command.noun += words[i];
    }
    return command;
}