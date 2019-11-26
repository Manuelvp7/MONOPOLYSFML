#include "Tablero.h"
#include "dice.h"
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

void Monopoly::movedice(){
    Dice dice[2];
    
    int diceRoll1;
    int diceRoll2;
    	
    diceRoll1 = dice[0].rollDice();
	diceRoll2 = dice[1].rollDice();
	cout << "Te moviste " << diceRoll1 + diceRoll2 << " lugares." << endl << endl;
	int pastLocation = Tablero.getPlayerLocation(i);
	Tablero.move(i, diceRoll1 + diceRoll2);
	int currentLocation = Tablero.getPlayerLocation(i);
	int currentOwnership = Tablero.getSpaceOwnership(currentLocation);
	int futureLocation = 0;
	
}

/*
	void Tablero::move(int numPlayer, int amountInput){
	movement.move_amount(&(players[numPlayer]), amountInput);
}

void Tablero::createPlayers(int numPlayers){
	players = new Player[numPlayers];
}

void Tablero::setPlayerName(int playerNum, string inputName){
	players[playerNum].setPlayerName(inputName);
}

void Tablero::setGamePiece(int playerNum, string inputPiece){
	players[playerNum].setGamePieceName(inputPiece);
}

string Tablero::getPlayerName(int playerNum){
	return players[playerNum].getPlayerName();
}

string Tablero::getGamePiece(int playerNum){
	return players[playerNum].getGamePieceName();
}

Player* Tablero::getPlayer(int num){
	return &players[num];
}

int Tablero::getPlayerLocation(int playerNum){
	return players[playerNum].getLocation();
}

int Tablero::getPlayerMoney(int playerNum){
	return players[playerNum].getMoneyAmount();
}

string Tablero::spaceType(int inputIndex){
	return spaces[inputIndex].getType();
}

int Tablero::getSpaceOwnership(int spaceIndex){
	return spaces[spaceIndex].getOwnership();
}

int Tablero::getSpacePropertyCost(int spaceIndex){
	return spaces[spaceIndex].getPropertyCost();
}

void Tablero::setSpaceOwnership(int spaceIndex, int playerNum){
	spaces[spaceIndex].setOwnership(playerNum);
}

int Tablero::getSpaceRent(int spaceIndex){
	return spaces[spaceIndex].getRent();
}

int Tablero::getSpaceTax(int spaceIndex){
	return spaces[spaceIndex].getTax();
}

int Tablero::getSpaceFreeParking(int spaceIndex){
	return spaces[spaceIndex].getFreeParking();
}

string Tablero::getSpaceName(int spaceIndex, int index){
	return spaces[spaceIndex].getName(index);
}

void Tablero::upgradeSpace(int spaceNum){
	spaces[spaceNum].upgrade();
}

bool Tablero::isPlayerAlive(int playerNum){
	return players[playerNum].isAlive();
}

void Tablero::playerLost(int playerNum){
	players[playerNum].reset();
}

//Display Game Board
void Tablero::displayHorizontal(int firstSpace, int lastSpace, int numPlayers){

	int numSpaces = abs(lastSpace - firstSpace) + 1;

	//first line for all cards
	for(int i = 0; i < numSpaces; i++){
		cout << "----------";
	}
	
	cout << "-" << endl;

	//second line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|--"; 
			for(int x = 0; x < current.getHouses(); x++){
			    cout << "X";
			}
			for(int x = 0; x < 7-(current.getHouses()); x++){
			    cout << "-";
			} 
		} else {
			cout << "|" << current.getName(0);
		}
	}
	
	cout << "|" << endl;

	//third line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getName(0);
		} else {
			cout << "|" << current.getName(1);
		}
	}
	
	cout << "|" << endl;

	//fourth line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getName(1);
		} else {
			cout << "|" << "         ";
		}
	}
	
	cout << "|" << endl;

	//fifth line

	for(int i = 0; i < numSpaces; i++){

		int counter = 0;		

		if(firstSpace < lastSpace) {

		    cout << "|   ";
		    for(int j = 0; j < numPlayers; j++){
			if((firstSpace + i) == (players[j].getLocation())){
				cout << players[j].getGamePiece();
				counter++;
			}
		    }	
		    for(int x = 0; x < (6-counter); x++){
		        cout << " ";
		    }	

		} else {

		    cout << "|   ";
		    for(int j = 0; j < numPlayers; j++){
			if((firstSpace - i) == (players[j].getLocation())){
				cout << players[j].getGamePiece();
				counter++;
			}
		    }	
		    for(int x = 0; x < (6-counter); x++){
		        cout << " ";
		    }	

		}	
	}
	
	cout << "|" << endl;

	//sixth line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getActionText(0);
		} else {
			cout << "|" << current.getActionText(0);
		}
	}
	
	cout << "|" << endl;

	//seventh line
	for(int i = 0; i < numSpaces; i++){

		Space current;

		if(firstSpace < lastSpace) {
			current = spaces[firstSpace + i];
		} else {
			current = spaces[firstSpace - i];
		}

		if(current.getType() == "Property"){ 
			cout << "|" << current.getActionText(1);
		} else {
			cout << "|" << current.getActionText(1);
		}
	}
	
	cout << "|" << endl;
	
	//eighth line
	for(int i = 0; i < numSpaces; i++){
		cout << "----------";
	}
	
	cout << "-" << endl;
}

void Tablero::displayVertical(int firstSpace, int lastSpace, int numPlayers){

	Space current = spaces[firstSpace];
	Space current2 = spaces[lastSpace];

	//toplines
	if(firstSpace != 19){

		cout << "-----------";

		for(int i = 0; i < 8; i++){
			cout << "          ";
		}

		cout << "         ";
		cout << "-----------" << endl;

	}

	
	
	//first line
	if(current.getType() == "Property"){
		cout << "|--"; 
		for(int x = 0; x < current.getHouses(); x++){
			cout << "X";
		}
		for(int x = 0; x < 7-(current.getHouses()); x++){
			cout << "-";
		} 
	} else{
		cout << "|" << current.getName(0);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|--"; 
		for(int x = 0; x < current2.getHouses(); x++){
			cout << "X";
		}
		for(int x = 0; x < 7-(current2.getHouses()); x++){
			cout << "-";
		} 
	} else{
		cout << "|" << current2.getName(0);
	}
	
	cout << "|" << endl;

	//second line

	if(current.getType() == "Property"){
		cout << "|" << current.getName(0);
	} else{
		cout << "|" << current.getName(1);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getName(0);
	} else{
		cout << "|" << current2.getName(1);
	}

	cout << "|" << endl;
	
	//third line
	
	if(current.getType() == "Property"){
		cout << "|" << current.getName(1);
	} else{
		cout << "|" << "         ";
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getName(1);
	} else{
		cout << "|" << "         ";
	}

	cout << "|" << endl;

	//fourth line

	int counter = 0;		

	cout << "|   ";

	for(int j = 0; j < numPlayers; j++){
		if((firstSpace) == (players[j].getLocation())){
			cout << players[j].getGamePiece();
			counter++;
		}
	}	

	for(int x = 0; x < (6-counter); x++){
		        cout << " ";
	}

	cout << "|         ";	

	for(int z = 0; z < 8; z++){
	    cout << "          ";
	}

	counter = 0;		

	cout << "|   ";
	
	for(int j = 0; j < numPlayers; j++){
		if((lastSpace) == (players[j].getLocation())){
			cout << players[j].getGamePiece();
			counter++;
		}
	}	

	for(int x = 0; x < (6-counter); x++){
		        cout << " ";
	}	
	
	cout << "|" << endl;

	//fifth line
	
	if(current.getType() == "Property"){
		cout << "|" << current.getActionText(0);
	} else{
		cout << "|" << current.getActionText(0);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getActionText(0);
	} else{
		cout << "|" << current2.getActionText(0);
	}
	
	cout << "|" << endl;

	//sixth line
	
	if(current.getType() == "Property"){
		cout << "|" << current.getActionText(1);
	} else{
		cout << "|" << current.getActionText(1);
	}
	
	cout << "|         ";

	for(int i = 0; i < 8; i++) {
		cout << "          ";
	}

	if(current2.getType() == "Property"){
		cout << "|" << current2.getActionText(1);
	} else{
		cout << "|" << current2.getActionText(1);
	}
	
	cout << "|" << endl;

}
*/