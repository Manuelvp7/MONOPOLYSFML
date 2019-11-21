#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string.h>
#include "Carro.h"
#include "Tablero.h"
#include "ComunityCard.h"


class Monopoly{
	public:
		
		Monopoly();
		void actualizarTablero();
		Carro * getCarros();
		void initWindow();
		void run();
		void initFichas();
		void initCommunityChest();
		void initChances();

		
	private:
		sf::RenderWindow * window;
		Tablero * tablero;
		Carro * carros;
		ComunityCard * chest;
		ComunityCard * chances;


};