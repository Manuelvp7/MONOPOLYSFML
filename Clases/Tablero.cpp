#include "Tablero.h"
#include <string.h>



Tablero::Tablero(){

    this->texturaTbalero = new sf::Texture() ;
   	this->spriteTablero = new sf::Sprite() ;

    if (this->texturaTbalero->loadFromFile("images/image.jpg", sf::IntRect(10, 10, 2000, 2000))){
        this->texturaTbalero->setSmooth(true);
        this->spriteTablero->setTexture(*this->texturaTbalero);
        this->spriteTablero->scale(sf::Vector2f(0.46,0.46));
        this->spriteTablero->setPosition(sf::Vector2f(16.f, 16.f));
        
    }
         

}

sf::Sprite * Tablero::getSpriteTablero(){
    return this->spriteTablero;
}
