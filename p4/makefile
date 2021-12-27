act1.out: main.o tome.o
			g++ main.o tome.o -o act1.out

main.o: main.cpp
			g++ -c main.cpp

tome.o: tome.cpp
			g++ -c tome.cpp

run:
			./act1.out

clean:
			rm *.o act1