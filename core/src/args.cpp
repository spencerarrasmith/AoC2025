#include "args.h"

Args Args::parse(std::span<char*> argv) {
  return { argv.size() > 1 ? argv[1] : "input.txt" };
}