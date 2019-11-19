#include <SFML/Graphics.hpp>
#include <string.h>


class Tablero{
	public:
		
		Tablero();
		sf::Sprite * getSpriteTablero();
		
	private:
		//sf::RenderWindow window;
    	sf::Texture * texturaTbalero;
    	sf::Sprite * spriteTablero;
};