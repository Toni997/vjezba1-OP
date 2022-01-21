#pragma once
#include "Player.h"

class Game
{
public:
	Game(std::vector<Player*> players, const int pointsNeededToWin);
	
	void Play();
	//std::vector<Player*>& GetPlayers() { return m_players; }
	//int GetPointsNeededToWin() const { return m_pointsNeededToWin; }

private:
	void HandleChooseCoins(Player* player);
	void HandleGuessCoins(Player* player, Player* opponent);
	void HandleEndGame(const std::string& name) const;
	bool CheckIfPlayerIsWinner(Player* player) const;
	
private:
	std::vector<Player*> m_players;
	int m_pointsNeededToWin;
};

