#include "TestGameLevel.hpp"

void TestGameLevel::Init()
{
	//Shaders
	m_Game->RegisterShader<BasicOpenGLShader>();

	// Presets
	EventPreset eventPreset;
	LinePreset linePreset;
	CharacterPreset characterPreset;

	// Add object using preset
	m_GameObjects.push_back(eventPreset.CreateNew());

	// Add the player
	GameObject* player = characterPreset.CreateNew();
	player->RenderComponents()->Get<FillSquare>()->SetShader(
		m_Game->GetWindow()->GetRenderer()->Shaders()->Get<BasicOpenGLShader>()
	);
	m_GameObjects.push_back(player);

}