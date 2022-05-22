#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//Function Prototypes
string echo(string);
string echo(string, int);

int main()
{
    ifstream infile("values.txt");

    if (!infile)
        cout << "The file does not exist\n";
    else
        {
            string line;
            int count = 0;
            while (getline(infile, line))
            {
                cout << echo(line) << endl;
                cout << echo(line,count) << endl;
                count++;
            }
        }
    return 0;
}

string echo(string input="echo")
{
    return input;
}

string echo(string input, int count)
{   
    if ((count == 0) || (count % 2 == 0))    
        return input + to_string(count);
    else
        return to_string(count) + input;       
}