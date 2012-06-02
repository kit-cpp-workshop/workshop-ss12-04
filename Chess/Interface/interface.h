/*
 * interface.h
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <string>

class Interface
{
public:
	void ausgabe(char (*f)[8]);
	void einlesen(int p);

	char e[6];
};


#endif /* INTERFACE_H_ */
