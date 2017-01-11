#pragma once

#include "component/Component.hpp"
#include "core/Logger.hpp"

class LineDrawController : public Component
{
	bool m_TrackMovement;

	public:
		void Start()
		{
			m_TrackMovement = false;
		};

		void Update()
		{
			// If Mouse 1 was pressed since the last update
			if (Input::Pressed(Input::Key::KEY_LALT)) {
				Logger() << "Start tracking objects" << "\n";
				m_TrackMovement = true;
			}

			// If we're tracking the mouse movement
			if (m_TrackMovement) {
				double deltaVert = Input::GetAxis(Input::Axis::VERTICAL);
				double deltaHoriz = Input::GetAxis(Input::Axis::HORIZONTAL);
			}

			// If Mouse 1 was released since the last update
			if (Input::Released(Input::Key::KEY_LALT)) {
				Logger() << "Stop tracking objects" << "\n";
				m_TrackMovement = false;
			}
		};
};