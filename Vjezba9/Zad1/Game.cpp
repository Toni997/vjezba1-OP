#include "Game.h"
#include <iostream>

Game::Game(std::vector<Player*> players, const int pointsNeededToWin) :
	m_players(std::move(players)), m_pointsNeededToWin(pointsNeededToWin) {}

void Game::Play()
{
	while(true)
	{
		for (auto player : m_players)
		{
			std::cout << std::endl << "It's " << player->GetName() << " turn to choose coins." << std::endl << std::endl;
			HandleChooseCoins(player);
		}

		for (auto player : m_players)
		{
			std::cout << std::endl << "It's " << player->GetName() << " turn to guess opponents coins." << std::endl << std::endl;
			
			for (auto opponent : m_players)
			{
				HandleGuessCoins(player, opponent);
				if (CheckIfPlayerIsWinner(player))
				{
					HandleEndGame(player->GetName());
					return;
				}
			}
		}
	}
}

void Game::HandleChooseCoins(Player* player)
{
	player->ClearCoins();

	std::cout << "Choose coins (y y y to choose all (1 2 5), n n n to choose none):" << std::endl;
	player->ChooseCoins();

	std::cout << player->GetName() << " chose: ";
	auto& playerCoins = player->GetCoins();
	for (auto coin : playerCoins)
	{
		std::cout << coin << " ";
	}
	if (playerCoins.empty()) std::cout << "None";
	std::cout << std::endl;
}

void Game::HandleGuessCoins(Player* player, Player* opponent)
{
	if (&(*player) == &(*opponent)) return;

	std::cout << "Guess how many coins does " << opponent->GetName() << " have:" << std::endl;
	int coinCountGuess = player->GuessCoinCount();

	const int opponentCoins = opponent->GetCoinCount();
	if (coinCountGuess == opponentCoins)
	{
		player->IncrementPoints();
		std::cout << "Congrats " << player->GetName() << ", you guessed right! You now have " << player->GetPoints() << " points in total." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Sorry pal, you guessed wrong." << std::endl << std::endl;
	}
}

void Game::HandleEndGame(const std::string& name) const
{
	std::cout << std::endl << std::endl << "We have a WINNER! " << name << " is the first to reach " << m_pointsNeededToWin << " points." << std::endl;
}

bool Game::CheckIfPlayerIsWinner(Player* player) const
{
	return player->GetPoints() >= m_pointsNeededToWin;
}
