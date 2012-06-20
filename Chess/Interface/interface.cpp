/*
 * interface.cpp
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#include "interface.h"
#include "../game/brett.h"
#include <iostream>
#include <string>
#include <limits>

void Interface::einlesen(int p)
{
	do
	{
		std::cout << "Spieler " << p << ": Bitte Zug eingeben: ";
		std::cin >> p1a >> p1b >> p2a >> p2b;

		if (std::cin.fail()==false)
		{
			break;
		}
		else
		{
		    std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	while (true);

}

void Interface::ausgabe(brett* b)
{
	std::cout << "  a b c d e f g h" << std::endl << "  ---------------" << std::endl;
	for (int i=0;i<8;i++)
	{
		std::cout << 8-i << "|";
		for (int j=0;j<8;j++)
		{
			std::cout << b->lese(j,i) << " ";
		}
		std::cout << std::endl;
	}

}

void Interface::winner(int player)
{

}

