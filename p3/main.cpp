//
// Created bint index = 0;y Keelan Matthews on 9/7/2021.
//
#include <iostream>
#include "cauldron.h"
#include <string>
using namespace std;
int main()
{
    cout << "Pot stats: " << endl;
    cauldron* pot = new cauldron("list.txt",10);
    pot->print();
    cout << "Bigger Pot stats: " << endl;
    cauldron biggerPot = pot;
    biggerPot.print();

    cauldron smallPot("list2.txt",10);
    smallPot.addIngredient("Shoe",10);
    smallPot.removeIngredient(1);
    biggerPot = smallPot;
    cout << "Small pot stats: " << endl;
    biggerPot.print();
    cout << "Small pot ingredients: " << endl;
    biggerPot.listIngredients();

    string* list = new string[3];
    list[0] = "pear";
    list[1] = "berry";
    list[2] = "peach";

    biggerPot.distillPotion(biggerPot,list,3);
    cout << "Small pot ingredients, after removal: " << endl;
    biggerPot.listIngredients();

    delete pot;

    /*cauldron* myCauldron = new cauldron("list.txt", 10);

    myCauldron->addIngredient("wow", 5);
    myCauldron->print();
    myCauldron->listIngredients();
    cout << myCauldron->getCurr() << endl;
    cauldron* newCauldron = new cauldron(myCauldron);

    newCauldron->listIngredients();
    cout << newCauldron->getCurr() << endl;

    myCauldron->removeIngredient(2);
    myCauldron->listIngredients();
    cout << myCauldron->getCurr() << endl;

    string* test = new string[2];
    test[0] = "zub";
    test[1] = "apple";
    myCauldron->distillPotion(*myCauldron, test,2);
    myCauldron->listIngredients();
    cout << myCauldron->getCurr() << endl;

    delete myCauldron;
    delete newCauldron;*/

    return 0;
}
