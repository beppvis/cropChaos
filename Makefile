.PHONY: compile clean


UNAME_OS = $(shell uname)
ifeq ($(UNAME_OS),Darwin)
	pkg_config := $(shell pkg-config --libs -cflags raylib)
	PLATFORM_OS = OSX
endif
ifeq ($(UNAME_OS),Linux)
	PLATFORM_OS = LINUX
endif

cc = clang

compile: 
	@echo "compiling .. "
ifeq ($(PLATFORM_OS),LINUX)
	${cc}  -o ./build/cropchaos ./src/main.c -lraylib -I"./include/" -lm
endif
ifeq ($(PLATFORM_OS),OSX)
	${cc} -o ./build/cropchaos ./src/main.c -I./include/ ${pkg_config} -L"./build/" 
endif

run: compile
	@echo "Running the game ..."
	cd ./build/ && ./cropchaos

test: compile
	@echo "Running tests ..."
	./build/cropchaosTest


clean:
	@echo "Cleaning build..."
	rm ./build/*
