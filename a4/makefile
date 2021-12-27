output = main.o Message.o Layer.o Application.o Presentation.o Transport.o Network.o Datalink.o Physical.o
gpp_o = g++ -c -std=c++98 -static

main: $(output)
			g++ -std=c++98 -static $(output) -o main

main.o: main.cpp Message.h Message.cpp Layer.cpp Layer.h Application.cpp Application.h Presentation.cpp Presentation.h Transport.cpp Transport.h Network.cpp Network.h Datalink.cpp Datalink.h Physical.cpp Physical.h
			$(gpp_o) main.cpp

run: main
			./main

clean:
			rm *.o main