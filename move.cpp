#include <string>
#include <iostream>
#include "move.h"
#include "notation.h"

// Constructors
Move::Move(int from, int to){
    from_index = from;
    to_index = to;
    Promotion = Piece::None;
}

Move::Move(int from, int to, Piece promotion) {
    from_index = from;
    to_index = to;
    Promotion = promotion;
}

Move::Move(std::string alg_notation) {
    std::string from_square = alg_notation.substr(0,2);
    std::string to_square = alg_notation.substr(2,2);
    std::cout << "FROM: " << from_square << std::endl;
    std::cout << "TO:   " << to_square << std::endl;
    from_index = Notation::toSquare(from_square);
    to_index = Notation::toSquare(to_square); // 'toSquare()' as in from a string, to a board square
    Promotion = alg_notation.length() == 5 ? Notation::toPiece(alg_notation[4]) : Piece::None;
}
