/*
 * interfaceb.cpp
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#include "interfaceb.h"
#include "../game/brett.h"
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <ctype.h>

Interfaceb::Interfaceb()
{

	//Initalisiere SDL
	int res=SDL_Init(SDL_INIT_VIDEO);
	if (res!=0)
	{
		std::cout << "Fehler bei Initalisieren von SDL." << std::endl;
		std::cin.get();
		exit(-1);
	}

	display=SDL_SetVideoMode(630,650,24,SDL_SWSURFACE);
	if (display==NULL)
	{
		std::cout << "Fehler beim Erzeugen der Oberfläche." << std::endl;
		std::cin.get();
		exit(-1);
	}

}

Interfaceb::~Interfaceb()
{
	if (display!=NULL)
	{
		SDL_FreeSurface(display);
	}
	SDL_Quit();

}

void Interfaceb::einlesen(int p)
{
	bool exitLoop=false;
	SDL_Rect mouse,start,ende;

	while (!exitLoop)
	{
		SDL_Event event;

		if (0==SDL_WaitEvent(&event))
		{
			std::cout << "Fehler beim Warten auf Event." << std::endl;
			std::cin.get();
			exitLoop=true;
		}

		switch(event.type)
		{
		case SDL_MOUSEMOTION:
			mouse.x=event.motion.x;
			mouse.y=event.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			start=mouse;
			break;
		case SDL_MOUSEBUTTONUP:
			ende=mouse;
			exitLoop=true;
			break;
		case SDL_QUIT:
			exitLoop=true;
			exit(-1);
			break;
		default:
			break;
		}
	}

	//std::cout << start.x << "-" << start.y << std::endl;
	//std::cout << ende.x << "-" << ende.y << std::endl;

	int sx=(int) ((start.x-51)/66);
	int sy=(int) ((start.y-61)/66);
	int ex=(int) ((ende.x-51)/66);
	int ey=(int) ((ende.y-51)/66);

	//std::cout << sx << "-" << sy << std::endl;
	//std::cout << ex << "-" << ey << std::endl;

	p1a=char(int('a')+sx);
	p1b=8-sy;

	p2a=char(int('a')+ex);
	p2b=8-ey;

	/*std::cout << "Spieler " << p << ": Bitte Zug eingeben: ";

	std::cin >> p1a >> p1b >> p2a >> p2b;

	while(std::cin.bad() || std::cin.fail())
	    {
			    std::cin.clear();
	            std::cin.ignore(100, '\n');
	            std::cout << "Spieler " << p << ": Bitte Zug eingeben: ";
				std::cin >> p1a >> p1b >> p2a >> p2b;
		}*/


}


void Interfaceb::winner(int player)
{

}

void Interfaceb::ausgabe(brett* b)
{
	SDL_Surface* image=NULL;

	//Hintergrund einfügen
	image = SDL_LoadBMP("image/feld.bmp");
	if (image==NULL)
	{
		std::cout << "Grafik nicht verfuegbar." << std::endl;
		std::cin.get();
		exit(-1);
	}

	SDL_BlitSurface(image,NULL,display,NULL);
	SDL_FreeSurface(image);
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			char l=b->lese(j,i);

			if (l!=' ')
			{
				SDL_Surface* figur;
				SDL_Rect bereich;

				char datei[]="image/bs.bmp";
				datei[6]=tolower(l);

				if (tolower(l)!=l) //Großbuchstabe->weiße Figur
				{
					datei[7]='w';
				}

				figur = SDL_LoadBMP(datei);

				if (figur==NULL)
				{
					std::cout << "Grafik nicht verfuegbar." << std::endl;
					std::cin.get();
					exit(-1);
				}

				bereich.x=59+j*66;
				bereich.y=69+i*66;
				bereich.w=50;
				bereich.h=50;

				SDL_BlitSurface(figur,NULL,display,&bereich);
			}
		}
	}

	SDL_Flip(display);

}
