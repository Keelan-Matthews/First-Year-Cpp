//
// Created by Keelan Matthews on 10/11/2021.
//

#include "locomotive.h"
locomotive::locomotive(char type, double weight, double cost, int powerDrain, int powerGen) : component(type, weight, cost, powerDrain){
    this->powerGen = powerGen;
}

int locomotive::getPowerGen() {
    return this->powerGen;
}

locomotive::~locomotive() {}

double locomotive::calculateEfficiency() {
    return (this->powerGen / this->getPowerDrain()) / this->getCost();
}