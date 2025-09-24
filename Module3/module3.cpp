#include <iostream>

#include "multiplication.h"
#include "game.h"

int main()
{
    std::cout << "Module 3" << std::endl << std::endl;

    std::cout << "Multiplication" << std::endl;
    printMultiplicationOver3Loops();

    std::cout << std::endl << std::endl << "Now will play" << std::endl;
    const int gameCount = 10;
    for (int i = 0; i < gameCount; i++)
    {
      Game::playGame();
    }
}
