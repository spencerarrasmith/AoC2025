#include <fstream>
#include <filesystem>
#include <print>

#include "args.h"

namespace fs = std::filesystem;

void p1(std::ifstream& file) {
    std::println("p1");
}

void p2(std::ifstream& file) {
    std::println("p2");
}

int main(int argc, char* argv[]) {
    const auto args = Args::parse(argc, argv);

    std::ifstream file{args.mInput};
    if (!file.is_open()) {
        std::println(stderr, "Failed to open file: {}", args.mInput);
        return 1;
    }

    switch (args.mPart) {
        case 1:
            p1(file);
            break;
        case 2:
            p2(file);
            break;
        default:
            return -1;
    }
    return 0;
}