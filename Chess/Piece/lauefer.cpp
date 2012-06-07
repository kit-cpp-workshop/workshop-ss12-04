/*
 * lauefer.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "lauefer.h"


Laeufer::~Laeufer()
{

}

bool Laeufer::bewegungmoeglich(int a,int b,brett* brett)
{
	int deltay=abs(b-y);
	int deltax=abs(a-x);

	//diagonal
	if (deltax==deltay)
	{
		int richtungx=(a-x)/deltax;
		int richtungy=(b-y)/deltay;
		for (int j=1;j<deltax;j++)
		{
			if (brett->besitzer(x+richtungx*j,y+richtungy*j)!=0) { return false; }
		}
		if (brett->besitzer(a,b)!=besitzer) { return true; } else { return false;}
	}

	return false;
}

Laeufer::Laeufer(int a,int b,int c):Piece(a,b,c)
{

}


