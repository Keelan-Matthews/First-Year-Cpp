act1.out: main.o HiddenLayer.o HiddenNeuron.o InputLayer.o NeuralNetwork.o OutputLayer.o
			g++ main.o HiddenLayer.o HiddenNeuron.o InputLayer.o NeuralNetwork.o OutputLayer.o -o act1.out

main.o: main.cpp
			g++ -c main.cpp

HiddenLayer.o: HiddenLayer.cpp
			g++ -c HiddenLayer.cpp

HiddenNeuron.o: HiddenNeuron.cpp
			g++ -c HiddenNeuron.cpp

InputLayer.o: InputLayer.cpp
			g++ -c InputLayer.cpp

NeuralNetwork.o: NeuralNetwork.cpp
			g++ -c NeuralNetwork.cpp

OutputLayer.o: OutputLayer.cpp
			g++ -c OutputLayer.cpp

run:
			./act1.out

clean:
			rm *.o act1