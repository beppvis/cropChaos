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

build: 
	@echo "Building .. "
ifeq ($(PLATFORM_OS),LINUX)
	mkdir -p build
	${cc}  -o ./build/cropchaos ./src/main.c -lraylib -I"./include/" -lm
endif
ifeq ($(PLATFORM_OS),OSX)
	mkdir -p build
	${cc} -o ./build/cropchaos ./src/main.c -I./include/ ${pkg_config} -L"./build/" 
endif

run: clean build
	@echo "Running the game ..."
	cd ./build/ && ./cropchaos --no-log

debug: clean build
	@echo "Running the game ..."
	cd ./build/ && ./cropchaos


test: compile
	@echo "Running tests ..."
	./build/cropchaosTest


clean:
	@echo "Cleaning build..."
	rm -r ./build/
