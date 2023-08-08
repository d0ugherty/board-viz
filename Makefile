
## MAKEFILE

#VARIABLES
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lstdc++
TARGET = build/board-viz


# RULES

all: $(TARGET)

$(TARGET): src/board-viz.cpp
	$(CC) $(CFLAGS) -o $(TARGET) src/board-viz.cpp src/board.cpp src/notation.cpp src/move.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)	

.PHONY: all-clean

