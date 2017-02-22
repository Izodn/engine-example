#pragma once

#include "GameLevel.hpp"
#include "GameObject.hpp"
#include "graphics/shader/opengl/TextureOpenGLShader.hpp"

#include "../preset/EventPreset.hpp"
#include "../preset/CameraPreset.hpp"
#include "../preset/CharacterPreset.hpp"

class TestGameLevel : public GameLevel
{
public:
	void Init();
};