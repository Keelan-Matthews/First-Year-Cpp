//
// Created by Keelan Matthews on 10/11/2021.
//

#ifndef P5_COMPONENT_H
#define P5_COMPONENT_H


class component {
private:
    double weight;
    int powerDrain;
    double cost;
    char type;
public:
    component();
    component(char type, double weight, double cost, int powerDrain);
    double getWeight();
    double getCost();
    int getPowerDrain();
    char getType();
    virtual ~component();
    virtual double calculateEfficiency() = 0;
};


#endif //P5_COMPONENT_H
