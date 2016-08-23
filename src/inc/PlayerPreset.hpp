#pragma once

#include "GameObject.hpp"
#include "ObjectPreset.hpp"
#include "component/Transform.hpp"

#include "component/PlayerController.hpp"

class PlayerPreset : public ObjectPreset
{
	public:
		GameObject* CreateNew()
		{
			// Instantiate a normal object
			GameObject* object = new GameObject();

			// Apply our modifications & components
			object->SetName("Player");
			(object->Components())->Add<Transform>();
			(object->Components())->Add<PlayerController>();

			// Return the outfitted GameObject
			return object;
		};
};