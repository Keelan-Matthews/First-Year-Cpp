//
// Created by Keelan Matthews on 9/7/2021.
//

#ifndef CAULDRON_H
#define CAULDRON_H
#include <string>
#include "ingredient.h"
class cauldron
{
private:
    ingredient** ingredients;
    int numIngredients;
    int maxIngredients;
public:
    cauldron(std::string ingredientList, int maxIngredients);
    cauldron(const cauldron* oldCauldron);
    ~cauldron();
    void operator=(const cauldron& oldCauldron);
    void print();
    int getMax() const;
    int getCurr() const;
    ingredient* getIngredient(int a) const;
    int addIngredient(std::string in, int dR);
    void removeIngredient(int in);
    void distillPotion(cauldron& currCauldron, std::string* list, int numRemove);
    void listIngredients();
};
#endif //CAULDRON_H
