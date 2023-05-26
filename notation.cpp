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
    int rank = alg_notation[1] - '1';

    int index = rank * 8 + file;
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

/** Converts a piece object to the char representation **/
char Notation::toChar(Piece piece) {
    switch(piece) {
	case Piece::WhitePawn:
	    return 'P';
	case Piece::WhiteKnight:
	    return 'N';
	case Piece::WhiteRook:
	    return 'R';
	case Piece::WhiteBishop:
	    return 'B';
	case Piece::WhiteQueen:
	    return 'Q';
	case Piece::WhiteKing:
	    return 'K';
	case Piece::BlackPawn:
	    return 'p';
	case Piece::BlackKnight:
	    return 'n';
	case Piece::BlackRook:
	    return 'r';
	case Piece::BlackBishop:
	    return 'b';
	case Piece::BlackQueen:
	    return 'q';
	case Piece::BlackKing:
	    return 'k';
	default:
	    return ' ';
    }
}

std::string Notation::toString(Piece piece) {
    switch(piece) {
	case Piece::WhitePawn:
	    return "White Pawn";
	case Piece::WhiteKnight:
	    return "White Knight";
	case Piece::WhiteRook:
	    return "White Rook";
	case Piece::WhiteBishop:
	    return "White Bishop";
	case Piece::WhiteQueen:
	    return "White Queen";
	case Piece::WhiteKing:
	    return "White King";
	case Piece::BlackPawn:
	    return "Black Pawn";
	case Piece::BlackKnight:
	    return "Black Knight";
	case Piece::BlackRook:
	    return "Black Rook";
	case Piece::BlackBishop:
	    return "Black Bishop";
	case Piece::BlackQueen:
	    return "Black Queen";
	case Piece::BlackKing:
	    return "Black King";
	default:
	    return ' ';
    }
}

std::string Notation::toString(const char ascii) {
    switch(ascii) {
	case 'P':
	    return "White Pawn";
	case 'N':
	    return "White Knight";
	case 'R':
	    return "White Rook";
	case 'B':
	    return "White Bishop";
	case 'Q':
	    return "White Queen";
	case 'K':
	    return "White King";
	case 'p':
	    return "Black Pawn";
	case 'n':
	    return "Black Knight";
	case 'r':
	    return "Black Rook";
	case 'b':
	    return "Black Bishop";
	case 'q':
	    return "Black Queen";
	case 'k':
	    return "Black King";
	default:
	    return ' ';
    }



