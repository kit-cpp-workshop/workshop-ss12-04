/*
 * bauer.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef BAUER_H_
#define BAUER_H_

#include "piece.h"

class Bauer : public Piece
{
public:
	Bauer(int a,int b,int c);
	virtual bool bewegungmoeglich(int a,int b);
	virtual ~Bauer();
};


#endif /* BAUER_H_ */
