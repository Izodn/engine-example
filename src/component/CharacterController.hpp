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
				Transform* transform = m_GameObject->GetTransform();
				Quaternion* quat = transform->GetRotation();
				Vector3 euler = quat->ToEulerAngles();

				// Roll
				if (Input::Pressed(Input::Key::KEY_E)) {
					euler.SetZ(euler.GetZ() - deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_Q)) {
					euler.SetZ(euler.GetZ() + deltaRad);
				}

				// Pitch
				if (Input::Pressed(Input::Key::KEY_W)) {
					euler.SetX(euler.GetX() - deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_S)) {
					euler.SetX(euler.GetX() + deltaRad);
				}

				// Yaw
				if (Input::Pressed(Input::Key::KEY_D)) {
					euler.SetY(euler.GetY() - deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_A)) {
					euler.SetY(euler.GetY() + deltaRad);
				}

				// Update quaternion with new rotation
				*quat = Quaternion::FromEulerAngles(euler);
			}
		};
};