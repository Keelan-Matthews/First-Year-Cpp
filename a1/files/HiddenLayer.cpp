#include "HiddenLayer.h"
#include <iostream>
#include <string>
using namespace std;

HiddenLayer::HiddenLayer(int numNeurons, HiddenNeuron** neurons, string activation)
{
    this->numNeurons = numNeurons;
    this->neurons = neurons;
    this->activation = activation;
}

HiddenLayer::~HiddenLayer()
{
    for (int i = 0; i < numNeurons; i++)
        delete neurons[i];

    delete[] neurons;

    neurons = NULL;
}

HiddenNeuron** HiddenLayer::getNeurons()
{
    return neurons;
}

void HiddenLayer::setNeurons(HiddenNeuron** neurons)
{
    if (neurons == NULL)
        this->neurons = neurons;
    else
    {
        for (int i = 0; i < numNeurons; i++)
            delete neurons[i];

        delete[] this->neurons;
        this->neurons = neurons;
    }
}

int HiddenLayer::getNumNeurons()
{
    return numNeurons;
}

void HiddenLayer::setNumNeurons(int numNeurons)
{
    this->numNeurons = numNeurons;
}

void HiddenLayer::forward(HiddenLayer* prevLayer)
{
    for (int i = 0; i < numNeurons; i++)
    {
        neurons[i]->forward(prevLayer);
        
        if (activation == "relu")
            neurons[i]->activateReLU();
        else if (activation == "sigmoid")
            neurons[i]->activateSigmoid();        
    }
}

void HiddenLayer::forward(InputLayer* inputLayer)
{
    for (int i = 0; i < numNeurons; i++)
    {
        neurons[i]->forward(inputLayer);
        
        if (activation == "relu")
            neurons[i]->activateReLU();

        if (activation == "sigmoid")
            neurons[i]->activateSigmoid();

    }
}

void HiddenLayer::printLayer()
{
    cout << "h:" << numNeurons << ":" << activation << endl;
}

void HiddenLayer::clearLayer()
{
    if (neurons != NULL)
        for (int i = 0; i < numNeurons; i++)
            neurons[i]->setValue(0);
}