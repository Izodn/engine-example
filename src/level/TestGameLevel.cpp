#include "TestGameLevel.hpp"
#include "maths/Vector3.hpp"

void TestGameLevel::Init()
{
	//Shaders
	m_Game->RegisterShader<TextureOpenGLShader>();

	// Presets
	EventPreset eventPreset;
	CharacterPreset characterPreset;

	// Add object using preset
	m_GameObjects.push_back(eventPreset.CreateNew());

	// Add the player
	GameObject* player = characterPreset.CreateNew();
	player->RenderComponents()->Get<TestGL>()->SetShader(
		m_Game->GetWindow()->GetRenderer()->Shaders()->Get<TextureOpenGLShader>()
	);
	m_GameObjects.push_back(player);
}