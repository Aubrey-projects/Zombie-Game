#include "util/Utils.h"
#include <algorithm>
#include <cctype>
#include <sstream>

namespace util {
    std::string toLower(const std::string& text) {
        std::string result = text;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
        return result;
    }

    std::vector<std::string> split(const std::string& text) {
        std::vector<std::string> words;
        std::istringstream stream(text);
        std::string word;

        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }
}