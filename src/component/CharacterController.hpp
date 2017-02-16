#pragma once

#include "component/Component.hpp"
#include "core/Logger.hpp"

class CharacterController : public Component
{
	private:
		int m_WindowWidth;
		int m_WindowHeight;

	public:
		void Start()
		{
			Window* window =  m_GameObject->GetLevel()->GetGame()->GetWindow();
			m_WindowWidth = window->GetWidth();
			m_WindowHeight = window->GetHeight();
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
			} else if (Input::Pressed(Input::Key::MOUSE_ONE)) {
				Quaternion* quat = m_GameObject->GetTransform()->GetRotation();
				double mouseX = Input::GetAxis(Input::Axis::HORIZONTAL);
				double mouseY = Input::GetAxis(Input::Axis::VERTICAL);

				double gridX = mouseX - (m_WindowWidth / 2);
				double gridY = mouseY - (m_WindowHeight / 2);
				Vector3 target = Vector3(-gridX, gridY, 100.0f);

				*quat = Quaternion::LookAt(
					*(m_GameObject->GetTransform()->GetPosition()),
					target
				);
			}
		};
};