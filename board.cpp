#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

#include "board.h"
#include "piece.h"
#include "notation.h"

const std::string Board::START_POS_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

Board::Board(const std::string& fen) {
    setPosition(fen);
}



// return the current FEN string
std::string Board::getFen() const {
    return fen;
}

/***setup the board state according the given FEN string
    first the FEN string is split up into it's components:
    Piece placement, active color, castling availability, en passant target, halfmove clock, full move number


 */
void Board::setPosition(const std::string& fen) {
    Notation* notation;
    Piece* board_state = new Piece[64];	
    std::vector<std::string> tokens = splitString(fen, ' ');

    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    // Piece placement
    std::vector<std::string> fen_position = splitString(tokens[0], '/');
    std::cout << fen_position[0] << std::endl;

    // Add error handling here
    int rank = 7;
    for (const std::string& row : fen_position) {
        int file = 0;
        for (char piece : row) {
            if (isdigit(piece)) {
                int empty_squares = piece - '0';
                file += empty_squares;
            } else {
		board_state[rank * 8 + file] = notation -> toPiece(piece);
		file++;
	    }
        }
	rank--;
    }

    // TO DO: Active Color
    // TO DO: Castling
    // TO DO: En Passant target
    delete notation;
    delete[] board_state; // Don't forget to deallocate the dynamically allocated array
}

/**
 * Utility function that splits the string by a given delimiter 
 * and returns a vector<string> of its components
 * 
*/
std::vector<std::string> Board::splitString(const std::string& fen, char delim) {
    std::vector<std::string> result;
    std::istringstream iss(fen);
    std::string token;
    while(std::getline(iss, token, delim)) {
        result.push_back(token);
    }
    return result;
}
