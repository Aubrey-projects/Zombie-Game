#pragma once
#include <string>

struct Command {
    std::string verb;
    std::string noun;
    std::string target;
};

class Parser {
    public:
        Command parse(const std::string& line) const;
};