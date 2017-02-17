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

	double xPos = -6.0f;
	double yPos = 6.0f;
	for (uint16_t i = 0; i < 49; i++) {
		if (xPos > 6.0f) {
			yPos -= 2.0f;
			xPos = -6.0f;
		}

		GameObject* obj = characterPreset.CreateNew();
		obj->RenderComponents()->Get<TestGL>()->SetShader(
			m_Game->GetWindow()->GetRenderer()->Shaders()->Get<TextureOpenGLShader>()
		);
		m_GameObjects.push_back(obj);
		obj->GetTransform()->SetPosition(Vector3(xPos, yPos, -13.0f));
		xPos += 2.0f;
	}
}