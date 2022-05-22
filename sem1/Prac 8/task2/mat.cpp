#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("values.txt");

    if (!infile)
        cout << "The file does not exist";
    else
    {
        //Declare line input
        string line;
        int lineCount = 0;
        int arrSize[2];
        int** arrPtr = nullptr;
        int ROWS, COLS;
        int row = 0;
    
        //Populate dynamic array
        while (getline(infile,line))
        {
            //Extract array size
            if (lineCount == 0)
            {
                stringstream ss(line);
                string size;
                int sizeCount = 0;

                while (getline(ss,size,','))
                {
                    //Convert size to integer
                    stringstream convert(size);
                    int num;
                    convert >> num;

                    //Store size in an array
                    arrSize[sizeCount] = num;
                    sizeCount++;
                }
                //Declare array and size
                ROWS = arrSize[0];
                COLS = arrSize[1];
                arrPtr = new int*[ROWS];

                for (int count = 0; count < ROWS; count++)
                    arrPtr[count] = new int[COLS];
            }
            else 
            {
                //Populate dynamic array
                for (int col = 0; col < COLS; col++)
                {
                    //Extract single number
                    stringstream ss(line);
                    string item;
                    getline(ss, item, ',');

                    //Convert item to integer
                    stringstream convert(item);
                    int iNum;
                    convert >> iNum;

                    //Populate
                    arrPtr[row][col] = iNum;
                }
                row++;
            }
            lineCount++;
        }

        //Determine number of odd and even numbers
        int odd = 0,
            even = 0,
            largest = arrPtr[0][0],
            smallest = arrPtr[0][0];

        for (int rows = 0; rows < ROWS; rows++)
            for (int cols = 0; cols < COLS; cols++)
            {
                int temp = arrPtr[rows][cols];
                if ((arrPtr[rows][cols]) % 2 == 0)
                    even++;
                else
                    odd++;

                if (arrPtr[rows][cols] > largest)
                    largest = arrPtr[rows][cols];
                else if (arrPtr[rows][cols] < smallest)
                    smallest = arrPtr[rows][cols];
            }

        //Output
        cout << "Count Odd: " << odd << endl;
        cout << "Count Even: " << even << endl;
        cout << "Largest Number: " << largest << endl;
        cout << "Smallest Number: " << smallest << endl;

        //Deallocate memory
        for (int count = 0; count < ROWS; ++count)
	        delete[] arrPtr[count];

        delete[] arrPtr;
    }
    return 0;
}