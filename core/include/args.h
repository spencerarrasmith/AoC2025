#pragma once
#include <string>

struct Args {
    int mPart;
    std::string mInput;

    static Args parse(int argc, char* const argv[]);
};