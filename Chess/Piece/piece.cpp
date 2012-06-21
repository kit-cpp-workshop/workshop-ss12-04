/*
 * piece.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>

#include "piece.h"
#include "../game/brett.h"

Piece::Piece(int a,int b,int c)
{
	x=a;
	y=b;
	besitzer=c;
	active=true;
}

void Piece::geschlagen()
{
	active=false;
}

bool Piece::IsPosition(int a,int b,int c)
{
	//std::cout << a << "=" << x << ";" << b << "=" << y << ";" << c << "=" << besitzer << std::endl;

	if ((a==x) && (b==y) && (c==besitzer) && (active==true))
		{
		return true;
		}
	return false;
}


Piece::~Piece()
{

}

typedef char foo[8];
typedef foo bar[8];
void Piece::move(int xn,int yn, brett* b)
{
	b->schreibe(xn,yn,b->lese(x,y));
	b->schreibe(x,y,' ');
	x=xn;
	y=yn;
}

