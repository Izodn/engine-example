#pragma once

#include "component/Component.hpp"
#include "core/Logger.hpp"

class CharacterController : public Component
{
	public:
		void Start()
		{

		};

		void Update(double deltaTime)
		{
			if (
				Input::Pressed(Input::Key::KEY_W)
				|| Input::Pressed(Input::Key::KEY_A)
				|| Input::Pressed(Input::Key::KEY_S)
				|| Input::Pressed(Input::Key::KEY_D)
				|| Input::Pressed(Input::Key::KEY_Q)
				|| Input::Pressed(Input::Key::KEY_E)
			) {
				double deltaRad = (90.0f * (/*PI*/4*atan(1) / 180)) * deltaTime;
				Quaternion* quat = m_GameObject->GetTransform()->GetRotation();

				// Roll
				if (Input::Pressed(Input::Key::KEY_E)) {
					quat->Rotate(Vector3::Forward(), -deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_Q)) {
					quat->Rotate(Vector3::Forward(), deltaRad);
				}

				// Pitch
				if (Input::Pressed(Input::Key::KEY_W)) {
					quat->Rotate(Vector3::Right(), -deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_S)) {
					quat->Rotate(Vector3::Right(), deltaRad);
				}

				// Yaw
				if (Input::Pressed(Input::Key::KEY_D)) {
					quat->Rotate(Vector3::Up(), -deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_A)) {
					quat->Rotate(Vector3::Up(), deltaRad);
				}
			}
		};
};