#pragma once

#include <iostream>

#include "component/Component.hpp"

class PlayerController : public Component
{
	public:
		void Start()
		{

		};

		void Update()
		{
			// The forward/backward delta
			double deltaVert = (Input())->GetAxis("Vertical");
		};
};