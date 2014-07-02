/*
 * interface.h
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#ifndef INTERFACEb_H_
#define INTERFACEb_H_


#include <string>
#include <SDL/SDL.h>
#include "../game/brett.h"

class Interfaceb
{
public:
	void ausgabe(brett* b);
	void einlesen(int p);
	void winner(int player);
	Interfaceb();
	~Interfaceb();

	char p1a,p2a;
	int p1b,p2b;

private:
	SDL_Surface* display;

};


#endif /* INTERFACE_H_ */
