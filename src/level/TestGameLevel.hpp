#pragma once

#include "GameLevel.hpp"
#include "GameObject.hpp"
#include "graphics/shader/opengl/BasicOpenGLShader.hpp"

#include "../preset/LinePreset.hpp"
#include "../preset/EventPreset.hpp"
#include "../preset/CharacterPreset.hpp"

class TestGameLevel : public GameLevel
{
public:
	void Init();
};