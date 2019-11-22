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

/*
	void Game_Board::move(int numPlayer, int amountInput){
	movement.move_amount(&(players[numPlayer]), amountInput);
}

void Game_Board::createPlayers(int numPlayers){
	players = new Player[numPlayers];
}

void Game_Board::setPlayerName(int playerNum, string inputName){
	players[playerNum].setPlayerName(inputName);
}

void Game_Board::setGamePiece(int playerNum, string inputPiece){
	players[playerNum].setGamePieceName(inputPiece);
}

string Game_Board::getPlayerName(int playerNum){
	return players[playerNum].getPlayerName();
}

string Game_Board::getGamePiece(int playerNum){
	return players[playerNum].getGamePieceName();
}

Player* Game_Board::getPlayer(int num){
	return &players[num];
}

int Game_Board::getPlayerLocation(int playerNum){
	return players[playerNum].getLocation();
}

int Game_Board::getPlayerMoney(int playerNum){
	return players[playerNum].getMoneyAmount();
}

string Game_Board::spaceType(int inputIndex){
	return spaces[inputIndex].getType();
}

int Game_Board::getSpaceOwnership(int spaceIndex){
	return spaces[spaceIndex].getOwnership();
}

int Game_Board::getSpacePropertyCost(int spaceIndex){
	return spaces[spaceIndex].getPropertyCost();
}

void Game_Board::setSpaceOwnership(int spaceIndex, int playerNum){
	spaces[spaceIndex].setOwnership(playerNum);
}

int Game_Board::getSpaceRent(int spaceIndex){
	return spaces[spaceIndex].getRent();
}

int Game_Board::getSpaceTax(int spaceIndex){
	return spaces[spaceIndex].getTax();
}

int Game_Board::getSpaceFreeParking(int spaceIndex){
	return spaces[spaceIndex].getFreeParking();
}

string Game_Board::getSpaceName(int spaceIndex, int index){
	return spaces[spaceIndex].getName(index);
}

void Game_Board::upgradeSpace(int spaceNum){
	spaces[spaceNum].upgrade();
}

bool Game_Board::isPlayerAlive(int playerNum){
	return players[playerNum].isAlive();
}

void Game_Board::playerLost(int playerNum){
	players[playerNum].reset();
}

//Display Game Board
void Game_Board::displayHorizontal(int firstSpace, int lastSpace, int numPlayers){

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

void Game_Board::displayVertical(int firstSpace, int lastSpace, int numPlayers){

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