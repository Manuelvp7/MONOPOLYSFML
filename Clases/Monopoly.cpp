#include "Monopoly.h"

Monopoly::Monopoly(){

	initWindow();

	char * titleAux = (char*)malloc(sizeof(char)*12);
	char imageTitle[] = "images/car";
	this->carros = (Carro*)malloc(sizeof(Carro*)*4);
	tablero = new Tablero();

   	for (int i = 0; i < 4; i++){

   		memset(&titleAux[0], 0, sizeof(titleAux));
        char numeric = (char)49+i;
        strcpy(titleAux, imageTitle); 
        strncat(titleAux, &numeric,1); 
        strncat(titleAux, ".PNG",strlen(".PNG")); 
        
        printf("%d %s\n",i,titleAux );   
        this->carros[i] = Carro(titleAux,i);
    }
}

void initFichas(){

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
        }

        this->window->clear();
        Carro carro = getCarros()[1];
        this->window->draw(*tablero->getSpriteTablero());
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

