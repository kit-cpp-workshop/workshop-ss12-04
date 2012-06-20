/*
 * bauer.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>
#include <cstdlib>
#include "bauer.h"


Bauer::~Bauer()
{

}

bool Bauer::bewegungmoeglich(int a,int b,brett* brett)
{
	int deltay=std::abs(b-y);
	int deltax=std::abs(a-x);


	if (besitzer==1)
	{
		std::cout << a << b << x << y << deltax << deltay << std::endl;
	if ((b<y) && (deltax==0) && (deltay==1) && (brett->besitzer(a,b)==0)) { return true;}
	if ((y==6) && (deltax==0) && (deltay==2) && (brett->besitzer(a,b-1)==0) && (brett->besitzer(a,b)==0)) { return true; }
	if ((b<y) && (deltax==1) && (deltay==1) && (brett->besitzer(a,b)==2)) { return true; }
	}
	else
	{
	if ((b>y) && (deltax==0) && (deltay==1) && (brett->besitzer(a,b)==0)) { return true; }
	if ((y==1) && (deltax==0) && (deltay==2) && (brett->besitzer(a,b-1)==0) && (brett->besitzer(a,b)==0)) { return true; }
	if ((b>y) && (deltax==1) && (deltay==1) && (brett->besitzer(a,b)==1)) { return true; }
	}

return false;
}
	/*
	int deltay=std::abs(b-y);
	int deltax=std::abs(a-x);
	int yZugrichtung = (besitzer == 1) ? (-1) : (1);
	int anderer = (besitzer ==1) ? (2) : (1);

	if ((b-y)*yZugrichtung>0)
	{
		if (deltax==0)
		{
			if ((deltay==1) && (brett->besitzer(a,b)==0)) { return true;}
			if ((deltay==2) && ((y==6) || (y==1)) && (brett->besitzer(a,b-1)==0) && (brett->besitzer(a,b)==0)) { return true; }
		}

		if ((deltax==1) && (deltay==1) && (brett->besitzer(a,b)==2))
		{
			return true;
		}
	}

	return false;
}*/

Bauer::Bauer(int a,int b,int c):Piece(a,b,c)
{

}


