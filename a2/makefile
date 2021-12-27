act1.out: main.o piece.o board.o solver.o
			g++ main.o piece.o board.o solver.o -o act1.out

main.o: main.cpp
			g++ -c main.cpp

piece.o: piece.cpp
			g++ -c piece.cpp

board.o: board.cpp
			g++ -c board.cpp

run:
			./act1.out

clean:
			rm *.o act1