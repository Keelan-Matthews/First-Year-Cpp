#ifndef HIDDEN_NEURON_H
#define HIDDEN_NEURON_H

class HiddenLayer;
#include "InputLayer.h"
#include <cmath>
#include <iostream>
class HiddenNeuron
{
private:
    double value;
    int numWeights;
    double* weights;
public:
    HiddenNeuron(int numWeights, double* weights);
    ~HiddenNeuron();
    double getValue();
    void setValue(double value);
    void forward(HiddenLayer* prevLayer);
    void forward(InputLayer* inputLayer);
    void activateReLU();
    void activateSigmoid();
};
#endif