#include "args.h"

#include <getopt.h>
#include <stdexcept>

Args Args::parse(int argc, char* const argv[]) {
  Args args{1, "input.txt"};
  int opt;
  while ((opt = getopt(argc, argv, "p:f:")) != -1) {
    switch (opt) {
      case 'p':
        args.mPart = std::stoi(optarg);
        if (args.mPart != 1 && args.mPart != 2)
          throw std::invalid_argument("Part must be 1 or 2");
        break;
      case 'f':
        args.mInput = optarg;
        break;
      default:
        throw std::invalid_argument("Usage: prog [-p 1|2] [-f filename]");
    }
  }
  return args;
}