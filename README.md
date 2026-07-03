# Advent of Code 2025

## Environment
This repo contains a `Dockerfile` and `devcontainer.json` meant for use with the VS Code Dev Container extension. The container is an Ubuntu 24.04 image which provides an environment for compiling C++ 23 using CMake.

## Building
```
mkdir build
cd build
cmake ..
make day1
```

## Running
`./day1/day1`

TODO: standardize each day with an argument for which input file it ingests