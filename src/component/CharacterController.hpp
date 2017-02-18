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
				Quaternion* rotation = m_Transform->GetRotation();

				// Roll
				if (Input::Pressed(Input::Key::KEY_E)) {
					rotation->Rotate(Vector3::Forward(), -deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_Q)) {
					rotation->Rotate(Vector3::Forward(), deltaRad);
				}

				// Pitch
				if (Input::Pressed(Input::Key::KEY_W)) {
					rotation->Rotate(Vector3::Right(), -deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_S)) {
					rotation->Rotate(Vector3::Right(), deltaRad);
				}

				// Yaw
				if (Input::Pressed(Input::Key::KEY_D)) {
					rotation->Rotate(Vector3::Up(), -deltaRad);
				}
				if (Input::Pressed(Input::Key::KEY_A)) {
					rotation->Rotate(Vector3::Up(), deltaRad);
				}
			} else if (Input::Pressed(Input::Key::MOUSE_ONE)) {
				Quaternion* rotation = m_Transform->GetRotation();
				double mouseX = Input::GetAxis(Input::Axis::HORIZONTAL);
				double mouseY = Input::GetAxis(Input::Axis::VERTICAL);

				double gridX = mouseX - (m_WindowWidth / 2);
				double gridY = mouseY - (m_WindowHeight / 2);
				Vector3 target = Vector3(gridX, -gridY, 100.0f);

				*rotation = Quaternion::LookAt(
					*(m_GameObject->GetTransform()->GetPosition()),
					target
				);
			}
		};
};