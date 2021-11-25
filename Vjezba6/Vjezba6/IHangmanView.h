#pragma once

class IHangmanView
{
public:
	virtual ~IHangmanView() = default;
	virtual void DisplayGameStats(const std::string& guessMovie, unsigned lives) = 0;
	virtual void DisplayEndGame(const std::string& movie, unsigned lives) = 0;
};