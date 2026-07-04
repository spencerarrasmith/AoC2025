#pragma once

#include <span>
#include <string>

struct Args {
    std::string mInput;

    static Args parse(std::span<char*> argv);
};