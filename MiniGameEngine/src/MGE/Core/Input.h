#pragma once

#include "MGE/Core/Base.h"
#include "MGE/Core/KeyCodes.h"

namespace MGE {

	class MGE_API Input
	{
	public:
		public:
		static bool IsKeyPressed(int keycode);

		static bool IsMouseButtonPressed(int button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}