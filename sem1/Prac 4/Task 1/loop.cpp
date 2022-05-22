#include <iostream>
using namespace std;

int main()
{
    int number, counter=0, odd=0;

    cout << "Enter an int: ";
    cin >> number;

    while (counter <= number)
    {
        if (counter % 2 != 0)
            odd += 1;
        counter += 1;
    }
    cout << "Number of Odds: " << odd << endl;
    return 0;
}