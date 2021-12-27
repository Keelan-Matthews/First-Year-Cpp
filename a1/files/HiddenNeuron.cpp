#include "HiddenNeuron.h"
#include "HiddenLayer.h"

HiddenNeuron::HiddenNeuron(int numWeights, double* weights)
{
    this->numWeights = numWeights;
    this->weights = weights;
    value = 0;
}

HiddenNeuron::~HiddenNeuron()
{
    delete[] weights;

    weights = NULL;
}

double HiddenNeuron::getValue()
{
    return value;
}

void HiddenNeuron::setValue(double value)
{
    this->value = value;
}

void HiddenNeuron::forward(HiddenLayer* prevLayer)
{
    value = 0.0;
    for (int i = 0; i < prevLayer->getNumNeurons(); ++i)
            value += prevLayer->getNeurons()[i]->getValue() * weights[i];
}

void HiddenNeuron::forward(InputLayer* inputLayer)
{
    value = 0.0;
    for (int i = 0; i < inputLayer->getNumInputs(); ++i)
        value += inputLayer->getInputs()[i] * weights[i];

}

void HiddenNeuron::activateReLU()
{
    value = fmax(0,value);
}

void HiddenNeuron::activateSigmoid()
{
    value = 1/(1+exp(-(value)));
}

