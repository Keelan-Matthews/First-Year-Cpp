act1.out: main.o cauldron.o ingredient.o
			g++ main.o cauldron.o ingredient.o -o act1.out

main.o: main.cpp
			g++ -c main.cpp

cauldron.o: cauldron.cpp
			g++ -c cauldron.cpp

ingredient.o: ingredient.cpp
			g++ -c ingredient.cpp

run:
			./act1.out

clean:
			rm *.o act1