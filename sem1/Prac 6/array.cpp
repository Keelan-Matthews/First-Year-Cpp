#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int bins[5] = {0,0,0,0,0};
    string line;
    ifstream infile("values.txt");

    if (!infile)
        cout << "The file does not exist\n";
    else
        {
            while(getline(infile,line))
            {
                stringstream ss(line);
                for (int count=0; count < 5; count++)
                {
                    string number;
                    getline(ss, number, ',');
                    stringstream sstemp;
                        int num;
                        sstemp << number;
                        sstemp >> num;
                    bins[count] += num;
                }               
            }
            infile.close();
            for (int count=0; count < 5; count++)
                cout << bins[count] << endl;
        }

    return 0;
}