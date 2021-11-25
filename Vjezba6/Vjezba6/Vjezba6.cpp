#include "Hangman.h"
#include "HangmanController.h"
#include "HangmanView.h"

int main()
{
	const auto hangman = std::make_shared<Hangman>();
	const auto hangmanView = std::make_shared<HangmanView>();

	const auto hangmanController = HangmanController{ hangman, hangmanView };

	while(!hangmanController.CheckIfGameIsOver())
	{
		hangmanController.DisplayGameStats();
		const auto letter = hangmanController.UserEntry();
		hangmanController.CheckLetterAndUpdateModel(letter);
	}

	hangmanController.DisplayEndGame();
}
