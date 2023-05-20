#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
#include "piece.h"

class Board {
    public:
	static const std::string START_POS_FEN;
	Piece* board_state = new Piece[64];
	//TO DO: Add Active Color
	//TO DO: Add Castling Rights
	//TO DO: Add En Passant Target
	
	//indexers
	Piece operator[](int index){
	    return board_state[index];
	};

	Piece operator()(int rank, int file) {
	    return board_state[rank * 8 + file];
	};

        Board(const std::string& fen); // Constructor
	void setPosition(const std::string& fen);
        std::string getFen() const;
        std::vector<std::string> splitString(const std::string& fen, char delim);

        void printBoard(Board board);
    private:
        std::string fen;

};

#endif
