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

    if (args.mPart == 1) {
        p1(file);
    }
    if (args.mPart == 2) {
        p2(file);
    }
    file.close();
}