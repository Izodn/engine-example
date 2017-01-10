#pragma once

#include "GameObject.hpp"
#include "ObjectPreset.hpp"
#include "component/Transform.hpp"
#include "component/FillSquare.hpp"

#include "component/CharacterController.hpp"

class CharacterPreset : public ObjectPreset
{
	public:
		GameObject* CreateNew()
		{
			// Instantiate a normal object
			GameObject* object = new GameObject();

			// Apply our modifications & components
			object->SetName("Character");
			(object->Components())->Add<Transform>();
			(object->Components())->Add<CharacterController>();
			(object->RenderComponents())->Add<FillSquare>();

			// Return the outfitted GameObject
			return object;
		};
};