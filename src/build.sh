#!/bin/sh

mkdir -p ./build

clang -o ./build/libplayer.so -fPIC -shared ./player.c  -lraylib 

clang -o ./build/cropchaos ./main.c -lraylib -L./build/ 
