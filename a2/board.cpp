//
// Created by Keelan Matthews on 9/27/2021.
//

#include "board.h"
#include <fstream>
#include <iostream>
#include <sstream>

board::board(string pieceList)
{
    ifstream infile(pieceList.c_str());

    if (!infile)
        cout << "the text file does not exist" << endl;
    else
    {
        //Initialization
        numBlackPieces = 0;
        numWhitePieces = 0;
        whitePieces = new piece*[16];
        blackPieces = new piece*[16];

        for (int i = 0; i < 16; i++)
        {
            whitePieces[i] = NULL;
            blackPieces[i] = NULL;
        }

        chessboard = new string*[8];
        for (int i = 0; i < 8; i++)
            chessboard[i] = new string[8];

        for (int row = 0; row < 8; row++)
            for (int col = 0; col < 8; col++)
                chessboard[row][col] = "-";

        //Get starting side
        string side;
        getline(infile,side);
        stringstream convert(side);
        convert >> sideToMove;

        //Get move to be carried out
        getline(infile,move);

        //Extract piece information
        string line;
        while (getline(infile, line))
        {

            //Extract information from each line
            string pieceType;
            char side;
            int xPos;
            int yPos;

            string data;
            int count = 0;
            stringstream ss(line);
            while (getline(ss,data,','))
            {
                switch (count)
                {
                    case 0 :
                    {
                        if (data == "b")
                            side = 'b';
                        else if (data == "w")
                            side = 'w';
                    }
                        break;

                    case 1 :
                        pieceType = data;
                        break;

                    case 2 :
                    {
                        stringstream convert(data);
                        convert >> xPos;
                    }
                        break;

                    case 3 :
                    {
                        stringstream convert2(data);
                        convert2 >> yPos;
                    }
                }
                count++;
            }

            //Populate piece for each line
            if (side == 'b')
                blackPieces[numBlackPieces++] = new piece(pieceType, side, xPos, yPos);
            else
                whitePieces[numWhitePieces++] = new piece(pieceType, side, xPos, yPos);
        }

        //Populate chess board with pieces
        for (int i = 0; i < numWhitePieces; i++)
        {
            int x = whitePieces[i]->getX();
            int y = whitePieces[i]->getY();
            string type = whitePieces[i]->getPieceType();
            string typeLetter;

            if (type == "king")
                typeLetter = "K";
            else
            {
                type.erase(1,type.length());
                typeLetter = type;
            }

            for (int row = 0; row < 8; row++)
                for (int col = 0; col < 8; col++)
                    if (row == x && col == y)
                        chessboard[x][y] = whitePieces[i]->getSide() + typeLetter;
        }

        for (int i = 0; i < numBlackPieces; i++)
        {
            int x = blackPieces[i]->getX();
            int y = blackPieces[i]->getY();
            string type = blackPieces[i]->getPieceType();
            string typeLetter;

            if (type == "king")
                typeLetter = "K";
            else
            {
                type.erase(1,type.length());
                typeLetter = type;
            }

            for (int row = 0; row < 8; row++)
                for (int col = 0; col < 8; col++)
                    if (row == x && col == y)
                        chessboard[x][y] = blackPieces[i]->getSide() + typeLetter;
        }
    }
}

board::~board()
{
    int total = 0;

    for (int i = 0; i < 16; i++)
        if (blackPieces[i] != NULL)
        {
            delete blackPieces[i];
            total++;
        }
    delete blackPieces;

    for (int i = 0; i < 16; i++)
        if (whitePieces[i] != NULL)
        {
            delete whitePieces[i];
            total++;
        }
    delete whitePieces;

    delete chessboard;

    cout << "Num Pieces Removed: " << total << endl;
}

board &board::operator++()
{
    stringstream ss(move);
    string num;
    int coords[4];
    bool found = false;

    for (int i = 0; i < 4; i++)
    {
        getline(ss,num,',');
        stringstream(num) >> coords[i];
    }

    chessboard[coords[2]][coords[3]] = chessboard[coords[0]][coords[1]];
    chessboard[coords[0]][coords[1]] = "-";

    //Set coordinates
    int whiteCount = 0;
    while (whiteCount < numWhitePieces && !found)
    {
        int x = whitePieces[whiteCount]->getX();
        int y = whitePieces[whiteCount]->getY();

        if (x == coords[0] && y == coords[1])
        {
            whitePieces[whiteCount]->setX(coords[2]);
            whitePieces[whiteCount]->setY(coords[3]);

            found = true;
        }
        whiteCount++;
    }

    int blackCount = 0;
    while (blackCount < numBlackPieces && !found)
    {
        int x = blackPieces[blackCount]->getX();
        int y = blackPieces[blackCount]->getY();

        if (x == coords[0] && y == coords[1])
        {
            blackPieces[blackCount]->setX(coords[2]);
            blackPieces[blackCount]->setY(coords[3]);
            found = true;
        }
        blackCount++;
    }

    return *this;
}

bool board::checkIfPieceHasCheck(string pieceType, int xPos, int yPos, int kingX, int kingY)
{
    if (xPos == kingX && yPos == kingY)
        return false;

    //Check each piece
    switch (pieceType[0])
    {
        //Pawn check
        case 'p' :
        {
            if (xPos - 1 == kingX)
                if (yPos + 1 == kingY || yPos - 1 == kingY)
                    return true;

            return false;
        }

        //Rook check
        case 'r' :
        {
            if (xPos == kingX || yPos == kingY)
                return true;

            return false;
        }

        //Knight check
        case 'k' :
        {
            if(xPos == kingX || yPos == kingY)
                return false;

            int x = xPos - kingX;
            int y = yPos - kingY;

            if (x < 0)
                x *=-1;

            if (y < 0)
                y *= -1;

            if (x + y == 3)
                return true;

            return false;
        }

        //Bishop check
        case 'b' :
        {
            double slope = (yPos - kingY) / double(xPos - kingX);

            if (slope == 1.0 || slope == -1.0)
                return true;

            return false;
        }

        //Queen check
        case 'q' :
        {
            //Bishop determining
            double slope = (yPos - kingY) / double(xPos - kingX);

            if (slope == 1.0 || slope == -1.0)
                return true;

            //Rook determining
            if (xPos == kingX || yPos == kingY)
                return true;

            return false;
        }
    }
    return false;
}

board &board::operator--()
{
    ++*this;
    int xKing;
    int yKing;
    bool checkmate = false;
    switch (sideToMove)
    {
        case 'w' :
        {
            //Find coordinates of opposing king
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (chessboard[i][j] == "bK")
                    {
                        xKing = i;
                        yKing = j;
                    }
                }
            }

            for (int kingRow = 0; kingRow < 3; kingRow++)
                for (int kingCol = 0; kingCol < 3; kingCol++)
                {
                    int areaX = kingRow-1;
                    int areaY = kingCol-1;

                    if (areaX != 0 && areaY != 0)
                        for (int i =0; i < 8; i++)
                            for (int j = 0; j < 8; j++)
                                if (chessboard[i][j] != "-" && chessboard[i][j][0] != 'b')
                                    if (!checkIfPieceHasCheck(chessboard[i][j].substr(1), i, j, areaX, areaY))
                                        checkmate = true;
                }

            if (!checkmate)
                cout << "Failed: No Checkmate of b King" << endl;
            else
                cout << "Success: Checkmate of b King at [" << xKing << "," << yKing << "]" << endl;

            return *this;
        }

        case 'b' :
        {
            //Find coordinates of opposing king
            for (int i = 0; i < 8; i++)
                for (int j = 0; j < 8; j++)
                    if (chessboard[i][j] == "wK")
                    {
                        xKing = i;
                        yKing = j;
                    }

            for (int kingRow = 0; kingRow < 3; kingRow++)
                for (int kingCol = 0; kingCol < 3; kingCol++)
                {
                    int areaX = kingRow-1;
                    int areaY = kingCol-1;

                    if (areaX != 0 && areaY != 0)
                        for (int i =0; i < 8; i++)
                            for (int j = 0; j < 8; j++)
                                if (chessboard[i][j] != "-" && chessboard[i][j][0] != 'w')
                                    if (!checkIfPieceHasCheck(chessboard[i][j].substr(1), i, j, areaX, areaY))
                                        checkmate = true;
                }

            if (!checkmate)
                cout << "Failed: No Checkmate of w King" << endl;
            else
                cout << "Success: Checkmate of w King at [" << xKing << "," << yKing << "]" << endl;

            return *this;
        }
    }

    return *this;
}