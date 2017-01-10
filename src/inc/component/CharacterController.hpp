#pragma once

#include <iostream>

#include "component/Component.hpp"

class CharacterController : public Component
{
	public:
		void Start()
		{

		};

		void Update()
		{
			if (Input::Pressed(Input::Key::KEY_W)) {
				// Run forward
			}
		};
};