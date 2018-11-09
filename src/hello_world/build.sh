#!/bin/sh
rm -rf hello_world
clang++  hello_world.cpp `llvm-config --cxxflags --ldflags --libs --system-libs`  -o hello_world