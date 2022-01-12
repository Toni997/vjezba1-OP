#include "ComputerPlayer.h"
#include <iostream>

void ComputerPlayer::ChooseCoins()
{
	bool shouldAdd = rand() % 2;
	if (shouldAdd) m_coins.push_back(1);
	
	shouldAdd = rand() % 2;
	if (shouldAdd) m_coins.push_back(2);
	
	shouldAdd = rand() % 2;
	if (shouldAdd) m_coins.push_back(5);
}

int ComputerPlayer::GuessCoinCount()
{
	int guess = rand() % m_possibleCounts.size();
	return m_possibleCounts.at(guess);
}
