#include "ComunityCard.h"

ComunityCard::ComunityCard(){

}

ComunityCard::ComunityCard(char * cardImage,int type){

    this->comunityCardTexture =  new sf::Texture();
    this->comunityCardSprite = new sf::Sprite();
    if (this->comunityCardTexture->loadFromFile(cardImage, sf::IntRect(0, 0, 3000, 3000))){
        this->comunityCardTexture->setSmooth(true);
        this->comunityCardSprite->setTexture(*this->comunityCardTexture);
        if (type!=1)
            this->comunityCardSprite->setPosition(sf::Vector2f(750.f, 20.f));
        else
            this->comunityCardSprite->setPosition(sf::Vector2f(1030.f, 20.f));
    }

}

sf::Sprite * ComunityCard::getcomunityCardSprite(){
    return this->comunityCardSprite;
}

// sf::Sprite * ComunityCard::moverComunityCard(){
//     this->comunityCardSprite->setPosition(sf::Vector2f(600.f, 650.f));
//     return comunityCardSprite;
// }