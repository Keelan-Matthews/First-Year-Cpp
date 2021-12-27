#include "NeuralNetwork.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int convertToInt(string x)
{
    int y;
    stringstream convert(x);
    convert >> y;

    return y;
}

double convertToDouble(string x)
{
    double y;
    stringstream convert(x);
    convert >> y;

    return y;
}

NeuralNetwork::NeuralNetwork(string filePath)
{
    int prevNeurons;
    ifstream infile(filePath.c_str());

    if (!infile)
        cout << "The text file does not exist" << endl;
    else {
        //Retrieve number of inputs
        string input;
        getline(infile, input);
        input.erase(0, 2);
        string numInputs = input;
        inputLayer = new InputLayer(convertToInt(numInputs));

        prevNeurons = convertToInt(numInputs);

        //Retrieve number of hidden layers
        getline(infile, input);
        input.erase(0, 18);
        string numLayers = input;
        numHiddenLayers = (convertToInt(numLayers));

        //Initialize Hidden Layers array of pointers
        hiddenLayers = new HiddenLayer*[numHiddenLayers];

        //Retrieve hidden layer for each layer
        for (int i = 0; i < numHiddenLayers; i++) {
            getline(infile, input);
            //Erase h:
            input.erase(0, 2);

            //Extract number of neurons
            stringstream ss(input);
            string numNeurons;
            getline(ss, numNeurons, ':');

            //Extract activation
            string activation;
            getline(ss, activation, ':');

            //Create array to store neurons
            HiddenNeuron **hiddenNeuron = new HiddenNeuron *[convertToInt(numNeurons)];

            //Populate weights
            for (int j = 0; j < convertToInt(numNeurons); j++) {
                getline(infile, input);
                //Create array to store weights
                double *weights = new double[prevNeurons];
                stringstream neuronInput(input);
                string neuron = "";

                for (int f = 0; f < prevNeurons; f++)
                {
                    getline(neuronInput, neuron, ' ');
                    weights[f] = convertToDouble(neuron);
                }

                //Create neuron and put it in the neuron array
                hiddenNeuron[j] = new HiddenNeuron(prevNeurons, weights);
            }
            hiddenLayers[i] = new HiddenLayer(convertToInt(numNeurons), hiddenNeuron, activation);

            prevNeurons = convertToInt(numNeurons);
        }
        //Get o:1
        getline(infile,input);

        //Get neurons for output layer
        double *outputWeights = new double[prevNeurons];

        getline(infile, input);
        stringstream neuronInput(input);
        string neuron = "";
        for (int f = 0; f < prevNeurons; f++)
        {
            getline(neuronInput, neuron, ' ');
            outputWeights[f] = convertToDouble(neuron);
        }

        outputLayer = new OutputLayer(prevNeurons, outputWeights);
    }
}

NeuralNetwork::~NeuralNetwork()
{
    delete inputLayer;
    inputLayer = NULL;

    for (int i = 0; i < numHiddenLayers; i++)
        delete hiddenLayers[i];

    delete[] hiddenLayers;
    hiddenLayers = NULL;
    delete outputLayer;
    outputLayer = NULL;
}

double NeuralNetwork::forward(double* input)
{
    inputLayer->setInputs(input);
    hiddenLayers[0]->forward(inputLayer);

    for (int i = 1; i < numHiddenLayers; ++i)
        hiddenLayers[i]->forward(hiddenLayers[i - 1]);

   outputLayer->forward(hiddenLayers[numHiddenLayers-1]);

    return outputLayer->getOutputValue();
}

void NeuralNetwork::printNetwork()
{
    inputLayer->printLayer();

    for (int i = 0; i < numHiddenLayers; i++)
        hiddenLayers[i]->printLayer();

    outputLayer->printLayer();
}

void NeuralNetwork::clearNetwork()
{
    inputLayer->clearLayer();

    for (int i = 0; i < numHiddenLayers; i++)
        hiddenLayers[i]->clearLayer();

    outputLayer->clearLayer();  
}