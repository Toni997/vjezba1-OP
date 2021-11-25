#include "HangmanController.h"

char HangmanController::UserEntry() const
{
	auto& entries = _hangman->GetEntries();
	char letter{};
	
	while (!std::isalnum(letter) || entries.find(std::tolower(letter)) != entries.end())
	{
		std::cout << "Enter your guess:" << std::endl;
		std::cin >> letter;
	}

	entries.insert(std::tolower(letter));
	return letter;
}

void HangmanController::CheckLetterAndUpdateModel(const char letter) const
{
	auto isGoodGuess = false;
	const char letterLowerCase = std::tolower(letter);
	const auto movie = _hangman->GetMovie();
	auto movieLowerCase = movie;
	transform(movieLowerCase.begin(), movieLowerCase.end(), movieLowerCase.begin(), std::tolower);

	auto newGuess = _hangman->GetGuessMovie();
	const auto movieSize = movieLowerCase.size();

	for (size_t i = 0; i < movieSize; i++)
	{
		if (movieLowerCase.at(i) == letterLowerCase)
		{
			newGuess.at(i) = _hangman->GetMovie().at(i);
			isGoodGuess = true;
		}
	}
	
	_hangman->SetGuessMovie(newGuess);
	if (!isGoodGuess) _hangman->DecreaseLives();
}
