/*
 * piece.h
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#ifndef PIECE_H_
#define PIECE_H_

#include "../game/brett.h"

class Piece
{
public:
	Piece(int a,int b,int c);
	bool IsPosition(int a, int b, int c);
	void move(int xn, int yn,brett* b);
	void geschlagen();
	virtual bool bewegungmoeglich(int a,int b)=0;
	virtual ~Piece();
protected:
	int x;
	int y;
	int besitzer;
	bool active;

};


#endif /* PIECE_H_ */
