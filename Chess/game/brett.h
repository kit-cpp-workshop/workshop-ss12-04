/*
 * brett.h
 *
 *  Created on: 02.06.2012
 *      Author: Thomas
 */

#ifndef BRETT_H_
#define BRETT_H_

#include "../game/brett.h"

class brett {
private:
	char f[64];
public:
	brett();
	~brett();
	char lese(int x,int y);
	bool schreibe(int x,int y,char value);
	int besitzer(int x,int y);
};

#endif /* BRETT_H_ */
