CFLAGS += $(shell pkg-config --cflags sdl2)
CFLAGS += -Wall -Wextra -pedantic -std=c11

LDFLAGS += $(shell pkg-config --libs sdl2)

.PHONY = debug clean

all: dummy-window

debug: CFLAGS += -O0 -g
debug: dummy-window

clean:
	rm dummy-window
