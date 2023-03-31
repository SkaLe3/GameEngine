#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Core/KeyCodes.h"
#include "Engine/Core/MouseCodes.h"

#include "glm/glm.hpp"

namespace Engine {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static double GetMouseX();
		static double GetMouseY();

		static void DisableCursor();
		static void EnableCursor();
		static void HideCursor();

	};
}