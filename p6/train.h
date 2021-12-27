//
// Created by Keelan Matthews on 10/18/2021.
//

#ifndef P6_TRAIN_H
#define P6_TRAIN_H
#include <string>

using namespace std;

template <class T>
class train {
private:
    T currStorage;
    T storageCap;
    string name;
public:
    train();
    ~train();
    train(string name, T storageCap);
    string getName();
    T getCargoCap();
    T getCurrCargo();
    void loadCargo(T cargo);
    void unloadCargo(T cargo);
};
#include "train.cpp"

#endif //P6_TRAIN_H
