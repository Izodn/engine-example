#pragma once

#include "component/Component.hpp"
#include "core/Logger.hpp"

class CameraController : public Component
{
	public:
		void Start()
		{
		};

		void Update(double deltaTime)
		{
			if (
				Input::Pressed(Input::Key::KEY_UP)
				|| Input::Pressed(Input::Key::KEY_DOWN)
				|| Input::Pressed(Input::Key::KEY_LEFT)
				|| Input::Pressed(Input::Key::KEY_RIGHT)
			) {
				double deltaPos = 5.0f  * deltaTime;
				double deltaRad = (45.0f * (/*PI*/4*atan(1) / 180)) * deltaTime;
				Vector3* position = m_Transform->GetPosition();
				Quaternion* rotation = m_Transform->GetRotation();

				// Move Forward/Backward
				if (Input::Pressed(Input::Key::KEY_UP)) {
					*position += Vector3::Forward() * deltaPos;
				}
				if (Input::Pressed(Input::Key::KEY_DOWN)) {
					*position += Vector3::Forward() * -deltaPos;
				}

				// Turn Right/Left
				if (Input::Pressed(Input::Key::KEY_RIGHT)) {
					rotation->Rotate(Vector3::Up(), deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_LEFT)) {
					rotation->Rotate(Vector3::Up(), -deltaRad);
				}
			}
		};
};