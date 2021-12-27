//
// Created by Keelan Matthews on 10/11/2021.
//

#ifndef P5_CARGO_H
#define P5_CARGO_H
#include "component.h"

class cargo : public component {
private:
    int cargoCapacity;
public:
    cargo(char type, double weight, double cost, int powerDrain, int cargoCapacity);
    int getCargoCapacity();
    virtual ~cargo();
    virtual double calculateEfficiency();
};


#endif //P5_CARGO_H
