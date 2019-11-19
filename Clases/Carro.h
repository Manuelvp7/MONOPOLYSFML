#include <SFML/Graphics.hpp>
#include <string.h>


class Carro{
	public:
		Carro();
		Carro(char * carImage, int i);
		sf::Sprite * getspriteCarro();
		sf::Sprite * moverCarro();
		
		
	private:
		//sf::RenderWindow window;
		int idCasilla;
	    sf::Texture * texturaCarro;
    	sf::Sprite * spriteCarro;
};