#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string.h>
#include "Carro.h"
#include "Tablero.h"


class Monopoly{
	public:
		
		Monopoly();
		void actualizarTablero();
		Carro * getCarros();
		void initWindow();
		void run();

		
	private:
		sf::RenderWindow * window;
		Tablero * tablero;
		Carro * carros;


};