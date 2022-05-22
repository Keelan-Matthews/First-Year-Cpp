#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string number, filename;
    int index;
    vector <int> list;

    for (int i=1; i<=2; i++)
    {
        if (i==1)
            filename = "lines.txt";
        else
        {
            filename = "lines2.txt";
            list.clear();
        }

        ifstream infile (filename);
        if (infile)
        {
            //Writing to the vector
            index = 0;
            while (getline(infile, number))
            {
                if (number.find("stop") != string::npos)
                {
                    cout << "File reading stopped\n";
                    break;
                }
                else
                {
                    if (index == 0)
                    {
                        stringstream ss;
                        int num;
                        ss << number;
                        ss >> num;
                        cout << num << endl;
                        list.push_back(num);
                        
                    }
                    else
                    {
                        stringstream ss;
                        int num;
                        ss << number;
                        ss >> num;
                        list.push_back(num);
                        cout << (num + list[index-1]) << endl;
                    }    
                }
                index += 1;
            }
            infile.close();
        } 
        else
            cout << "File does not exist\n";
    }
    return 0;
}