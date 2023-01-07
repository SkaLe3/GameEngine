#include "pch.h"
#include "WindowsWindow.h"
#include "SFML/Window.hpp"
#include "Engine/Events/Event.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"
#include "Engine/Events/ApplicationEvent.h"

#include <iostream>

namespace Engine {

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}
	
	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		sf::Event ev;
		while (m_Window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
			{
				WindowCloseEvent event;
				m_Data.EventCallback(event);
				break;
			}
			case sf::Event::Resized:
			{
				m_Data.Width = ev.size.width;
				m_Data.Height = ev.size.height;
				WindowResizeEvent event(ev.size.width, ev.size.height);
				break;
			}
			case sf::Event::KeyPressed:
			{
				KeyPressedEvent event(ev.key.code);
				m_Data.EventCallback(event);
				break;
			}
			case sf::Event::KeyReleased:
			{
				KeyReleasedEvent event(ev.key.code);
				m_Data.EventCallback(event);
				break;
			}
			case sf::Event::TextEntered:
			{
				KeyEnteredEvent event(ev.TextEntered);
				m_Data.EventCallback(event);
				
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				MouseButtonPressedEvent event(ev.mouseButton.button); // add mouse coords
				m_Data.EventCallback(event);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				MouseButtonReleasedEvent event(ev.mouseButton.button);
				m_Data.EventCallback(event);
				break;
			}
			case sf::Event::MouseWheelScrolled:
			{
				MouseScrolledEvent event(ev.mouseWheelScroll.delta);
				m_Data.EventCallback(event);
				break;
			}
			case sf::Event::MouseMoved:
			{
				MouseMovedEvent event(ev.mouseMove.x, ev.mouseMove.y);
				m_Data.EventCallback(event);
				break;
			}
			}
			
		}

	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Window.create(sf::VideoMode(sf::Vector2u(m_Data.Width, m_Data.Height)), m_Data.Title);


	}

	void WindowsWindow::Shutdown()
	{
		m_Window.close();
	}


}
