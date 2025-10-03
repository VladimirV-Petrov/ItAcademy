#include <iostream>
#include <cstdlib>  

#include "game.h"

namespace Game
{
	/// <summary>
	/// Выдает произвольное число от -5 до 5, чередуя отрицательные и положительные в зависимости от итерации.
	/// </summary> 
	/// <param name="iteration">Итерация</param>
	/// <returns>Произвольное число от -5 до 5</returns>
	int getNextValueForPlayer(int iteration)
	{
		auto randomNumber = rand() % 6; 

		//для четных будет "-"
		return (iteration % 2 == 0) ? -randomNumber : randomNumber;
	}

	void playGame()
	{
		int playerOneScore = 0;
		int playerTwoScore = 0;

		const int maxSteps = 100;
		//При 50 практически всегда ничья. Лучше ставить 20.
		const int gameLimit = 20;

		for (int iterator = 0; iterator < maxSteps; iterator++)
		{
			playerOneScore += getNextValueForPlayer(iterator);
			playerTwoScore += getNextValueForPlayer(iterator);

			if (playerOneScore > gameLimit && playerOneScore != playerTwoScore)
			{
				std::cout << "Player 1 won with " << playerOneScore << " points." << std::endl << std::endl;
				return;
			}

			if (playerTwoScore > gameLimit && playerOneScore != playerTwoScore)
			{
				std::cout << "Player 2 won with " << playerTwoScore << " points" << std::endl << std::endl;
				return;
			}

			if (playerOneScore > gameLimit && playerOneScore == playerTwoScore)
			{
				std::cout << "Tie. Both players scored " << playerOneScore << " points." << std::endl << std::endl;
				return;
			}
		}

		std::cout << "Tie" << std::endl;
		std::cout <<  "	Player 1 with " << playerOneScore << " points." << std::endl;
		std::cout <<  "	Player 2 with " << playerTwoScore << " points." << std::endl << std::endl;
	}
}
