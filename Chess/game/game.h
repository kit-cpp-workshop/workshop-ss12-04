/*
 * game.h
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#ifndef GAME_H_
#define GAME_H_

#include "../Interface/interface.h"
#include "../Piece/piece.h"
#include "brett.h"

class Game
{
private:
	brett* b;
	Interface aus;
	int activeplayer;
	bool end;
	int besitzer(int x,int y);
	Piece *figur[32];

public:
	Game();
	void zug();
	int aendern(char a,int b,char c,int d);
	~Game();
};

#endif /* GAME_H_ */
