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

	std::string GetMovie() const override { return _movie; }
	std::string GetGuessMovie() const override { return _guessMovie; }
	unsigned GetLives() const override { return _lives; }
	std::set<char>& GetEntries() override { return _entries; }

	void SetMovie(const std::string& movie) override { _movie = movie; }
	void SetGuessMovie(const std::string& guessMovie) override { _guessMovie = guessMovie; }
	void SetLives(const unsigned lives) override { _lives = lives; }
	
	void ResetLives() override { _lives = 8; }
	void DecreaseLives() override { _lives--; }

	void SelectNewRandomMovie() override;

private:
	std::string _movie;
	std::string _guessMovie;
	unsigned _lives{ 8 };
	std::vector<std::string> _moviesList;
	std::set<char> _entries;

	int getRandom(int min, int max) const;
};

