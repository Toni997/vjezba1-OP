#include "HangmanController.h"

void HangmanController::PlayGame() const
{
	while (!IsGameOver())
	{
		DisplayGameStats();
		CheckLetterAndUpdateModel(UserEntry());
	}

	DisplayEndGame();
}


char HangmanController::UserEntry() const
{
	auto& entries = hangman_->GetEntries();
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
	auto is_good_guess = false;
	const char letter_lower_case = std::tolower(letter);
	const auto movie = hangman_->GetMovie();
	auto movie_lower_case = movie;
	transform(movie_lower_case.begin(), movie_lower_case.end(), movie_lower_case.begin(), std::tolower);

	auto new_guess = hangman_->GetGuessMovie();
	const auto movie_size = movie_lower_case.size();

	for (size_t i = 0; i < movie_size; i++)
	{
		if (movie_lower_case.at(i) == letter_lower_case)
		{
			new_guess.at(i) = hangman_->GetMovie().at(i);
			is_good_guess = true;
		}
	}
	
	hangman_->SetGuessMovie(new_guess);
	if (!is_good_guess) hangman_->DecreaseLives();
}
