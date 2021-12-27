//
// Created by Keelan Matthews on 9/25/2021.
//

#include "piece.h"
#include <iostream>
#include <sstream>
piece::piece() {}

piece::piece(piece* newPiece)
{
    this->pieceType = newPiece->getPieceType();
    this->side = newPiece->getSide();
    this->xPos = newPiece->getX();
    this->yPos = newPiece->getY();
}

piece::piece(string pType, char side, int x, int y)
{
    this->pieceType = pType;
    this->side = side;
    this->xPos = x;
    this->yPos = y;
}

piece::~piece()
{
    cout << "(" << xPos << "," << yPos << ") " << side << " " << pieceType << " deleted" << endl;
}

char piece::getSide()
{
    return side;
}

string piece::getPieceType()
{
    return pieceType;
}

int piece::getX()
{
    return xPos;
}

int piece::getY()
{
    return yPos;
}

void piece::setX(int x)
{
    this->xPos = x;
}

void piece::setY(int y)
{
    this->yPos = y;
}

void piece::operator[](int pos)
{
    switch (pos)
    {
        case 0 :
            cout << "x coord: " << xPos << endl;
            break;
        case 1 :
            cout << "y coord: " << yPos << endl;
            break;
        default :
            cout << "Invalid Index" << endl;
    }
}

int convert(string coord)
{
    int iCoord;
    stringstream convert(coord);
    convert >> iCoord;
    return iCoord;
}

piece& piece::operator+(string move)
{
    string x;
    string y;
    stringstream ss(move);

    getline(ss, x, ',');
    move.erase(0,move.find(',')+1);
    y = move;

    if ((convert(x) >= 0 && convert(x) <= 7) && (convert(y) >= 0 && convert(y) <= 7))
    {
        this->xPos = convert(x);
        this->yPos = convert(y);
    }

    return *this;
}

ostream& operator<<(ostream& output, const piece& t)
{
    output << t.side << " " << t.pieceType << " at [" << t.xPos << "," << t.yPos << "]" << endl;
    return output;
}