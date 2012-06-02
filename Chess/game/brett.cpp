/*
 * brett.cpp
 *
 *  Created on: 02.06.2012
 *      Author: Thomas
 */

#include "brett.h"
#include <iostream>


brett::brett() {

	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			f[8*i+j]=' ';
		}
	}
}


brett::~brett() {

}

char brett::lese(int x,int y)
{
	if ((x>=0) && (x<8) && (y>=0) && (y<8))
	{
		//int val=x+8*y;
		//char z=f[val]; // --> geht nicht, warum????
		//return z;
	}
	return '-';
}

bool brett::schreibe(int x,int y,char value)
{
	if ((x>=0) && (x<8) && (y>0) && (y<8))
	{
		//f[x+8*y]=value;
		return true;
	}
	return false;
}

int brett::besitzer(int x,int y)
{
	// 0==> feld frei
	// 1==> Spieler 1
	// 2==> Spieler 2
	// -1 ==> nicht auf Spielfeld

	if ((x>=0) && (x<8) && (y>0) && (y<8))
	{
		/*if (f[x+8*y]==' ') { return 0; }
		if ((int(f[x+8*y])>='A') && (int(f[x+8*y]<='Z'))) { return 1; }
		if ((int(f[x+8*y])>='a') && (int(f[x+8*y]<='z'))) { return 2; }*/
	}
	return -1;

}


