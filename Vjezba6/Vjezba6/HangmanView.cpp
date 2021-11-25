#include <iostream>
#include "HangmanView.h"

void HangmanView::DisplayGameStats(const std::string& guessMovie, const unsigned lives)
{
	switch(lives)
	{
	    case 1:
		    std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |      /|\
	    |       |
	    |      /
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 2:
		    std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |      /|\
	    |       |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 3:
		    std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |      /|\
	    |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 4:
		    std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |      /|
	    |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 5:
		    std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |      /
	    |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 6:
		    std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |
	    |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 7:
		    std::cout << R"(
	    _________
	    | /     |
	    |/
	    |
	    |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    case 8:
		    std::cout << R"(
	    _________
	    | /
	    |/
	    |
	    |
	    |
	    |
	    |
	    |
	    |
	____|____
	    )";
	    break;
	    default: return;
	}
    std::cout << std::endl;
    std::cout << "Lives: " << lives << std::endl;
    std::cout << "Guess: " << guessMovie << std::endl;
}

void HangmanView::DisplayEndGame(const std::string& movie, const unsigned lives)
{
	if(lives <= 0)
	{
		std::cout << R"(
	    _________
	    | /     |
	    |/      O
	    |      /|\
	    |       |
	    |      / \
	    |
	    |
	    |
	    |
	____|____
	    )";
		std::cout << std::endl << "GAME OVER!" << std::endl << std::endl;
		std::cout << "Correct answer: " << movie << std::endl;
	}
	else
	{
		std::cout << std::endl << "WIN!" << std::endl << std::endl;
		std::cout << "Movie: " << movie << std::endl << std::endl;
	}
}

