#!/bin/sh


mkdir -p ./build
clang -o ./build/gamename ./main.c -lraylib -L./build/


