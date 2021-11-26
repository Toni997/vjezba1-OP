#include "Hangman.h"
#include "HangmanController.h"
#include "HangmanView.h"

int main()
{
	const auto hangman_ctrl = HangmanController{ std::make_unique<Hangman>(), std::make_unique<HangmanView>() };

	hangman_ctrl.PlayGame();
}
