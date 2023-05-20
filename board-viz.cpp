#include <iostream>
#include "board.h"
#include "piece.h"

void print_board(); 

int main() {
    //std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    //std::cout << "Forsyth-Edwards Notation: " << fen << std::endl;
    Board* board1 = new Board(Board::START_POS_FEN);
    //board1 -> setPosition(fen);
    bool running = true;
    while (running) {
    std::cout << ">> Move: ";
    std::string input;
    std::cin >> input;
    std::vector<std::string> moves = board1 -> splitString(input, ' ');
    }
    return 0;
}

void print_board(Board board) {
    std::cout << "   A B C D E F G H " << std::endl;
    std::cout << " ------------------" << std::endl;
    for(int rank = 1; rank < 9; rank++) {
        std::cout << rank << "|";
        for(int file = 0; file < 8; file++) {
	    std::cout << "X";
        }
        std::cout << "\n";
   }
    std::cout << "  -----------------" << std::endl;
}

