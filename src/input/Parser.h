// makes sure it only gets declared once
#pragma once

// the library I use
#include <string>

// the structure of the file
struct Command {
    std::string verb;
    std::string noun;
    std::string target;
};

class Parser {
    public:
        Command parse(const std::string& line) const;
};