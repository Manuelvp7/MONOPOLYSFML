all:test

test: main.o Tablero.o Carro.o Monopoly.o ComunityCard.o
	g++ main.o  Tablero.o Carro.o Monopoly.o ComunityCard.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o:main.cpp
	
	g++ main.cpp -c

Tablero.o:Clases/Tablero.cpp
	g++ Clases/Tablero.cpp -c

Carro.o:Clases/Carro.cpp
	g++ Clases/Carro.cpp -c

Monopoly.o:Clases/Monopoly.cpp
	g++ Clases/Monopoly.cpp -c

ComunityCard.o:Clases/ComunityCard.cpp
	g++ Clases/ComunityCard.cpp -c





	
