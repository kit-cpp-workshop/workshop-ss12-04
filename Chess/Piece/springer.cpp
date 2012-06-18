/*
 * bauer.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>
#include <cmath>

#include "springer.h"


Springer::~Springer()
{

}

bool Springer::bewegungmoeglich(int a,int b,brett* brett)
{
	int deltay=std::abs(b-y);
	int deltax=std::abs(a-x);

	if ((deltax==2) && (deltay==1) && (brett->besitzer(a,b)!=besitzer)) { return true; }
	if ((deltax==1) && (deltay==2) && (brett->besitzer(a,b)!=besitzer)) { return true; }
return false;
}

Springer::Springer(int a,int b,int c):Piece(a,b,c)
{

}


