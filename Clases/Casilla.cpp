#include "Casilla.h"
#include <string.h>



Casilla::Casilla(int idCasilla,double coordX,double coordY,int trayectoria){

	this->trayectoria = trayectoria;
	this->idCasilla = idCasilla;
    this->coordY = coordY;
    this->coordX = coordX;
}

int Casilla::getIdCasilla(){
	return this->idCasilla;
}

double Casilla::getCoordX(){
    return this->coordX;
}
double Casilla::getCoordY(){
    return this->coordY;
}

int Casilla::getTrayectoria(){
	return this->trayectoria;
}