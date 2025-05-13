
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
	${cc}  -o ./build/cropchaos ./main.c -lraylib -I"../include/" -lm
endif
ifeq ($(PLATFORM_OS),OSX)
	${cc} -o ./build/cropchaos ./main.c -I"../include/" ${pkg_config} -L"./build/" 
	${cc} -o ./build/cropchaosTest ./test/test_ecs.c -I"../include/" ${pkg_config} -L"./build/" 
endif

run: compile
	@echo "Runnning the binary"
	./build/cropchaos --no-log

test: compile
	@echo "Runnning the binary"
	./build/cropchaosTest


clean:
	@echo "Cleaning build..."
	rm *.o
