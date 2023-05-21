
## MAKEFILE

#VARIABLES
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lstdc++
TARGET = board-viz


# RULES

all: $(TARGET)

$(TARGET): board-viz.cpp
	$(CC) $(CFLAGS) -o $(TARGET) board-viz.cpp board.cpp notation.cpp move.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)	

.PHONY: all-clean

