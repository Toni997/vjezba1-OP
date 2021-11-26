#pragma once
#include <iostream>
#include "Hangman.h"
#include "HangmanView.h"

class HangmanController
{
public:
	HangmanController(std::unique_ptr<IHangman> hangman, std::unique_ptr<IHangmanView> hangman_view) :
	hangman_(std::move(hangman)), hangman_view_(std::move(hangman_view)) {  }

	void PlayGame() const;

private:
	char UserEntry() const;
	void CheckLetterAndUpdateModel(char letter) const;

	bool IsGameOver() const
	{
		return hangman_->GetLives() <= 0 || hangman_->GetGuessMovie() == hangman_->GetMovie();
	}

	void DisplayGameStats() const
	{
		hangman_view_->DisplayGameStats(hangman_->GetGuessMovie(), hangman_->GetLives());
	}

	void DisplayEndGame() const
	{
		hangman_view_->DisplayEndGame(hangman_->GetMovie(), hangman_->GetLives());
	}
	
	std::unique_ptr<IHangman> hangman_;
	std::unique_ptr<IHangmanView> hangman_view_;
};
