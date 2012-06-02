/*
 * turm.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef TURM_H_
#define TURM_H_

#include "piece.h"

class Turm : public Piece
{
public:
	Turm(int a,int b,int c);
	virtual bool bewegungmoeglich(int a,int b);
	virtual ~Turm();
};


#endif /* TURM_H_ */
