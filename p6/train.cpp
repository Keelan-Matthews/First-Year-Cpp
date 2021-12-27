//
// Created by Keelan Matthews on 10/18/2021.
//
#ifndef P6_TRAIN_CPP
#define P6_TRAIN_CPP

#include "train.h"
#include "storageEmpty.h"
#include "storageFull.h"
#include <iostream>
#include <string>

template <class T>
train<T>::train() {}

template <class T>
train<T>::~train() {
    cout << "Dispatch Name: " << name << endl;
    cout << "Current Storage: " << currStorage << endl;
    cout << "Storage Max: " << storageCap << endl;
}

template <class T>
train<T>::train(std::string name, T storageCap) {
    this->name = name;
    this->storageCap = storageCap;
    this->currStorage = 0;
}

template <class T>
string train<T>::getName() {
    return name;
}

template <class T>
T train<T>::getCargoCap() {
    return storageCap;
}

template <class T>
T train<T>::getCurrCargo() {
    return currStorage;
}

template <class T>
void train<T>::loadCargo(T cargo) {
    if (cargo + currStorage > storageCap)
        throw storageFull();

    currStorage += cargo;
    cout << "Capacity: " << currStorage << endl;
}

template <class T>
void train<T>::unloadCargo(T cargo) {
    if (cargo > currStorage)
        throw storageEmpty();

    currStorage -= cargo;
    cout << "Capacity: " << currStorage << endl;
}

#endif //P6_TRAIN_CPP