#pragma once

#include "Core.h"
#include "Engine/Events/Event.h"
#include "pch.h"

namespace Engine {

	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class ENGINE_API Window
	{
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() = 0;
		virtual unsigned int GetHeight() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};
}
