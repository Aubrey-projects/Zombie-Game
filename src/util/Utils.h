#pragma once
#include <string>
#include <vector>

namespace util {
    // This makes the text lowercase so that you don't need to worry about capslock while playing
    std::string toLower(const std::string& text);

    // This splits a line into words so that it can make sense of your commands (for example: "go right" becomes {"go", "right"})
    std::vector<std::string> split(const std::string& text);
}