#pragma once

#include "Core.h"
#include "Window.h"
#include "Engine/Events/ApplicationEvent.h"
#include "LayerStack.h"


#include "Engine/Renderer/Shader.h"
namespace Engine {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClosed(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		std::unique_ptr<Shader> m_Shader;
		static Application* s_Instance;
	};
	

	// Need to be defined in game	
	Application* CreateApplication();
}

