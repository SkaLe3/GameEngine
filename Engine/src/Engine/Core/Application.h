#pragma once

#include "Core.h"
#include "Window.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	

	// Need to be defined in game	
	Application* CreateApplication();
}

