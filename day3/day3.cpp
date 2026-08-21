#include <fstream>
#include <filesystem>
#include <print>
#include <vector>
#include <algorithm>

#include "args.h"

namespace fs = std::filesystem;

void p1(std::ifstream& file) {
    std::string line;

    int joltage_sum = 0;

    while (std::getline(file, line)) {
        //std::println("{}", line);
        int first_char = 9;
        bool first_found = false;
        int first_pos = 0;

        while (!first_found) {
            int cur_pos = 0;
            for (auto it = line.begin(); it != line.end()-1; ++it) {
                int digit = *it - '0';
                if (digit == first_char) {
                    first_found = true;
                    first_pos = cur_pos;
                    break;
                }
                cur_pos++;
            }
            if (!first_found) {
                first_char--;
            }
        }

        int second_char = 9;
        bool second_found = false;
        int second_pos = 0;
        
        while (!second_found) {
            int cur_pos = 0;
            for (auto it = line.begin()+first_pos+1; it != line.end(); ++it) {
                int digit = *it - '0';
                if (digit == second_char) {
                    second_found = true;
                    second_pos = cur_pos;
                    break;
                }
                cur_pos++;
            }
            if (!second_found) {
                second_char--;
            }
        }
        //std::println("{}{}", first_char, second_char);
        joltage_sum += first_char * 10 + second_char;
    }

    std::println("{}", joltage_sum);

}

void p2(std::ifstream& file) {
    std::string line;

    uint64_t joltage_sum = 0;

    while (std::getline(file, line)) {
        for (int i=12; i>0; i--) {
            std::string digit = "9";
            
            if (line.length() > 12) {
                while (line.substr(12-i, line.length()-(i-1)-(12-i)).find(digit) == std::string::npos) {
                    // decrement int-as-string
                    digit[0]--;
                }
                auto pos = line.substr(12-i, line.length()-(i-1)-(12-i)).find(digit) + (12-i);
                line.erase(line.begin()+12-i, line.begin()+pos);
            }
            else {
                break;
            }
        }
        line.erase(line.begin()+12, line.end());
        
        //std::println("");
        joltage_sum += std::stoll(line);
    }

    std::println("{}", joltage_sum);
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