#include "pch.h"
#include "Application.h"
#include "Window.h"

#include "Engine/Renderer/Renderer.h"
#include "Engine/Renderer/Renderer2D.h"
#include "Engine/Core/Input.h"

#include "Engine/Renderer/Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Engine/Events/KeyEvent.h"
#include "Engine/Renderer/Renderer.h"

namespace Engine {

	Application* Application::s_Instance = nullptr;

	
	Application::Application(const std::string& name)
	{

		Log::GetLogger()->Init();
		s_Instance = this;
		m_Window = Window::Create(WindowProperties(name));
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		
		Renderer::Init();


		
	}


	Application::~Application() 
	{
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResized));

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
			
			if (!m_Minimized)
			{

				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);
				m_Window->OnUpdate();
			}
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
	}

	void Application::Close()
	{
		m_Running = false;
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResized(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}
		m_Minimized = false;

		Renderer::OnWindowResized(e.GetWidth(), e.GetHeight());
		return false;
	}

}