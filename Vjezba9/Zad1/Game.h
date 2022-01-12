#pragma once
#include "Player.h"

class Game
{
public:
	Game(std::vector<Player*> players, const int pointsNeededToWin) :
		m_players(std::move(players)), m_pointsNeededToWin(pointsNeededToWin) {}
	
	void Play();
	std::vector<Player*>& GetPlayers() {return m_players; }
	int GetPointsNeededToWin() const { return m_pointsNeededToWin; }

private:
	void HandleChooseCoins(Player* player);
	void HandleEndGame(const Player* winner) const;
	
private:
	std::vector<Player*> m_players;
	int m_pointsNeededToWin;
};

