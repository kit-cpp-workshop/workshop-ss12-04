/*
 * koenig.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef KOENIG_H_
#define KOENIG_H_

#include "piece.h"

class Koenig : public Piece
{
public:
	Koenig(int a,int b,int c);
	virtual bool bewegungmoeglich(int a,int b,brett* brett);
	virtual ~Koenig();
};


#endif /* KOENIG_H_ */
