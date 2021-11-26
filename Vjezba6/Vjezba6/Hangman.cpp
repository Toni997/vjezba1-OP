#include "Hangman.h"
#include <fstream>
#include <functional>
#include <random>

bool IsNotAlnumOrSpace(const char ch)
{
	return !std::isalnum(static_cast<unsigned char>(ch)) && !std::isspace(static_cast<unsigned char>(ch));
}

Hangman::Hangman()
{
	std::ifstream movies("movie.txt");

	std::string temp_movie;
	while (getline(movies, temp_movie))
		movies_list_.emplace_back(temp_movie);

	movie_ = movies_list_.at(GetRandom(0, movies_list_.size() - 1));

	// remove all special characters
	movie_.erase(std::remove_if(movie_.begin(), movie_.end(),
		IsNotAlnumOrSpace), movie_.end());

	// remove all multiple spaces in a row
	auto double_space = movie_.find("  ");
	while (double_space != std::string::npos)
	{
		movie_.erase(double_space, 1);
		double_space = movie_.find("  ");
	}

	guess_movie_ = movie_;

	for(auto& ch : guess_movie_)
		if (!std::isspace(ch))
			ch = '_';

	movies.close();
}

void Hangman::SelectNewRandomMovie()
{
	SetMovie(movies_list_.at(GetRandom(0, movies_list_.size() - 1)));
}

int Hangman::GetRandom(const int min, const int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	const std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	return uni(rng);
}
