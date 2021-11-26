#pragma once
#include <string>
#include <random>
#include <vector>
#include <set>
#include "IHangman.h"

class Hangman final : public IHangman
{
public:
	Hangman();

	std::string GetMovie() const override { return movie_; }
	std::string GetGuessMovie() const override { return guess_movie_; }
	unsigned GetLives() const override { return lives_; }
	std::set<char>& GetEntries() override { return entries_; }

	void SetMovie(const std::string& movie) override { movie_ = movie; }
	void SetGuessMovie(const std::string& guess_movie) override { guess_movie_ = guess_movie; }
	void SetLives(const unsigned lives) override { lives_ = lives; }
	
	void ResetLives() override { lives_ = 8; }
	void DecreaseLives() override { lives_--; }

	void SelectNewRandomMovie() override;

private:
	std::string movie_;
	std::string guess_movie_;
	unsigned lives_{ 8 };
	std::vector<std::string> movies_list_;
	std::set<char> entries_;

	static int GetRandom(int min, int max);
};

