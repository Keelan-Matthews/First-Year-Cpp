//
// Created by Keelan Matthews on 9/7/2021.
//

#include "ingredient.h"

ingredient::ingredient(std::string name, int dangerRating) {
    this->name = name;
    this->dangerRating = dangerRating;
}

ingredient::ingredient(const ingredient *newIngredient) {
    name = newIngredient->name;
    dangerRating = newIngredient->dangerRating;
}

ingredient::ingredient(const ingredient &newIngredient) {
    name = newIngredient.name;
    dangerRating = newIngredient.dangerRating;
}

int ingredient::getDanger() {
    return dangerRating;
}

std::string ingredient::getName() {
    return name;
}

ingredient::~ingredient() {

}


