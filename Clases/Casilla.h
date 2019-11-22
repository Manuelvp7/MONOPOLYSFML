#include <SFML/Graphics.hpp>
#include <string.h>


class Casilla{
	public:
		
	Casilla(int idCasilla,double coordX,double coordY,int trayectoria);	
	double getCoordX();
	double getCoordY();
	int getTrayectoria();
	int getIdCasilla();
		
		
	private:
		//sf::RenderWindow window;
		int idCasilla;
		double coordX;
		double coordY;
		int trayectoria;


};