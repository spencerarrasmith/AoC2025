#include <fstream>
#include <filesystem>
#include <print>

#include "args.h"

namespace fs = std::filesystem;

class Dial {
    public:
        void spin(std::string dir, int val) {
            
            if (dir == "L") {
                for (int i=0; i<val; i++) {
                    position--;
                    if (position < 0) {
                        position += 100;
                    }
                    if (position == 0) {
                        p2password++;
                    }
                }
            }
            else {
                for (int i=0; i<val; i++) {
                    position++;
                    if (position > 99) {
                        position -= 100;
                    }
                    if (position == 0) {
                        p2password++;
                    }

                }
            }

            if (position == 0) {
                p1password++;
            }

            return;
        };

        int getPosition(void) {
            std::println("Pos:  {}", position);
            return position;
        };

        int getP1(void) {
            std::println("P1: {}", p1password);
            return p1password;
        };

        int getP2(void) {
            std::println("P2: {}", p2password);
            return p2password;
        };
    
    private:
        int position = 50;
        int p1password = 0;
        int p2password = 0;
};

void p1(std::ifstream& file) {
    // Dial starts at 50
    Dial dial;

    std::string line;
    while (std::getline(file, line)) {
        //std::println("{}", line);
        //std::println("{}", (line.substr(0,1)=="L"));
        dial.spin(line.substr(0,1), std::stoi(line.substr(1)));
    }
    dial.getP1();
    return;
}

void p2(std::ifstream& file) {
    // Dial starts at 50
    Dial dial;

    std::string line;
    while (std::getline(file, line)) {
        dial.spin(line.substr(0,1), std::stoi(line.substr(1)));
    }
    dial.getP2();
    return;
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