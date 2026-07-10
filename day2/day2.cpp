#include <fstream>
#include <filesystem>
#include <print>
#include <sstream>
#include <vector>

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

    // Separate comma-delimited tokens
    while (std::getline(ss, token, ',')) {
        div = token.find('-');
        firstId = std::stoll(token.substr(0, div));
        lastId = std::stoll(token.substr(div+1, token.length()));

        // Iterate through range
        for (uint64_t i=firstId; i<=lastId; i++) {
            currentId = std::to_string(i);
            currentIdLen = currentId.length();

            // Only consider even-length strings
            if (currentIdLen % 2 == 0) {
                // Check if first and second half are identical
                if (currentId.substr(0, currentIdLen/2) == currentId.substr(currentIdLen/2, currentIdLen)) {
                    //std::println("SILLY: {} {}", currentId.substr(0, currentIdLen/2), currentId.substr(currentIdLen/2, currentIdLen));
                    invalidSum += i;
                }
            }
        }

    }
    std::println("Sum: {}", invalidSum);
}

// Generate a vector of factors of an input number
// This is used to determine how many kernels to generate in part 2
std::vector<uint64_t> factorize(uint64_t val) {
    std::vector<uint64_t> factors = {1};
    for (uint64_t i=2; i<=val/2; i++) {
        if ((val/i)*i == val) {
            factors.push_back(i);
        }
    }
    return factors;
}

void p2(std::ifstream& file) {
    //std::println("p2");
    uint64_t invalidSum = 0;

    std::stringstream ss;
    ss << file.rdbuf();
    std::string token;
    std::size_t div;
    uint64_t firstId;
    uint64_t lastId;
    std::string currentId;
    uint64_t currentIdLen;
    bool shwilly = false;

    while (std::getline(ss, token, ',')) {
        div = token.find('-');
        firstId = std::stoll(token.substr(0, div));
        lastId = std::stoll(token.substr(div+1, token.length()));

        for (uint64_t i=firstId; i<=lastId; i++) {
            // Corner case - single digits can't be repeating
            if (i < 10) {
                continue;
            }
            shwilly = false;
            currentId = std::to_string(i);
            currentIdLen = static_cast<uint64_t>(currentId.length());

            // Need to find repeating patterns which fit in length of number
            std::vector<uint64_t> factors = factorize(currentIdLen);
            for (const uint64_t& width : factors) {
                // Leave instantly if this gets too silly
                if (shwilly) {
                    break;
                }
                // Generate zero-padded strings of format "00001" (example width=5) of lengths that can repeat inside number
                int val = 1;
                std::string kernel = std::vformat("{:0>{}}", std::make_format_args(val, width));
                std::string out;
                out.reserve(currentIdLen);
                // Generate repeating pattern
                for (int j=0; j<currentIdLen/kernel.length(); j++) {
                    out += kernel;
                }

                uint64_t pattern = std::stoll(out);

                // Test if a substring of the current id * pattern is equal to i
                // 135 * 001001001 == 135135135
                // Flag as silly, add to sum
                if (std::stoll(currentId.substr(0, width)) * pattern == i) {
                    shwilly = true;
                    invalidSum += i;
                    std::println("{} = {} * {}", currentId, currentId.substr(0, width), pattern);
                }
            }
        }
    }
    std::println("Sum: {}", invalidSum);
}

/* XYZXYZ = XYZ * palindrome of format [order of magnitude of XYZ repeating until value is one order of magnitude less than XYZXYZ]1
123123123 = 123 * 1001001
242424 = 24 * 10101
135791357913579 = 13579 * 10000100001

need to check substrings of lengths {factors of length of number}
248248248248 -> {1, 2, 3, 4, 6}
248248248248 == 2 * 111111111111 ?
248248248248 == 24 * 10101010101 ?
248248248248 == 248 * 1001001001 ? -- true; stop here
248248248248 == 2482 * 100010001 ?
248248248248 == 248248 * 1000001 ?

248248248248
111111111111
1 repeating to len(val)

248248248248
010101010101
01 repeating to len(val)

248248248248
001001001001
001 repeating to len(val)

248248248248
000001000001

*/

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