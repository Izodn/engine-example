#include "inc/TestGameLevel.hpp"

TestGameLevel::TestGameLevel()
{

}

void TestGameLevel::Init()
{
	// Presets
	EventPreset eventPreset;
	LinePreset linePreset;

	// Add object using preset
	m_GameObjects.push_back(eventPreset.CreateNew());
	m_GameObjects.push_back(linePreset.CreateNew());
}