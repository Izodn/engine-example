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
			if (Input()->Pressed(Input()->GetKeyCode("Mouse 1"))) {
				m_TrackMovement = true;
			}

			// If we're tracking the mouse movement
			if (m_TrackMovement) {
				double deltaVert = Input()->GetAxis("Vertical");
				double deltaHoriz = Input()->GetAxis("Horizontal");
			}

			// If Mouse 1 was released since the last update
			if (Input()->Released(Input()->GetKeyCode("Mouse 1"))) {
				m_TrackMovement = false;
			}
		};
};