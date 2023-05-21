#include <string>
#include <sstream>
#include <iostream>

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
/** Takes a portion of an algebraic notation string
 *  and converts that to an index on the chess board
 *  by mapping the characters to integers
 */
int Notation::toSquare(std::string alg_notation) {
    int file = alg_notation[0] - 'a';
	std::cout << "tosquare file = " << file <<std::endl;
    int rank = alg_notation[1] - '1';
	std::cout << "tosquare rank = " << rank <<std::endl;
    int index = rank * 8 + file;
	std::cout << "toSquare Index = " << index << std::endl;
    if(index >= 0 && index <=63) {
	return index;
    } else {
	//TO DO: add proper error handling
	std::cout << "Given square notation " << alg_notation << " does not map to a valid index between 0 and 63" << std::endl;
	return -1;
    }
}

/** Converts algebraic notation to a move object */
Move Notation::toMove(std::string alg_notation) {
	Move move(alg_notation);
	return move;
}



