#!/bin/sh

mkdir -p ./build

clang -o ./build/libplayer.so -fPIC -shared ./player.c  -lraylib 

clang ./main.c $(pkg-config --libs -cflags raylib) -o ./build/cropchaos 

./build/cropchaos
