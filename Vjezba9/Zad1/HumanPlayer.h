#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(std::string name) : Player(std::move(name)) {}
	
	void ChooseCoins() override;
	int GuessCoinCount() override;
};

