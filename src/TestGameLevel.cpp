#include "inc/TestGameLevel.hpp"

TestGameLevel::TestGameLevel()
{

}

void TestGameLevel::Init()
{
	// Presets
	LinePreset linePreset;

	// Add object using preset
	m_GameObjects.push_back(linePreset.CreateNew());
}