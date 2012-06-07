/*
 * bauer.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "bauer.h"


Bauer::~Bauer()
{

}

bool Bauer::bewegungmoeglich(int a,int b,brett* brett)
{
	int deltay=abs(b-y);
	int deltax=abs(a-x);

	if (besitzer==1)
	{
		if ((b<y) && (deltax==0) && (deltay==1) && (brett->besitzer(a,b)==0)) { return true;}
		if ((y==6) && (deltax==0) && (deltay==2) && (brett->besitzer(a,b-1)==0) && (brett->besitzer(a,b)==0)) { return true; }
		if ((b<y) && (deltax==1) && (deltay==1) && (brett->besitzer(a,b)==2)) { return true; }
	}
	else
	{
		if ((b>y) && (deltax==0) && (deltay==1)  && (brett->besitzer(a,b)==0)) { return true; }
		if ((y==1) && (deltax==0) && (deltay==2) && (brett->besitzer(a,b-1)==0) && (brett->besitzer(a,b)==0)) { return true; }
		if ((b>y) && (deltax==1) && (deltay==1) && (brett->besitzer(a,b)==1)) { return true; }
	}

	return false;
}

Bauer::Bauer(int a,int b,int c):Piece(a,b,c)
{

}


