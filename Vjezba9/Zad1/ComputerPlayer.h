#pragma once
#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(std::string name) : Player(std::move(name)) {}
	
	void ChooseCoins() override;
	int GuessCoinCount() override;

private:
	const std::vector<int> m_possibleCounts { 0, 1, 2, 5, 3, 8, 7, 6 };
};

