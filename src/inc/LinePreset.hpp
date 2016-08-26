#pragma once

#include "GameObject.hpp"
#include "ObjectPreset.hpp"
#include "component/Transform.hpp"

#include "component/LineDrawController.hpp"

class LinePreset : public ObjectPreset
{
	public:
		GameObject* CreateNew()
		{
			// Instantiate a normal object
			GameObject* object = new GameObject();

			// Apply our modifications & components
			object->SetName("Line");
			(object->Components())->Add<Transform>();
			(object->Components())->Add<LineDrawController>();

			// Return the outfitted GameObject
			return object;
		};
};