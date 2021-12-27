//
// Created by Keelan Matthews on 10/11/2021.
//

#include "cargo.h"
cargo::cargo(char type, double weight, double cost, int powerDrain, int cargoCapacity) : component(type, weight, cost, powerDrain){
    this->cargoCapacity = cargoCapacity;
}

int cargo::getCargoCapacity() {
    return this->cargoCapacity;
}

cargo::~cargo() {}

double cargo::calculateEfficiency() {
    return ( (this->getWeight() + cargoCapacity) / this->getPowerDrain()) / this->getCost();
}