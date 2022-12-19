#include "pch.h"
#include "Application.h"
#include "Window.h"

namespace Engine {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}
	Application::~Application()
	{
	}
	void Application::OnEvent(Event& e)
	{

	}

	void Application::Run()
	{
		std::cout << "in run" << std::endl;
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}

}