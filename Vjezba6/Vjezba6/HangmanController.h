#pragma once
#include <iostream>
#include "Hangman.h"
#include "HangmanView.h"

class HangmanController
{
public:
	HangmanController(std::shared_ptr<IHangman> hangman, std::shared_ptr<IHangmanView> hangmanView) :
	_hangman(std::move(hangman)), _hangmanView(std::move(hangmanView)) {  }

	char UserEntry() const;
	void CheckLetterAndUpdateModel(char letter) const;

	unsigned CheckIfGameIsOver() const
	{
		return _hangman->GetLives() <= 0 || _hangman->GetGuessMovie() == _hangman->GetMovie();
	}

	void DisplayGameStats() const
	{
		_hangmanView->DisplayGameStats(_hangman->GetGuessMovie(), _hangman->GetLives());
	}

	void DisplayEndGame() const
	{
		_hangmanView->DisplayEndGame(_hangman->GetMovie(), _hangman->GetLives());
	}
	
private:
	std::shared_ptr<IHangman> _hangman;
	std::shared_ptr<IHangmanView> _hangmanView;
};
