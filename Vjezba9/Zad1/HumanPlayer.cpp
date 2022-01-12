#include "HumanPlayer.h"
#include <iostream>

void HumanPlayer::ChooseCoins()
{
	char choice = 0;

	std::cin >> choice;
	while (choice != 'y' && choice != 'n')
		std::cin >> choice;
	
	if (choice == 'y') m_coins.push_back(1);

	std::cin >> choice;
	while (choice != 'y' && choice != 'n')
		std::cin >> choice;

	if (choice == 'y') m_coins.push_back(2);

	std::cin >> choice;
	while (choice != 'y' && choice != 'n')
		std::cin >> choice;
		
	if (choice == 'y') m_coins.push_back(5);
}

int HumanPlayer::GuessCoinCount()
{
	int guess = 0;
	std::cin >> guess;
	return guess;
}
