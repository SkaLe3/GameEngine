#include "pch.h"
#include "Application.h"
#include "Window.h"

#include "SFML/Graphics.hpp"



#include "Engine/Renderer/Renderer.h"


namespace Engine {

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
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
			if (e.m_Handled)
				break;
			(*--it)->OnEvent(e);
		}

	}

	void Application::Run()
	{
		
		sf::ConvexShape convex(5);
		convex.setPoint(0, sf::Vector2f(0, 0));
		convex.setPoint(1, sf::Vector2f(150, 10));
		convex.setPoint(2, sf::Vector2f(120, 90));
		convex.setPoint(3, sf::Vector2f(30, 100));
		convex.setPoint(4, sf::Vector2f(0, 50));
		convex.setFillColor(sf::Color::Green);
		while (m_Running) {
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			m_Window->OnUpdate();
			RenderCommand::SetClearColor(glm::vec4(0.2, 0.8, 0.8, 1));
			RenderCommand::Clear();
			RenderCommand::Draw(&convex);
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