// DeadMansDraw-Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game_title.h" 
#include "Game.h"

int main()
{
    std::cout << GAME_TITLE << std::endl; 
    std::cout << "Starting Dead Man's Draw++!\n";
    Game game;
    game.startGame();
    return 0;
}