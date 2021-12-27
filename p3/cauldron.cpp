//
// Created by Keelan Matthews on 9/7/2021.
//

#include "cauldron.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

cauldron::cauldron(std::string ingredientList, int maxIngredients) {
    ifstream infile(ingredientList.c_str());
    string line;

    if (!infile)
        cout << "No item list could be found" << endl;
    else {
        //Initialize
        this->maxIngredients = maxIngredients;
        this->numIngredients = 0;
        ingredients = new ingredient*[maxIngredients];

        for (int i = 0; i < maxIngredients; i++)
            ingredients[i] = NULL;

        while (getline(infile, line) && numIngredients < maxIngredients){
            //Retrieve ingredient information
            stringstream ss(line);
            string ingredientName;
            getline(ss,ingredientName,',');
            string dangerRating;
            getline(ss,dangerRating,',');

            int ratingInt;
            stringstream convert(dangerRating);
            convert >> ratingInt;

            ingredients[numIngredients++] = new ingredient(ingredientName,ratingInt);
        }
    }
}

cauldron::cauldron(const cauldron* oldCauldron) {
    numIngredients = oldCauldron->numIngredients;
    maxIngredients = oldCauldron->maxIngredients;
    ingredients = new ingredient*[oldCauldron->maxIngredients];

    for (int i = 0; i < maxIngredients; i++)
        if (oldCauldron->ingredients[i] != NULL)
            ingredients[i] = new ingredient(oldCauldron->getIngredient(i)->getName(),oldCauldron->getIngredient(i)->getDanger());
}

void cauldron::operator=(const cauldron& oldCauldron) {
    if (this->ingredients != NULL)
    {
        for (int i = 0; i < maxIngredients; i++)
            if (ingredients[i] != NULL)
                delete ingredients[i];

        delete[] ingredients;
    }

    numIngredients = oldCauldron.numIngredients;
    maxIngredients = oldCauldron.maxIngredients;

    ingredients = new ingredient*[maxIngredients];

    for (int i = 0; i < maxIngredients; i++)
        if (oldCauldron.getIngredient(i) != NULL)
            ingredients[i] = new ingredient(oldCauldron.getIngredient(i)->getName(),oldCauldron.getIngredient(i)->getDanger());

        else
            ingredients[i] = NULL;
}

void cauldron::print() {
    //Calculate average danger rating
    double total = 0.0;
    for (int i = 0; i < maxIngredients; i++)
        if (ingredients[i] != NULL)
            total += ingredients[i]->getDanger();

    double avg = total/numIngredients;

    //Determine maximum danger rating
    int max = 0;
    for (int i = 0; i < maxIngredients; i++)
        if  (ingredients[i] != NULL)
            if (ingredients[i]->getDanger() > max)
                max = ingredients[i]->getDanger();

    //Determine minimum danger rating
    int min = 10;
    for (int i = 0; i < maxIngredients; i++)
        if  (ingredients[i] != NULL)
            if (ingredients[i]->getDanger() < min)
                min = ingredients[i]->getDanger();

    cout << "Number of Ingredients: " << numIngredients << endl;
    cout << "Average Danger Rating: " << avg << endl;
    cout << "Maximum Danger Rating: " << max << endl;
    cout << "Minimum Danger Rating: " << min << endl;
}

int cauldron::getMax() const {
    return maxIngredients;
}

int cauldron::getCurr() const {
    return numIngredients;
}

ingredient *cauldron::getIngredient(int a) const {
    return ingredients[a];
}

int cauldron::addIngredient(std::string in, int dR) {
    if (numIngredients < maxIngredients) {
        for (int i = 0; i < maxIngredients; i++) {
            if (ingredients[i] == NULL) {
                ingredients[i] = new ingredient(in, dR);
                numIngredients++;
                return i;
            }
        }
    }
    else {
        maxIngredients++;
        ingredient** biggerArray = new ingredient*[maxIngredients];

        for (int i = 0; i < maxIngredients-1; i++)
            if (ingredients[i] != NULL)
                biggerArray[i] = ingredients[i];

        biggerArray[maxIngredients-1] = new ingredient(in, dR);

        
        ingredients = biggerArray;
        biggerArray = NULL;

        numIngredients++;
        return numIngredients;
    }
}

void cauldron::removeIngredient(int in) {
    if (in < maxIngredients && in >= 0)
    {
        if (ingredients[in] != NULL)
        {
            delete ingredients[in];
            ingredients[in] = NULL;
            numIngredients--;
        }
    }
}

void cauldron::distillPotion(cauldron &currCauldron, std::string *list, int numRemove) {
    for (int i = 0; i < numRemove; i++)
        for (int j = 0; j < currCauldron.maxIngredients; j++)
            if (currCauldron.ingredients[j] != NULL)
                if (list[i] == currCauldron.ingredients[j]->getName())
                {
                    removeIngredient(j);
                    break;
                }
}

void cauldron::listIngredients() {
    for (int i = 0; i < maxIngredients; i++)
        if (ingredients[i] != NULL)
            cout << ingredients[i]->getName() << endl;
}

cauldron::~cauldron() {
    for (int i = 0; i < maxIngredients; i++)
        if(ingredients[i] != NULL)
            delete ingredients[i];

    delete[] ingredients;
    ingredients = NULL;
}







