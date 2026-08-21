#include <fstream>
#include <filesystem>
#include <print>
#include <string>

#include "args.h"

namespace fs = std::filesystem;

const char floor = '.';
const char roll = '@';

void p1(std::ifstream& file) {
    std::string line;
    int numRows = 0;
    int numCols = 0;
    while (std::getline(file, line)) {
        numRows++;
        if (numCols == 0) {
            numCols = line.length()+1;  // include newline
        }
    }

    file.clear();
    file.seekg(0, file.end);
    int fileSize = file.tellg();
    file.seekg(0, file.beg);

    std::string text(fileSize, '\0');
    file.read(&text[0], fileSize);


    for (int i=0; i<numRows; i++) {
        if (i == 0) {
            for (int j=0; j<numCols-1; j++) {
                if (text[i*numCols + j] != floor) {
                    // @?
                    // ??
                    if (j == 0) {
                        text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                    }
                    // ?@
                    // ??
                    else if (j == numCols - 2) {
                        text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                    }
                    // ?@?
                    // ???
                    else {
                        text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                    }
                }
            }
        }
        else if (i == numRows-1) {
            for (int j=0; j<numCols-1; j++) {
                if (text[i*numCols + j] != floor) {
                    // ??
                    // @?
                    if (j == 0) {
                        text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                    }
                    // ??
                    // ?@
                    else if (j == numCols - 2) {
                        text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                    }
                    // ???
                    // ?@?
                    else {
                        text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                    }
                }
            }
        }
        else {
            for (int j=0; j<numCols-1; j++) {
                if (text[i*numCols + j] != floor) {
                    // ??
                    // @?
                    // ??
                    if (j == 0) {
                        text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                    }
                    // ??
                    // ?@
                    // ??
                    else if (j == numCols - 2) {
                        text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                    }
                    // ???
                    // ?@?
                    // ???
                    else {
                        text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                        text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j)] != floor;
                        text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            if (text[i*numCols + j] >= '=') {
                count++;
            }
        }
    }
    std::println("{}", count);
}


void p2(std::ifstream& file) {
    std::string line;
    int numRows = 0;
    int numCols = 0;
    while (std::getline(file, line)) {
        numRows++;
        if (numCols == 0) {
            numCols = line.length()+1;  // include newline
        }
    }

    file.clear();
    file.seekg(0, file.end);
    int fileSize = file.tellg();
    file.seekg(0, file.beg);

    std::string text(fileSize, '\0');
    file.read(&text[0], fileSize);

    int count = 0;
    int count_prev = -1;

    while(count != count_prev) {
        for (int i=0; i<numRows; i++) {
            if (i == 0) {
                for (int j=0; j<numCols-1; j++) {
                    if (text[i*numCols + j] != floor) {
                        // @?
                        // ??
                        if (j == 0) {
                            text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                        }
                        // ?@
                        // ??
                        else if (j == numCols - 2) {
                            text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                        }
                        // ?@?
                        // ???
                        else {
                            text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                        }
                    }
                }
            }
            else if (i == numRows-1) {
                for (int j=0; j<numCols-1; j++) {
                    if (text[i*numCols + j] != floor) {
                        // ??
                        // @?
                        if (j == 0) {
                            text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                        }
                        // ??
                        // ?@
                        else if (j == numCols - 2) {
                            text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                        }
                        // ???
                        // ?@?
                        else {
                            text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                        }
                    }
                }
            }
            else {
                for (int j=0; j<numCols-1; j++) {
                    if (text[i*numCols + j] != floor) {
                        // ??
                        // @?
                        // ??
                        if (j == 0) {
                            text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                        }
                        // ??
                        // ?@
                        // ??
                        else if (j == numCols - 2) {
                            text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + j] != floor;
                        }
                        // ???
                        // ?@?
                        // ???
                        else {
                            text[i*numCols + j] -= text[(i-1)*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + j] != floor;
                            text[i*numCols + j] -= text[(i-1)*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[i*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[i*numCols + (j+1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j-1)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j)] != floor;
                            text[i*numCols + j] -= text[(i+1)*numCols + (j+1)] != floor;
                        }
                    }
                }
            }
        }

        count_prev = count;
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<numCols; j++) {
                if (text[i*numCols + j] >= '=') {
                    count++;
                    text[i*numCols + j] = '.'; // remove roll
                }
                else if (text[i*numCols + j] >= '0') {
                    text[i*numCols + j] = '@'; // reset roll
                }
            }
        }
    }
    std::println("{}", count);
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