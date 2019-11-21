#include "Carro.h"

Carro::Carro(){

}

Carro::Carro(char * carImage, int member){

    member = 22*member;

    printf("EN EL CONSTRUCTOR %s\n",carImage );

    this->texturaCarro =  new sf::Texture();
    this->spriteCarro = new sf::Sprite();


    if (this->texturaCarro->loadFromFile(carImage, sf::IntRect(0, 0, 2000, 2000))){
        this->texturaCarro->setSmooth(true);
        this->spriteCarro->setTexture(*this->texturaCarro);
        this->spriteCarro->setOrigin(sf::Vector2f(1000.f, 1000.f));
        this->spriteCarro->scale(sf::Vector2f(0.04,0.04));
        this->spriteCarro->setPosition(sf::Vector2f(650.f, 630.f+member));
        this->spriteCarro->rotate(-90.f); 
       
    }

}

sf::Sprite * Carro::getspriteCarro(){
    return this->spriteCarro;
}

sf::Sprite * Carro::moverCarro(){
    this->spriteCarro->setPosition(sf::Vector2f(600.f, 650.f));
    return spriteCarro;
}