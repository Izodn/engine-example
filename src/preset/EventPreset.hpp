#pragma once

#include "GameObject.hpp"
#include "ObjectPreset.hpp"
#include "component/Transform.hpp"

#include "../component/EventController.hpp"

class EventPreset : public ObjectPreset
{
	public:
		GameObject* CreateNew()
		{
			// Instantiate a normal object
			GameObject* object = new GameObject();

			// Apply our  components
			object->SetName("Event");
			(object->Components())->Add<EventController>();

			// Return the outfitted GameObject
			return object;
		};
};