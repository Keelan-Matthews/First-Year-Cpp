#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int convert(string input)
{
    stringstream convert;
    int x;

    convert << input;
    convert >> x;
    convert.str("");
    convert.clear();

    return x;
}

//Calculate the number of rows in the file
int size_count(const string filename)
{
    ifstream infile(filename);
    string line;
    int count = 0;

    while (getline(infile,line))
        count++;

    return count;      
}

//Calculate the number of columns in the current line of the file
int col_count(const string filename, int row)
{
    ifstream infile(filename);
    string line;
    int cols = 0;
    int rowcounter = 0;

    while (getline(infile,line))
    {
        //Only execute when the row number matches
        if (rowcounter == row)
        {
            stringstream ss(line);
            string column;

            while (getline(ss,column,','))
                cols++;
        }
        rowcounter++;
    } 
    return cols;       
}

int main()
{   
    //Populate array
    ifstream infile("data.txt");

    if (!infile)
        cout << "The file does not exist";
    else
    {
        string line;
        int row_size = 0, column_size = 0;
        row_size = size_count("data.txt");

        string*** array = new string**[row_size];
        int colArray[row_size] = {};

        int row = 0;
        while (getline(infile,line))
        {
            column_size = col_count("data.txt",row);
            colArray[row] = column_size;

            array[row] = new string*[column_size];

            int col = 0;
            stringstream ss(line);
            string input;
            while (getline(ss,input,','))
            {
                array[row][col] = new string(input);                
                col++;
            }
            row++;
        }

        string* final = new string[row_size];

        for (int rows = 0; rows < row_size; rows++)
        {
            for (int cols = 0; cols < colArray[rows]; cols++)
            {
                if (cols == 0)
                    final[rows] += *array[rows][cols];
                else
                    final[rows] += "," + *array[rows][cols];
            }
        }
        
        infile.clear();
        infile.seekg(0);
        string input2;
        int* id = new int[row_size];
        int idCounter = 0;
        while (getline(infile,input2))
        {
            stringstream ss(input2);
            string input;
 
            getline(ss, input,',');

            id[idCounter] = convert(input);
            idCounter++;
        }

        int temp = 0;
        string sTemp = "";
        for (int first = 0; first < row_size; first++)
        {
            for (int second = first+1; second < row_size; second++)
            {
                if (id[first] > id[second])
                {
                    temp = id[first];
                    id[first] = id[second];
                    id[second] = temp;

                    sTemp = final[first];
                    final[first] = final[second];
                    final[second] = sTemp;
                }
            }
        }

        //Output array
        for (int rows = 0; rows < row_size; rows++)
        {
            cout << final[rows] << endl;
        }

        //Deallocate array
        for (int rows = 0; rows < row_size; rows++)
            delete[] array[rows];       

        delete[] array;
        delete[] id;
        delete[] final;
        infile.close();
    }
    return 0;
}