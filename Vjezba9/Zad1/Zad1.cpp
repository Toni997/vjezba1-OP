#include <iostream>


#include "ComputerPlayer.h"
#include "Game.h"
#include "HumanPlayer.h"

int main()
{
	srand(time(0));
	HumanPlayer player1("Toni");
	HumanPlayer player2("Josip");
	ComputerPlayer player3("PC");
	const std::vector<Player*> players { &player1, &player2, &player3 };

	Game game(players, 5);
	game.Play();
}
