#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include <SFML/Graphics.hpp>
#include <string.h>
#include "space.h"
#include "move_action"
#include "player.h"

class Propiedades{
	public:
		Propiedades();

	private:
		Space spaces[40];
}