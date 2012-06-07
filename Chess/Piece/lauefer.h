/*
 * lauefer.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef LAUEFER_H_
#define LAUEFER_H_

#include "piece.h"

class Laeufer : public Piece
{
public:
	Laeufer(int a,int b,int c);
	virtual bool bewegungmoeglich(int a,int b,brett* brett);
	virtual ~Laeufer();
};


#endif /* LAUEFER_H_ */
