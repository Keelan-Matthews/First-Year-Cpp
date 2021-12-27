#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

class NeuralNetwork
{
private:
    InputLayer* inputLayer;
    int numHiddenLayers;
    HiddenLayer** hiddenLayers;
    OutputLayer* outputLayer;
public:
    NeuralNetwork(std::string filePath);
    ~NeuralNetwork();
    double forward(double* input);
    void printNetwork();
    void clearNetwork();
};
#endif