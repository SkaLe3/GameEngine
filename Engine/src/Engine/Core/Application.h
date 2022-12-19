#pragma once

#include "Core.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	

	// Need to be defined in game	
	Application* CreateApplication();
}

