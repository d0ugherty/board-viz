#ifndef NOTATION_H
#define NOTATION_H

#include <string>
#include "piece.h"

class Notation{
    public: 
	int to_square(const std::string& squareNotation);
	Piece toPiece(const char ascii);
	char to_char(Piece piece);
};

#endif
