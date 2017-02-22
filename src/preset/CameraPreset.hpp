#pragma once

#include "GameObject.hpp"
#include "ObjectPreset.hpp"
#include "component/CameraComponent.hpp"

#include "../component/CameraController.hpp"

class CameraPreset : public ObjectPreset
{
	public:
		GameObject* CreateNew()
		{
			// Instantiate a normal object
			GameObject* object = new GameObject();

			// Apply our modifications & components
			object->SetName("Camera");
			(object->Components())->Add<CameraComponent>();
			(object->Components())->Add<CameraController>();

			// Position camera
			object->GetTransform()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));

			// Face camera forward
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