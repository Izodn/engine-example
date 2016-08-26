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

	// Instantiate the window and attach to game
	Window window(800, 600, "Engine Test");

	game.AttachWindow(&window);

	// Instantiate the level
	TestGameLevel level;

	// Set the game to the level
	game.ChangeToLevel(&level);

	// Trigger the game run
	game.Run();

	// Cleanup
	game.Cleanup();

	return 0;
}