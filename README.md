
# C++ Calculator

A simple C++17 calculator application built with CMake
and tested using CTest.

## Project Structure

- src/ - Application implementation
- include/ - Header files
- tests/ - Unit tests
- CMakeLists.txt - Build configuration
- Jenkinsfile - Linux CI pipeline

## Requirements

- Linux
- GCC / G++
- CMake 3.16+
- Make or Ninja

## Configure

cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_TESTING=ON

## Build

cmake --build build --config Release --parallel 4

## Test

ctest --test-dir build -C Release --output-on-failure

## Run

./build/calculator

## Install

cmake --install build \
  --config Release \
  --prefix "$PWD/package"

## Package

tar -czf cpp-release.tar.gz -C package .

## Verify Package

tar -tzf cpp-release.tar.gz
