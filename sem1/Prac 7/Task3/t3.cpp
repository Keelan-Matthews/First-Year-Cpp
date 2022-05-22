#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//Function Prototype
string bubSort(double []);

int main()
{
    ifstream infile("input.txt");
    string line;
    double arr[8] = {0};

    if (!infile)
        cout << "The file does not exist" << endl;
    else
    {
        //Populate arrays
        while (getline(infile,line))
        {
            stringstream ss(line);
            string number;
            int index = 0;

            while (getline(ss, number, ','))
            {
                stringstream convert(number);
                double num;
                convert >> num;

                arr[index] = num;
                index++;
            }   

            cout << bubSort(arr) << endl;
        }
    }
    return 0;
}

string bubSort(double arr[8])
{
    double sorted[8] = {0};
    bool flag = true;

    for (int index = 0; index < 8; index++)
        sorted[index] = arr[index];

    while (flag == true)
    {
        flag = false;
        for (int index = 7; index > 0; index--)
        {
            double temp;
            
            if (sorted[index] < sorted[index-1])
            {
                temp = sorted[index];
                sorted[index] = sorted[index-1];
                sorted[index-1] = temp;
                flag = true;
            }
        }
    }

    string result = "";
    for (double val : sorted)
    {
        stringstream ss;
        string number;
        ss << val;
        ss >> number;

        if (result == "")
            result = number;
        else    
            result = result + "," + number;
    }

    return result;
}