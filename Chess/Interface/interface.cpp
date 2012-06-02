/*
 * interface.cpp
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */

#include "interface.h"
#include <iostream>
#include <string>

void Interface::einlesen(int p)
{
	std::cout << "Spieler " << p << ": Bitte Zug eingeben: ";
	std::cin.getline(e,6);

	/*char c;
	int i;
	char e;
	int f;
	std::cin >> c >> i >> e >> f;

	i = 42;*/


}

void Interface::ausgabe(char (*f)[8])
{
	std::cout << "  a b c d e f g h" << std::endl << "  ---------------" << std::endl;
	for (int i=0;i<8;i++)
	{
		std::cout << 8-i << "|";
		for (int j=0;j<8;j++)
		{
			std::cout << f[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
