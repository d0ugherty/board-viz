#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
#include "move.h"
#include "piece.h"

class Board {
    public:
		static const std::string START_POS_FEN;
		Piece board_state[64];
		

		//TO DO: Add Castling Rights
		//TO DO: Add En Passant Target
		
		// indexers made by operator overloading '[]'
		Piece operator[](int index);
		Piece operator()(int rank, int file);
		// constructors
		Board();
			Board(const std::string& fen);
		/**member functions**/
		void play(Move move);
		void setPosition(const std::string& fen);
        std::string getFen() const;
        std::vector<std::string> splitString(const std::string& fen, char delim);
    private:
        std::string fen;

};

#endif
