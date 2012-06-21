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
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
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

	display=SDL_SetVideoMode(630,670,24,SDL_SWSURFACE);
	if (display==NULL)
	{
		std::cout << "Fehler beim Erzeugen der Oberfl‰che." << std::endl;
		std::cin.get();
		exit(-1);
	}

	SDL_WM_SetCaption("Schach", "Schach");

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
	if (TTF_Init()==-1)
	{
		std::cout << "Fehler beim Starten der Textausgabe." << std::endl;
		std::cin.get();
		exit(-1);
	}

	TTF_Font* font;
	font=TTF_OpenFont("font/JOURNAL.ttf",24);
	if (font==NULL)
	{
		std::cout << "Schrift konnte nicht geladen werden." << std::endl;
		std::cin.get();
		exit(-1);
	}

	char text[]="Spieler 1 am Zug!";
	text[8]=48+p;

	SDL_Color textcolor;
	textcolor.r=0;
	textcolor.g=0;
	textcolor.b=0;

	SDL_Surface* nachricht=TTF_RenderText_Blended(font,text,textcolor);

	SDL_Rect bereich;
	bereich.x=0;
	bereich.y=0;
	bereich.w=630;
	bereich.h=20;

	SDL_BlitSurface(nachricht,NULL,display,&bereich);
	SDL_UpdateRects(display,1,&bereich);
	SDL_FreeSurface(nachricht);


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
	int sy=(int) ((start.y-81)/66);
	int ex=(int) ((ende.x-51)/66);
	int ey=(int) ((ende.y-81)/66);

	//std::cout << sx << "-" << sy << std::endl;
	//std::cout << ex << "-" << ey << std::endl;

	p1a=char(int('a')+sx);
	p1b=8-sy;

	p2a=char(int('a')+ex);
	p2b=8-ey;

}


void Interfaceb::winner(int player)
{
	if (TTF_Init()==-1)
	{
		std::cout << "Fehler beim Starten der Textausgabe." << std::endl;
		std::cin.get();
		exit(-1);
	}

	TTF_Font* font;
	font=TTF_OpenFont("font/JOURNAL.ttf",90);
	if (font==NULL)
	{
		std::cout << "Schrift konnte nicht geladen werden." << std::endl;
		std::cin.get();
		exit(-1);
	}

	char text[]="Spieler 1 hat gewonnen!";
	text[8]=48+player;

	SDL_Color textcolor;
	textcolor.r=0;
	textcolor.g=0;
	textcolor.b=0;

	SDL_Surface* nachricht=TTF_RenderText_Blended(font,text,textcolor);

	SDL_Rect bereich;
	bereich.x=50;
	bereich.y=300;
	bereich.w=530;
	bereich.h=70;

	SDL_BlitSurface(nachricht,NULL,display,&bereich);
	SDL_UpdateRects(display,1,&bereich);
	SDL_FreeSurface(nachricht);

	bool exitLoop=false;
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
		case SDL_QUIT:
			exitLoop=true;
			exit(-1);
			break;
		default:
			break;
		}
	}
}

void Interfaceb::ausgabe(brett* b)
{
	SDL_Surface* image=NULL;

	//Hintergrund einf¸gen
	image = IMG_Load("image/feld.png");
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

				char datei[]="image/bs.png";
				datei[6]=tolower(l);

				if (tolower(l)!=l) //Groﬂbuchstabe->weiﬂe Figur
				{
					datei[7]='w';
				}

				figur = IMG_Load(datei);

				if (figur==NULL)
				{
					std::cout << "Grafik nicht verfuegbar." << std::endl;
					std::cin.get();
					exit(-1);
				}

				bereich.x=59+j*66;
				bereich.y=89+i*66;
				bereich.w=50;
				bereich.h=50;

				SDL_BlitSurface(figur,NULL,display,&bereich);
			}
		}
	}

	SDL_Flip(display);

}
