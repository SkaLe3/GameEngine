#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Core/KeyCodes.h"
#include "Engine/Core/MouseCodes.h"


namespace Engine {

	class ENGINE_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode keycode);
		static bool IsMouseButtonPressed(MouseCode button);
		// Temporary type, need to be changed 
		static std::pair<int,int> GetMousePosition();
		static double GetMouseX();
		static double GetMouseY();

	};
}