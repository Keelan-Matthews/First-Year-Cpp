#include <iostream>
#include <fstream>
#include <sstream>
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

        //Will run as many iterations as there are lines in values.txt
        while (getline(infile,line))
        {
            stringstream ss(line);
            string strSize;
            //Get size of array
            getline(ss,strSize, ';');

            //Convert size to integer
            stringstream convert(strSize);
            int arrSize;
            convert >> arrSize;

            //Declare dynamic array with size
            int* arrayPtr = new int[arrSize];

            //Populate dynamic array
            int count = 0;
            string item;
            while (getline(ss,item, ','))
            {
                //Convert item to integer
                stringstream convert(item);
                int num;
                convert >> num;

                //Populate array
                *(arrayPtr + count) = num;
                count++;
            }

            //Find highest value
            int highest = arrayPtr[0];

            for (int i = 0; i < arrSize; i++)
                if (arrayPtr[i] > highest)
                    highest = arrayPtr[i];

            //Determine odd or even
            if (highest % 2 != 0)
            {
                for (int j = 0; j < arrSize; j++)
                {
                    arrayPtr[j] *= arrayPtr[j];

                    //Output array delimited by commas
                    if (j == 0)
                        cout << arrayPtr[j];
                    else  
                        cout << "," << arrayPtr[j];
                }
                cout << endl;
            }
            else
            {
                for (int j = 0; j < arrSize; j++)
                {
                    arrayPtr[j] *= highest;

                    //Output array delimited by commas
                    if (j == 0)
                        cout << arrayPtr[j];
                    else  
                        cout << "," << arrayPtr[j];
                }
                cout << endl;
            }

            //Delete values of array
            delete [] arrayPtr;
        }
    }
    return 0;
}