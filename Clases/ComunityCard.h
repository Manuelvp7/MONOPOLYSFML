#include <SFML/Graphics.hpp>
#include <string.h>


class ComunityCard{
	public:
		ComunityCard();
		ComunityCard(char * carImage, int type);
		sf::Sprite * getcomunityCardSprite();
		// sf::Sprite * moverComunityCard();
		
		
	private:
		//sf::RenderWindow window;
		int idCasilla;
	    sf::Texture * comunityCardTexture;
    	sf::Sprite * comunityCardSprite;
};