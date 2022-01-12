#include "Game.h"
#include <iostream>

void Game::Play()
{
	while(true)
	{
		for (auto* player : m_players)
		{
			std::cout << std::endl << "It's " << player->GetName() << " turn to choose coins." << std::endl << std::endl;
			HandleChooseCoins(player);
		}

		for (auto* player : m_players)
		{
			std::cout << std::endl << "It's " << player->GetName() << " turn to guess opponents coins." << std::endl << std::endl;
			
			for (auto* opponent : m_players)
			{
				if (*player == *opponent) continue;
				
				std::cout << "Guess how many coins does " << opponent->GetName() << " have:" << std::endl;
				const int coinCountGuess = player->GuessCoinCount();
				
				const int opponentCoins = opponent->GetCoinCount();
				if (coinCountGuess == opponentCoins)
				{
					player->IncrementCoins();
					std::cout << "Congrats " << player->GetName() << ", you guessed right! You now have " << player->GetPoints() << " points in total." << std::endl << std::endl;
				}
				else
				{
					std::cout << "Sorry pal, you guessed wrong." << std::endl << std::endl;

				}

				if (player->GetPoints() >= m_pointsNeededToWin)
				{
					HandleEndGame(player);
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

void Game::HandleEndGame(const Player* winner) const
{
	std::cout << std::endl << std::endl << "We have a WINNER! " << winner->GetName() << " is the first to reach " << m_pointsNeededToWin << " points." << std::endl;
}
