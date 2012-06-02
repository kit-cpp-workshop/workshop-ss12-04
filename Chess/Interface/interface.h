/*
 * interface.h
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <string>
#include "../game/brett.h"

class Interface
{
public:
	void ausgabe(brett* b);
	void einlesen(int p);

	char p1a,p2a;
	int p1b,p2b;
};


#endif /* INTERFACE_H_ */
