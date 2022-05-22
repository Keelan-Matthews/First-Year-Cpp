#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    const int ROWS = 4, COLS = 4;
    int array[ROWS][COLS], average, total = 0;
    ifstream infile("input.txt");
    string line;

    if (!infile)
        cout << "The file does not exist";
    else
    {
        int row = 0;
        while (getline(infile,line))
        {
            stringstream ss(line);
            for (int col = 0; col < COLS; col++)
            {
                //Extract single number
                string number;
                getline(ss, number, ',');

                //Convert number to integer
                stringstream stoi(number);
                int iNum;
                stoi >> iNum;

                //Populate column
                array[row][col] = iNum;
            }
            row++;
        }

        //Calculate the total per row
        for (int row = 0; row < ROWS; row++)
        {
            int totalRow = 0;
            for (int col = 0; col < COLS; col++)
            {
                totalRow += array[row][col];
                total += array[row][col];
            }

            cout << "Row Total " << row+1 << ": " << totalRow << endl;
        }

        //Calculate the total per column
        for (int col = 0; col < COLS; col++)
        {
            int totalColumn = 0;
            for (int row = 0; row < ROWS; row++)
                totalColumn += array[row][col];

            cout << "Col Total " << col+1 << ": " << totalColumn << endl;
        }

        //Calculate the average
        average = total / (ROWS*COLS);
        cout << "Array Average: " << average << endl;
    }
    
    return 0;
}