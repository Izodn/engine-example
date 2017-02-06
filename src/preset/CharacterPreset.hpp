#pragma once

#include "GameObject.hpp"
#include "ObjectPreset.hpp"
#include "component/TestGL.hpp"

#include "../component/CharacterController.hpp"

class CharacterPreset : public ObjectPreset
{
	public:
		GameObject* CreateNew()
		{
			// Instantiate a normal object
			GameObject* object = new GameObject();

			// Apply our modifications & components
			object->SetName("Character");
			(object->Components())->Add<CharacterController>();
			(object->RenderComponents())->Add<TestGL>();

			object->GetTransform()->SetRotation(
				Quaternion::FromAxisAngle(
					Vector3::Forward(),
					0.0f
				)
			);

			// Return the outfitted GameObject
			return object;
		};
};