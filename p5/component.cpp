//
// Created by Keelan Matthews on 10/11/2021.
//

#include "component.h"
component::component() {}

component::component(char type, double weight, double cost, int powerDrain) {
    this->type = type;
    this->weight = weight;
    this->cost = cost;
    this->powerDrain = powerDrain;
}

double component::getWeight() {
    return this->weight;
}

double component::getCost() {
    return this->cost;
}

int component::getPowerDrain() {
    return this->powerDrain;
}

char component::getType() {
    return this->type;
}

component::~component() {}

