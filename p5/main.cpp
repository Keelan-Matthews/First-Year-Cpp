#include <iostream>
#include "train.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    train chooChoo(4);

    cout << "=====Insert Cargo Car=====" << endl;
    chooChoo.addComponent("c,12.3,300000.50,10,10");
    cout << chooChoo << endl;

    cout << "=====Insert Passenger Car=====" << endl;
    chooChoo.addComponent("p,10.1,450000.30,4,5");
    cout << chooChoo << endl;

    cout << "=====Insert Locomotive=====" << endl;
    chooChoo.addComponent("l,56.6,10000.40,11,12");
    cout << chooChoo << endl;

    chooChoo.removeComponent();

    cout << chooChoo << endl;
    return 0;
}
