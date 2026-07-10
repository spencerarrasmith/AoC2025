#include <fstream>
#include <filesystem>
#include <print>
#include <sstream>

#include "args.h"

namespace fs = std::filesystem;

void p1(std::ifstream& file) {
    //std::println("p1");
    uint64_t invalidSum = 0;

    std::stringstream ss;
    ss << file.rdbuf();
    std::string token;
    std::size_t div;
    uint64_t firstId;
    uint64_t lastId;
    std::string currentId;
    std::size_t currentIdLen;

    while (std::getline(ss, token, ',')) {
        //std::println("{}", token);
        div = token.find('-');
        firstId = std::stoll(token.substr(0,div));
        lastId = std::stoll(token.substr(div+1, token.length()));
        //std::println("{} {}", firstId, lastId);

        for (uint64_t i=firstId; i<=lastId; i++) {
            currentId = std::to_string(i);
            currentIdLen = currentId.length();

            if (currentIdLen % 2 == 0) {
                if (currentId.substr(0, currentIdLen/2) == currentId.substr(currentIdLen/2, currentIdLen)) {
                    //std::println("SILLY: {} {}", currentId.substr(0, currentIdLen/2), currentId.substr(currentIdLen/2, currentIdLen));
                    invalidSum += i;
                }
            }
        }

    }
    std::println("Sum: {}", invalidSum);
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