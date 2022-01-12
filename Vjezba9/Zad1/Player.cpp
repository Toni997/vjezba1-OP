#include "Player.h"
#include <numeric>

int Player::GetCoinCount()
{
	return std::accumulate(m_coins.begin(), m_coins.end(), 0);
}

void Player::ChooseCoins()
{
	
}

int Player::GuessCoinCount()
{
	return 0;
}
