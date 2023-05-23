#include <iostream>
#include "board.h"
#include "piece.h"
#include "notation.h"
#include "move.h"

void printBoard(Board& board);
void printPiece(Piece piece);
void playMove(Board& board, std::string moveNot);

int main() {
    Board board1(Board::START_POS_FEN);
    printBoard(board1); 
    bool running = true;
    while (running) {
	std::cout << "\n>> Move: ";
	std::string input;
	std::cin >> input;
	std::vector<std::string> moves = board1.splitString(input, ' ');
	for(std::string move : moves) {
	    playMove(board1, move);
	    printBoard(board1);
	    std::cout<< ">>> Last Move: " << move << "\n";
	}
    }
    return 0;
}
/** Updates the board state to the most recent move **/
 void playMove(Board& board, std::string moveNot) {
    Move move  = Notation::toMove(moveNot);
    board.play(move);
}


/** Takes a board object as input and iterates through it 
 *  to print out the current move or state of the game
 */
void printBoard(Board& board) {
    std::cout << "	              BLACK	    \n";
    std::cout << "\n" << "   A  B  C  D  E  F  G  H \n";
    std::cout << 	 " --------------------------\n";
    for (int rank = 7; rank >= 0; rank--) {
        std::cout << rank + 1 << "|";
        for (int file = 0; file < 8; file++) {
            Piece piece = board[rank * 8 + file];
	    printPiece(piece);
        }
        std::cout << "\n";
    }
    std::cout << 	 "---------------------------\n";
    std::cout <<	 "	      WHITE	     ";	
}

/* Prints the char representation of the Piece object
 */
void printPiece(Piece piece){
    std::cout << " " << Notation::toChar(piece);
    std::cout << ' ';
}


