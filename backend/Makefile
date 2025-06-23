CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude
SRC := $(wildcard src/*.c)
OBJ := $(SRC:src/%.c=build/%.o)

BIN := raytracer

all: $(BIN)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf build $(BIN)

.PHONY: all clean
