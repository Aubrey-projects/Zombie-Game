// This is my header
#include "util/Utils.h"

// These are my libaries
#include <algorithm>
#include <cctype>
#include <sstream>

// a helper for strings across the project
namespace util {
    // This returns a lowercase copy of the text
    std::string toLower(const std::string& text) {
        std::string result = text;

        // We then apply tolower to every character and write it back to the same string
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return result;
    }

    // This splits the words on every space " " and it also ignores it if you have multiple spaces
    std::vector<std::string> split(const std::string& text) {
        std::vector<std::string> words;
        std::istringstream stream(text);
        std::string word;

        // This will read on word at a time and then return them
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }
}