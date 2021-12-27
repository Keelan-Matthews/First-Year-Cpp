//
// Created by Keelan Matthews on 10/18/2021.
//
#ifndef P6_MANAGER_CPP
#define P6_MANAGER_CPP

#include "manager.h"
#include <sstream>
#include <fstream>
#include <iostream>

template <class T>
manager<T>::manager(string input) {
    ifstream infile(input.c_str());

    //Retrieve number of trains
    string num;
    getline(infile, num);
    stringstream convert(num);
    convert >> numTrains;

    //Retrieve train data
    trains = new train<T>*[numTrains];
    for (int i = 0; i < numTrains; i++)
        trains[i] = NULL;

    string line;
    int count = 0;
    while (getline(infile,line))
    {
        string trainName, max;
        stringstream ss(line);
        getline(ss,trainName,',');
        getline(ss,max,',');

        int cargoMax;
        stringstream convert1(max);
        convert1 >> cargoMax;

        trains[count++] = new train<T>(trainName,cargoMax);
    }

    infile.close();
}

template <class T>
manager<T>::~manager() {
    for (int i = 0; i < numTrains; i++)
        if (trains[i] != NULL)
            delete trains[i];

    delete[] trains;
}

template <class T>
void manager<T>::summarise() {
    int total = 0;

    for (int i = 0; i < numTrains; i++)
            total += trains[i]->getCargoCap();

    cout << "Total Current Storage: " << total << endl;
}

template <class T>
void manager<T>::loadTrain(int i, T load) {
    if (i < numTrains && i > -1) {
        trains[i]->loadCargo(load);
    }
}

#endif //P6_MANAGER_CPP