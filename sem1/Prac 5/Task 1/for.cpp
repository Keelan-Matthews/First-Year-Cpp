#include <iostream>
using namespace std;

int main()
{
    char symbol;
    int num;

    for (int i=1; i<=2; i++)
    {
        cout << "Enter a pair: ";
        cin >> symbol;
        cin.ignore();
        cin >> num;

        if ((symbol != '*') && (symbol != '+') && (symbol != '-'))
        {
            cout << "Result : 0" << endl;
        }
        else
        {
            int total=num;

            for (int i=1; i <= num; i++ )
            {
                switch (symbol)
                {
                    case '+': 
                        total += num;
                        break;
                    case '-': 
                        total -= num;
                        break;
                    case '*': 
                        total *= num;
                }  

            }
            cout << "Result: " << total << endl;
        }
    }
    return 0;
}