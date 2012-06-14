#include <iostream>

#include "chess/ui/userinterface.h"
#include "chess/chessgame.h"

using namespace std;

int main()
{
  chess::ui::UserInterface* iface = 0;

  chess::chessgame* Game = new chess::chessgame(iface);

  Game->run();



    return 0;
}
