/*
 * koenig.cpp
 *
 *  Created on: 31.05.2012
 *      Author: Thomas
 */

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "koenig.h"


Koenig::~Koenig()
{

}

bool Koenig::bewegungmoeglich(int a,int b,brett* brett)
{
	int deltay=abs(b-y);
	int deltax=abs(a-x);

	if ((deltax<=1) && (deltay<=1) && (brett->besitzer(a,b)!=besitzer)) { return true; }
return false;
}

Koenig::Koenig(int a,int b,int c):Piece(a,b,c)
{

}


