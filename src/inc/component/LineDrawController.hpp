#pragma once

#include <iostream>

#include "component/Component.hpp"

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
				std::cout << "Start tracking objects" << std::endl;
				m_TrackMovement = true;
			}

			// If we're tracking the mouse movement
			if (m_TrackMovement) {
				double deltaVert = Input::GetAxis(Input::Axis::VERTICAL);
				double deltaHoriz = Input::GetAxis(Input::Axis::HORIZONTAL);
			}

			// If Mouse 1 was released since the last update
			if (Input::Released(Input::Key::KEY_LALT)) {
				std::cout << "Stop tracking objects" << std::endl;
				m_TrackMovement = false;
			}
		};
};