/*
 * chess.cpp
 *
 *  Created on: 30.05.2012
 *      Author: Thomas
 */
#include <iostream>
#include <string>

#include "Interface/interface.h"
#include "Interface/interfaceb.h"
#include "Game/game.h"


#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCMd) {
#else
int main() {
#endif
	Game Spiel;
	Spiel.zug();
	return true;
}
