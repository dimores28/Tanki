#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	//setlocale(LC_CTYPE, "rus");
	Game _game;
	Game *ToGame;
	ToGame = &_game;

	do {
		_game.Render();
		_game.Update();
	} while (ToGame->IsGameActiv);
	_game.Sutdown();

	return 0;
}

