#ifndef MOVE_H
#define MOVE_H
#include "piece.h"
#include <string>

struct Move {
    public:
	//TO DO: Add static castling move
	int from_index;
	int to_index;
	Piece Promotion;
	// Constructors
	Move(int from, int to);
	Move(int from, int to, Piece promotion);
	Move(std::string move_notation);
};

#endif
