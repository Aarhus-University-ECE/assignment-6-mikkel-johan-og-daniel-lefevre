.PHONY: all configure build test clean

all: build

configure:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

build: configure
	cmake --build build

test: build
	./build/unit-tests

clean:
	rm -rf build
