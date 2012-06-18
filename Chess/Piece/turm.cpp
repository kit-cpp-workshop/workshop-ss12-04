/*
 * turm.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>
#include <cmath>

#include "turm.h"


Turm::~Turm()
{

}

bool Turm::bewegungmoeglich(int a,int b,brett* brett)
{
	int deltay=std::abs(b-y);
	int deltax=std::abs(a-x);

	//links-rechts
	if ((deltax!=0) && (deltay==0))
	{
		int richtung=(a-x)/deltax;
		for (int j=1;j<deltax;j++)
		{
			if (brett->besitzer(x+richtung*j,y)!=0) { return false; }
		}
		if (brett->besitzer(a,b)!=besitzer) { return true; } else { return false;}
	}

	//vor-zurück
	if ((deltax==0) && (deltay!=0))
	{
		int richtung=(b-y)/deltay;
		for (int j=1;j<deltay;j++)
		{
			if (brett->besitzer(x,y+richtung*j)!=0) { return false; }
		}
		if (brett->besitzer(a,b)!=besitzer) { return true; } else { return false;}
	}

	return false;
}

Turm::Turm(int a,int b,int c):Piece(a,b,c)
{

}


