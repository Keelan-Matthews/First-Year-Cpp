#include <iostream>
#include <iomanip>
#include "NeuralNetwork.h"
using namespace std;

int main()
{
    NeuralNetwork* mean = new NeuralNetwork("mean.txt");

    double * input = new double[5];

    input[0] = 5.0;
    input[1] = 10.0;
    input[2] = 15.0;
    input[3] = 20.0;
    input[4] = 25.0;

    cout << "------------------------------------------------" << endl;
    cout << "Mean should be: 14.8784669740762" << endl;
    cout << endl;

    cout << setprecision(15) << mean->forward(input) << endl;

    mean->printNetwork();
    cout << "------------------------------------------------" << endl;




    NeuralNetwork* sin = new NeuralNetwork("sin(x).txt");

    double * sinInput = new double(1.5);

    cout << "------------------------------------------------" << endl;
    cout << "Sin should be: 1.12744406068624" << endl;
    cout << endl;

    cout << setprecision(15) << sin->forward(sinInput) << endl;

    sin->printNetwork();
    cout << "------------------------------------------------" << endl;





    NeuralNetwork* squared = new NeuralNetwork("x_squared.txt");

    double * squaredInput = new double(2.0);

    cout << "------------------------------------------------" << endl;
    cout << "x squared should be: 3.95883565497932" << endl;
    cout << endl;

    cout << setprecision(15) << squared->forward(squaredInput) << endl;

    squared->printNetwork();
    cout << "------------------------------------------------" << endl;






    sin->clearNetwork();
    squared->clearNetwork();
    mean->clearNetwork();
    return 0;
}