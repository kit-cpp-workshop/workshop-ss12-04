/*
 * dame.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef DAME_H_
#define DAME_H_

#include "piece.h"

class Dame : public Piece
{
public:
	Dame(int a,int b,int c);
	virtual bool bewegungmoeglich(int a,int b,brett* brett);
	virtual ~Dame();
};


#endif /* DAME_H_ */
