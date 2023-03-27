#pragma once

#include "Core.h"
#include "Window.h"
#include "Engine/Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Timestep.h"

namespace Engine {

	class Application
	{
	public:
		Application(const std::string& name = "Engine App");
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();
		static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;
	};
	

	// Need to be defined in game	
	Application* CreateApplication();
}

