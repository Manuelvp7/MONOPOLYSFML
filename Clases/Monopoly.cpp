#include "Monopoly.h"

Monopoly::Monopoly(){

    initWindow();
    initFichas();
    initCommunityChest();
    initChances();
    
    this->tablero = new Tablero();

}

void Monopoly::initCommunityChest(){

    char * titleAux = (char*)malloc(sizeof(char)*50);
    char imageTitle[] = "images/CommunityChest/community";

    this->chest = (ComunityCard*)malloc(sizeof(ComunityCard)*10);

    for (int i = 0; i < 10; i++){

        memset(&titleAux[0], 0, sizeof(titleAux));
        char numeric = (char)48+i;
        strcpy(titleAux, imageTitle); 
        strncat(titleAux, &numeric,1); 
        strncat(titleAux, ".png",strlen(".png"));    
        this->chest[i] = ComunityCard(titleAux,1);
    }


}

void Monopoly::initChances(){

    char * titleAux = (char*)malloc(sizeof(char)*50);
    char imageTitle[] = "images/chance/chance";

    this->chances = (ComunityCard*)malloc(sizeof(ComunityCard)*10);

    for (int i = 0; i < 10; i++){

        memset(&titleAux[0], 0, sizeof(titleAux));
        char numeric = (char)48+i;
        strcpy(titleAux, imageTitle); 
        strncat(titleAux, &numeric,1); 
        strncat(titleAux, ".png",strlen(".png")); 
        this->chances[i] = ComunityCard(titleAux,2);
    }

}

void Monopoly::initFichas(){

    char * titleAux = (char*)malloc(sizeof(char)*12);
    char imageTitle[] = "images/car";

    this->carros = (Carro*)malloc(sizeof(Carro)*4);

    for (int i = 0; i < 4; i++){

        memset(&titleAux[0], 0, sizeof(titleAux));
        char numeric = (char)49+i;
        strcpy(titleAux, imageTitle); 
        strncat(titleAux, &numeric,1); 
        strncat(titleAux, ".PNG",strlen(".PNG")); 
        this->carros[i] = Carro(titleAux,i);
    }

}


void Monopoly::initWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(1500, 900), "SFML window");
}


void Monopoly::run(){
    while (this->window->isOpen()){
        sf::Event event;
        while (this->window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                this->carros[1].getspriteCarro()->move(-5.f,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                this->carros[1].getspriteCarro()->move(5.f,0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                this->carros[1].getspriteCarro()->move(0,5.f);                                            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                this->carros[1].getspriteCarro()->move(0,-5.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                this->carros[1].getspriteCarro()->rotate(90);                            
        }

// IMPRIMIR POSICIONES
        sf::Vector2f position = carros[1].getspriteCarro()->getPosition();
        printf("POSICION x %lf y %lf \n",position.x,position.y);  
    
        this->window->clear();
        Carro carro = getCarros()[1];
        this->window->draw(*tablero->getSpriteTablero());
        
        this->window->draw(*chest[3].getcomunityCardSprite());
        this->window->draw(*chances[3].getcomunityCardSprite());
        for (int i = 0; i < 4; i++){
            this->window->draw(*getCarros()[i].getspriteCarro());
        }
        
        this->window->display();
    }
}

Carro * Monopoly::getCarros(){
    return carros;
}

void Monopoly::actualizarTablero(){
}

