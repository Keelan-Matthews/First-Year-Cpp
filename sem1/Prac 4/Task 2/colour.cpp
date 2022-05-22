#include <iostream>
#include <string>
using namespace std;

int main()
{
    string colour;
    int number;

    for (int i=0; i<3; i++)
    {
        cout << "Input a colour: ";
        cin >> colour;

        //If colour is valid
        if ((colour == "red") || (colour == "orange") || (colour == "yellow") || (colour == "green") || (colour== "blue") || (colour == "purple"))
        {
                //Input
                cout << "Input a number: ";
                cin >> number;

                //Test primary/secondary
                if ((colour == "red") || (colour == "yellow") || (colour == "blue"))
                {
                    switch (number)
                    {
                        case 1 : cout << "yellow,orange,red,purple,blue,green" << endl;
                                 break;
                        case 2 : cout << colour << endl;
                                 break;
                        case 3 : switch (colour.at(0))
                                 {
                                     case 'r' : cout << "blue" << endl;
                                                break;
                                     case 'y' : cout << "red" << endl;
                                                break;
                                     case 'b' : cout << "yellow" << endl;
                                 }
                    }
                }
                else
                {
                    switch (number)
                    {
                        case 1 : cout << "green,orange,purple" << endl;
                                 break;
                        case 2 : cout << colour << "!" << endl;
                                 break;
                        case 3 : switch (colour.at(0))
                                 {
                                     case 'o' : cout << "purple" << endl;
                                                break;
                                     case 'g' : cout << "orange" << endl;
                                                break;
                                     case 'p' : cout << "green" << endl;   
                                 }
                    }
                }
        }
        else
            cout << "Colour not found" << endl;
    }
    return 0;
}