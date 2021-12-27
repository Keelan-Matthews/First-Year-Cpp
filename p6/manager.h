//
// Created by Keelan Matthews on 10/18/2021.
//

#ifndef P6_MANAGER_H
#define P6_MANAGER_H

#include "train.h"
template <class T>
class manager {
private:
    train<T>** trains;
    int numTrains;
public:
    manager(string input);
    ~manager();
    void summarise();
    void loadTrain(int i, T load);
};

#include "manager.cpp"

#endif //P6_MANAGER_H
