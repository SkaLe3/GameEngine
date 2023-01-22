#include "pch.h"
#include "Application.h"
#include "Window.h"

#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/Input.h"

#include "Engine/Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Events/KeyEvent.h"

namespace Engine {

	Application* Application::s_Instance = nullptr;

	
	Application::Application()
	{
		Log::GetLogger()->Init();
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		
	}


	Application::~Application() 
	{
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
			
		}

	}

	void Application::Run()
	{
		while (m_Running) 
		{
			float time = (float)glfwGetTime(); 
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;
			
			
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timestep);
			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();

	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
		layer->OnDetach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}