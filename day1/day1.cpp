#include <fstream>
#include <filesystem>
#include <print>

#include "args.h"

namespace fs = std::filesystem;

class Dial {
    public:
        void spin(std::string dir, int val) {
            if (dir == "L") {
                position -= val;
            }
            else {
                position += val;
            }
            position %= 100;
            if (position < 0) {
                position += 100;
            }

            if (position == 0) {
                password++;
            }
            return;
        };

        int getPosition(void) {
            std::println("Pos:  {}", position);
            return position;
        };

        int getPassword(void) {
            std::println("Pass: {}", password);
            return password;
        };
    
    private:
        int position = 50;
        int password = 0;
};


int main(int argc, char* argv[]) {
    const auto args = Args::parse(std::span(argv, argc));

    // Dial starts at 50
    Dial dial;

    std::ifstream file{args.mInput};
    
    std::string line;
    while (std::getline(file, line)) {
        //std::println("{}", line);
        //std::println("{}", (line.substr(0,1)=="L"));
        dial.spin(line.substr(0,1), std::stoi(line.substr(1)));
    }
    dial.getPassword();

}