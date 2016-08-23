#include <iostream>

#include "Game.hpp"
#include "Window.hpp"

#include "inc/TestGameLevel.hpp"

int main(int argc, char** args)
{
	// Instantiate the game
	Game* game = new Game();

	// Instantiate the window and attach to game
	Window* window = new Window(800, 600, "Engine Test");
	game->AttachWindow(window);

	// Instantiate the level
	TestGameLevel* level = new TestGameLevel();

	// Set the game to the level
	game->ChangeToLevel(level);

	// Trigger the game run
	game->Run();

	return 0;
}