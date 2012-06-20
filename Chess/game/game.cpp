/*
 * game.cpp
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#include <iostream>

#include "game.h"
#include "brett.h"
#include "../Piece/piece.h"
#include "../Piece/bauer.h"
#include "../Piece/dame.h"
#include "../Piece/koenig.h"
#include "../Piece/lauefer.h"
#include "../Piece/springer.h"
#include "../Piece/turm.h"



Game::Game()
{
	b=new brett();
	for (int i=0;i<8;i++)
	{
		b->schreibe(i,1,'b');
		figur[i]=new Bauer(i,1,2);
		b->schreibe(i,6,'B');
		figur[i+8]=new Bauer(i,6,1);
	}

	b->schreibe(0,0,'t'); figur[16]=new Turm(0,0,2);
	b->schreibe(1,0,'s'); figur[17]=new Springer(1,0,2);
	b->schreibe(2,0,'l'); figur[18]=new Laeufer(2,0,2);
	b->schreibe(3,0,'d'); figur[19]=new Dame(3,0,2);
	b->schreibe(4,0,'k'); figur[20]=new Koenig(4,0,2);
	b->schreibe(5,0,'l'); figur[21]=new Laeufer(5,0,2);
	b->schreibe(6,0,'s'); figur[22]=new Springer(6,0,2);
	b->schreibe(7,0,'t'); figur[23]=new Turm(7,0,2);

	b->schreibe(0,7,'T'); figur[24]=new Turm(0,7,1);
	b->schreibe(1,7,'S'); figur[25]=new Springer(1,7,1);
	b->schreibe(2,7,'L'); figur[26]=new Laeufer(2,7,1);
	b->schreibe(3,7,'D'); figur[27]=new Dame(3,7,1);
	b->schreibe(4,7,'K'); figur[28]=new Koenig(4,7,1);
	b->schreibe(5,7,'L'); figur[29]=new Laeufer(5,7,1);
	b->schreibe(6,7,'S'); figur[30]=new Springer(6,7,1);
	b->schreibe(7,7,'T'); figur[31]=new Turm(7,7,1);

	end=false;
	activeplayer=1;

	aus.ausgabe(b);
	return;
}

Game::~Game()
{
	delete b;
}

void Game::zug()
{
	do
	{
		do
		{
			aus.einlesen(activeplayer);
		}
		while (aendern(aus.p1a,aus.p1b,aus.p2a,aus.p2b)==false);

		aus.ausgabe(b);

		//Überprüfe,ob König vorhanden
		bool k1=false;
		bool k2=false;

		for (int i=0;i<8;i++)
		{
			for (int j=0;j<8;j++)
			{
				if (b->lese(i,j)=='K') { k1=true; }
				if (b->lese(i,j)=='k') { k2=true; }
			}
		}

		if ((k1==false) || (k2==false))
		{
			end=true;
			aus.winner(activeplayer);
			std::cout << "Spieler " << activeplayer << " hat gewonnen." << std::endl;
		}

		//Spieler ändern
		activeplayer++;
		if (activeplayer==3) { activeplayer=1; }

	}
	while (end==false);
}

int Game::aendern(char a,int be,char c,int d)
{
	int x1=int(a)-'a';
	int x2=int(c)-'a';
	int y1=8-be;
	int y2=8-d;

	//std::cout << x1 << "/" << y1 << " to " << x2 << "/" << y2 << std::endl;

	int nummer=-1;
	for (int i=0;i<32;i++)
	{
		if (figur[i]->IsPosition(x1,y1,activeplayer)==true)
		{
			nummer=i;
		}
	}
	//std::cout << "Nummer: " << nummer << std::endl;
	if (nummer==-1) { return false; }

	if ((x1==x2) && (y1==y2)) { return false; }

	if ((x1<0) || (x1>7)) { return false; }
	if ((x2<0) || (x2>7)) { return false; }
	if ((y1<0) || (y1>7)) { return false; }
	if ((y2<0) || (y2>7)) { return false; }

	if (figur[nummer]->bewegungmoeglich(x2,y2,b)==false)
	{
		return false;
	}

	//Auf geschlagene Figuren untersuchen
	int anderer;
	if (activeplayer==1) { anderer=2; } else { anderer=1; }
	for (int i=0;i<32;i++)
	{
		if (figur[i]->IsPosition(x2,y2,anderer)==true)
		{
			figur[i]->geschlagen();
		}
	}


	figur[nummer]->move(x2,y2,b);
	return true;
}




