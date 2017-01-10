#pragma once

#include "GameLevel.hpp"
#include "GameObject.hpp"
#include "../graphics/inc/BasicOpenGLShader.hpp"

#include "LinePreset.hpp"
#include "EventPreset.hpp"
#include "CharacterPreset.hpp"

class TestGameLevel : public GameLevel
{
public:
	TestGameLevel();
	void Init();
};