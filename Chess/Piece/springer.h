/*
 * springer.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef SPRINGER_H_
#define SPRINGER_H_

#include "piece.h"

class Springer : public Piece
{
public:
	Springer(int a,int b,int c);
	virtual bool bewegungmoeglich(int a,int b);
	virtual ~Springer();
};


#endif /* BAUER_H_ */
