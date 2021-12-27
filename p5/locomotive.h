//
// Created by Keelan Matthews on 10/11/2021.
//

#ifndef P5_LOCOMOTIVE_H
#define P5_LOCOMOTIVE_H
#include "component.h"

class locomotive : public component {
private:
    int powerGen;
public:
    locomotive(char type, double weight, double cost, int powerDrain, int powerGen);
    int getPowerGen();
    virtual ~locomotive();
    virtual double calculateEfficiency();
};


#endif //P5_LOCOMOTIVE_H
