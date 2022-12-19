#include "pch.h"
#include "Application.h"
#include "Window.h"

namespace Engine {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		std::cout << "in constructor" << std::endl;
	}
	Application::~Application()
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