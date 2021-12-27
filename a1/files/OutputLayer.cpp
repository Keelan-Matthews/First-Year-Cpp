#include "OutputLayer.h"
#include <iostream>
using namespace std;
OutputLayer::OutputLayer(int numWeights, double* weights)
{
    this->numWeights = numWeights;
    this->weights = weights;
    outputValue = 0;
}

OutputLayer::~OutputLayer()
{
    delete[] weights;
    weights = NULL;
}

double OutputLayer::getOutputValue()
{
    return this->outputValue;
}

void OutputLayer::setOutputValue(double outputValue)
{
    this->outputValue = outputValue;
}

void OutputLayer::forward(HiddenLayer* lastHiddenLayer)
{
    outputValue = 0;
    for (int i = 0; i < lastHiddenLayer->getNumNeurons(); i++)
        outputValue += lastHiddenLayer->getNeurons()[i]->getValue() * weights[i];
}

void OutputLayer::printLayer()
{
    cout << "o:1" << endl;
}

void OutputLayer::clearLayer()
{
    outputValue = 0;
}