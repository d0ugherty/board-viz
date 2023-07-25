#include <iostream>
#include "board.h"
#include "piece.h"
#include "notation.h"
#include "move.h"

#define RESET_COLOR "\033[0m" //macro to reset color back to default
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

void printBoard(Board& board);
void printPiece(Piece piece);
void playMove(Board& board, std::string moveNot);

int main() {
    // TO-DO: Make START_POS_FEN an argument from a file or command line entry
    Board board1(Board::START_POS_FEN);
    
    printBoard(board1);
    
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << "\n>> Move <<\n";
        std::string input;
        std::cin >> input;
        std::vector<std::string> moves = board1.splitString(input, ' ');
        
            for(std::string move : moves) {
                playMove(board1, move);
                printBoard(board1);
                std::cout<< "\n>>> Last Move: " << move << "\n";
            }
        
        if (std::cin.eof()) {
            std::cout << "End of game log..." << std::endl;
            break;
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
    std::cout << "	   BLACK	    \n";
    std::cout << "   A  B  C  D  E  F  G  H \n";
    std::cout << "--------------------------\n";
    
    for (int rank = 7; rank >= 0; rank--) {
        
        std::cout << rank + 1 << "|";
            
        for (int file = 0; file < 8; file++) {
                Piece piece = board[rank * 8 + file];
                printPiece(piece);
            }
        std::cout << "\n";
    }

    std::cout <<"---------------------------\n";
    std::cout <<"	   WHITE	    \n";	
}

/* Prints the char representation of the Piece object
 */
void printPiece(Piece piece){
    if (piece <= 6) {
        std::cout << ' ' << YELLOW <<  Notation::toChar(piece) << RESET_COLOR << ' ';
    } else {
        std::cout << ' ' << BLUE << Notation::toChar(piece) << RESET_COLOR << ' ';
    }   
}


