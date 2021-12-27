//
// Created by Keelan Matthews on 9/25/2021.
//

#ifndef A2_PIECE_H
#define A2_PIECE_H
#include <string>
using namespace std;

class piece;
ostream& operator<<(ostream& output, const piece& t);

class piece
{
private:
    string pieceType;
    char side;
    int xPos;
    int yPos;
public:
    piece();
    piece(piece* newPiece);
    piece(string pType, char side, int x, int y);
    ~piece();
    char getSide();
    string getPieceType();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    friend ostream& operator<<(ostream& output, const piece& t);
    void operator[](int pos);
    piece& operator+(string move);
};
#endif //A2_PIECE_H
