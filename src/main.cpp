#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

#include "inc/TestGameLevel.hpp"

int main(int argc, char** args)
{
	// Instantiate the game
	Game game;

	// Set the logic tick rate
	game.UpdateTickRate(300);

	// Change the resolution & change the window title
	game.GetWindow()->SetResolution(800, 600);
	game.GetWindow()->SetTitle("One Month - 201609");

	// Instantiate the level
	TestGameLevel* level = new TestGameLevel();

	// Set the game to the level
	game.ChangeToLevel(level);

	// Trigger the game run
	game.Run();

	return 0;
}