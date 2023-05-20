#include <string>
#include <sstream>

#include "notation.h"
#include "piece.h"


Piece Notation::toPiece(const char ascii) {
    switch (ascii)
    {
	case 'P':
	    return Piece::WhitePawn;
	case 'N':
	    return Piece::WhiteKnight;
	case 'B':
	    return Piece::WhiteBishop;
	case 'R':
	    return Piece::WhiteRook;
	case 'Q':
	    return Piece::WhiteQueen;
	case 'K':
	    return Piece::WhiteKing;
	case 'p':
	    return Piece::BlackPawn;
	case 'n':
	    return Piece::BlackKnight;
	case 'b':
	    return Piece::BlackBishop;
	case 'r':
	    return Piece::BlackRook;
	case 'q':
	    return Piece::BlackQueen;
	case 'k':
	    return Piece::BlackKing;
	default:
	    return Piece::None;
    }
}
