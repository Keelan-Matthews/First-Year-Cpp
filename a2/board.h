//
// Created by Keelan Matthews on 9/27/2021.
//

#ifndef A2_BOARD_H
#define A2_BOARD_H
#include "piece.h"

class board
{
private:
    int numWhitePieces;
    int numBlackPieces;
    piece** whitePieces;
    piece** blackPieces;
    string** chessboard;
    string move;
    char sideToMove;
    board& operator++();
public:
    board(string pieceList);
    ~board();
    board& operator--();
    bool checkIfPieceHasCheck(string pieceType, int xPos, int yPos, int kingX, int kingY);
};
#endif //A2_BOARD_H
