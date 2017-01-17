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
			if (Input::Pressed(Input::Key::KEY_W)) {
				// Run forward
				Transform* transform = m_GameObject->GetTransform();
				Vector3* position = transform->GetPosition();
				Logger() << "Position: " << (std::string)*position << "\n";
				*position += Vector3(
					5.0f * deltaTime,
					0.0f,
					0.0f
				);
			}
			if (Input::Released(Input::Key::KEY_W)) {
				// Echo current position
				Transform* transform = m_GameObject->GetTransform();
				Vector3* position = transform->GetPosition();
				Logger() << "Ending: " << (std::string)*position << "\n";
			}
		};
};