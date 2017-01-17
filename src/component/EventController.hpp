#pragma once

#include "component/Component.hpp"

class EventController : public Component
{
	public:
		void Start()
		{

		};

		void Update(double deltaTime)
		{
			// Upon releasing the escape button, stop the game.
			if (Input::Released(Input::Key::KEY_ESCAPE)) {
				m_GameObject->GetLevel()->GetGame()->Stop();
			}
		};
};