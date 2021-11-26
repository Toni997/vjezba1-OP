#pragma once
#include <string>
#include "IHangmanView.h"

class HangmanView final : public IHangmanView
{
public:
	void DisplayGameStats(const std::string& guess_movie, unsigned lives) override;
	void DisplayEndGame(const std::string& movie, unsigned lives) override;
};

