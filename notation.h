#ifndef NOTATION_H
#define NOTATION_H

#include <string>
#include "piece.h"
#include "move.h"

class Notation{
    public: 
	static int toSquare(const std::string squareNotation);
	static Piece toPiece(const char ascii);
	static char toChar(Piece piece);
	static Move toMove(const std::string moveNotation);
};

#endif
