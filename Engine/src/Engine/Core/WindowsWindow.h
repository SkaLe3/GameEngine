#pragma once
#include "Window.h"
#include "SFML/Graphics.hpp"
#include "Engine/Events/Event.h"

namespace Engine {


	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }


	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		sf::RenderWindow m_Window;
		struct WindowData
		{
			std::string Title= "";
			unsigned int Width = 0, Height = 0;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}

