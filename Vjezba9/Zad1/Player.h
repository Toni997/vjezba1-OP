#pragma once
#include <string>
#include <utility>
#include <vector>

class Player
{
public:
	Player() : m_name("Default"), m_points(0) {}
	Player(std::string name) : m_name(std::move(name)), m_points(0) {}

	virtual ~Player() = default;

	bool operator==(const Player& other)
	{
		return this == &other;
	}

	void ClearCoins() { m_coins.clear(); }
	int GetPoints() const { return m_points; }
	std::string GetName() const { return m_name; }
	std::vector<int>& GetCoins() { return m_coins; }
	int GetCoinCount();

	void IncrementCoins() { m_points++; }
	
	virtual void ChooseCoins();
	virtual int GuessCoinCount();
	
protected:
	std::string m_name;
	std::vector<int> m_coins;
	int m_points;
};

