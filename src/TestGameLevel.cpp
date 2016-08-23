#include "inc/TestGameLevel.hpp"

TestGameLevel::TestGameLevel()
{

}

void TestGameLevel::Init()
{
	// Presets
	PlayerPreset playerPreset;

	// Add object using preset
	m_GameObjects.push_back(playerPreset.CreateNew());
}