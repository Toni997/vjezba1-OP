#pragma once
#include <set>

class IHangman
{
public:
	virtual ~IHangman() = default;
	
	virtual std::string GetMovie() const = 0;
	virtual std::string GetGuessMovie() const = 0;
	virtual unsigned GetLives() const = 0;
	virtual std::set<char>& GetEntries() = 0;

	virtual void SetMovie(const std::string& movie) = 0;
	virtual void SetGuessMovie(const std::string& guess_movie) = 0;
	virtual void SetLives(unsigned lives) = 0;
	
	virtual void ResetLives() = 0;
	virtual void DecreaseLives() = 0;

	virtual void SelectNewRandomMovie() = 0;
};
