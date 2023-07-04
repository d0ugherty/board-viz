#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

#include "board.h"
#include "piece.h"
#include "notation.h"
#include "move.h"

const std::string Board::START_POS_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
/** Constructors **/
Board::Board(const std::string& fenString) : board_state{} {
  setPosition(fenString);
}

Board::Board() : board_state{} {
   for(int i = 0; i  < 64; i++){
       board_state[i] = Piece::None;
   }
}
/*********************************/
/** Indexers **/
Piece Board::operator[](int index) {
    return board_state[index];
}

Piece Board::operator()(int rank, int file) {
    return board_state[rank * 8 + file];
}
/********************************/
// return the current FEN string
std::string Board::getFen() const {
    return fen;
}

/** setup the board state according the given FEN string
    first the FEN string is split up into it's components:
    Piece placement, active color, castling availability, en passant target, halfmove clock, full move number
 
 **/
void Board::setPosition(const std::string& fenString) {	
    std::vector<std::string> tokens = splitString(fenString, ' ');
    // Piece placement
    std::vector<std::string> fen_position = splitString(tokens[0], '/');
    // TO DO: Add error handling here
    int rank = 7;
    for (const std::string& row : fen_position) {
	int file = 0;
        for (char piece : row) {
            if (isdigit(piece)) {
                int empty_squares = piece - '0';
                file += empty_squares;
            } else {
                board_state[rank * 8 + file] = Notation::toPiece(piece);
                file++;
	        }
        }
	    rank--;
    }

    // TO DO: Active Color
    // TO DO: Castling
    // TO DO: En Passant target
}

/**
 * Utility function that splits the string by a given delimiter 
 * and returns a vector<string> of its components
 * 
*/
std::vector<std::string> Board::splitString(const std::string& fenString, char delim) {
    std::vector<std::string> result;
    std::istringstream iss(fenString);
    std::string token;
    while(std::getline(iss, token, delim)) {
        result.push_back(token);
    }
    return result;
}

/**
 * Update the board state according to the given move
 */
void Board::play(Move move){
    Piece moving_piece = board_state[move.from_index];
    if(move.Promotion != Piece::None){
        moving_piece = move.Promotion;
    }
    // move the piece to the destination square
    board_state[move.to_index] = moving_piece;
    board_state[move.from_index] = Piece::None;
    //TO DO: Add castling logic
    //TO DO: Add En Passant Logic

}
