#include "InputLayer.h"
#include <iostream>

InputLayer::InputLayer(int numInputs)
{
    this->numInputs = numInputs;
    inputs = new double[numInputs];

    for (int i = 0; i < numInputs; i++)
        inputs[i] = 0;
}

InputLayer::~InputLayer()
{
    delete[] inputs;

    inputs = NULL;
}

double* InputLayer::getInputs()
{
    return inputs;
}

int InputLayer::getNumInputs()
{
    return numInputs;
}

void InputLayer::setInputs(double* inputs)
{
    if (this->inputs != inputs)
        if (this->inputs == NULL)
            this->inputs = inputs;
        else
        {
            delete[] this->inputs;
            this->inputs = inputs;
        }
}

void InputLayer::setNumInputs(int numInputs)
{
    this->numInputs = numInputs;
}

void InputLayer::printLayer()
{
    std::cout << "i:" << numInputs << std::endl;
}

void InputLayer::clearLayer()
{
    if (inputs != NULL)
        for (int i = 0; i < numInputs; i++)
            inputs[i] = 0;
}

