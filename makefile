Main: Main.o Pieza.o PiezaAzul.o PiezaRoja.o PiezaVerde.o PiezaAmarilla.o
	g++ Main.o Pieza.o PiezaAzul.o PiezaRoja.o PiezaVerde.o PiezaAmarilla.o -o Main

Main.o: Main.cpp Pieza.h PiezaAzul.h PiezaAmarilla.h PiezaVerde.h PiezaRoja.h
	g++ -c Main.cpp

Pieza.o: Pieza.cpp Pieza.h
	g++ -c Pieza.cpp

PiezaRoja.o: PiezaRoja.cpp PiezaRoja.h Pieza.h
	g++ -c PiezaRoja.cpp

PiezaVerde.o: PiezaVerde.cpp PiezaVerde.h Pieza.h
	g++ -c PiezaVerde.cpp

PiezaAmarilla.o: PiezaAmarilla.cpp PiezaAmarilla.cpp Pieza.h
	g++ -c PiezaAmarilla.cpp

PiezaAzul.o: PiezaAzul.cpp PiezaAzul.h Pieza.h
	g++ -c PiezaAzul.cpp

clean:
	rm -f *.o Main