#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//Function Prototype
string linSearch(double [], double []);

int main()
{
    double arr[10] = {0}, search[8] = {0};
    ifstream infile("input.txt");
    string line;

    if (!infile)
        cout << "The file does not exist" << endl;
    else
    {
        //Populate arrays
        int count = 1;
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

                if (count == 1)
                    arr[index] = num;
                else
                    search[index] = num;

                index++;
            }   

            count++;
        }

        //Use function
        string display = linSearch(arr,search), output;
        stringstream ss(display);
        while (getline(ss,output, ','))
            cout << output << endl;
    }
    return 0;
}

string linSearch(double arr[10], double search[8])
{
    string result = "";

    for (int searchNum = 0; searchNum < 8; searchNum++)
    {
        int index = -1;
        bool flag = false;

        while ((index < 10) && (flag == false))
        {
            index++;

            if (search[searchNum] == arr[index])
                flag = true;
        }

        //Convert index to string
        string stringIndex;
        stringstream ss;
        ss << index;
        ss >> stringIndex;

        if (flag == false)
            stringIndex = "NA";

        if (result == "")
            result = stringIndex;
        else    
            result = result + "," + stringIndex;
    }

    return result;
}