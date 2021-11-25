#include "Hangman.h"
#include <fstream>
#include <functional>
#include <random>

bool isNotAlnumOrSpace(char ch)
{
	return !std::isalnum(static_cast<unsigned char>(ch)) && !std::isspace(static_cast<unsigned char>(ch));
}

Hangman::Hangman()
{
	std::ifstream movies("movie.txt");

	std::string tempMovie;
	while (getline(movies, tempMovie))
		_moviesList.emplace_back(tempMovie);

	_movie = _moviesList.at(getRandom(0, _moviesList.size() - 1));

	// remove all special characters
	_movie.erase(std::remove_if(_movie.begin(), _movie.end(),
		isNotAlnumOrSpace), _movie.end());

	// remove all multiple spaces in a row
	auto doubleSpace = _movie.find("  ");
	while (doubleSpace != std::string::npos)
	{
		_movie.erase(doubleSpace, 1);
		doubleSpace = _movie.find("  ");
	}

	_guessMovie = _movie;

	for(auto& ch : _guessMovie)
		if (!std::isspace(ch))
			ch = '_';

	movies.close();
}

void Hangman::SelectNewRandomMovie()
{
	SetMovie(_moviesList.at(getRandom(0, _moviesList.size() - 1)));
}

int Hangman::getRandom(const int min, const int max) const
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	return uni(rng);
}
