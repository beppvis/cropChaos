
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
	${cc} -o ./build/cropchaos.o ./main.c -lraylib -L./build/ 
endif
ifeq ($(PLATFORM_OS),OSX)
	${cc} -I"../include/" ./main.c  -o ./build/cropchaos ${pkg_config} -L"./build/" -lgui
endif


clean:
	@echo "Cleaning build..."
	rm *.o
