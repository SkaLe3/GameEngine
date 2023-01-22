#pragma once

#include "Core.h"
#include "Engine/Events/Event.h"
#include <memory>
#include <string>
#include <functional>


namespace Engine {

	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties(const std::string& title = "Engine",
			unsigned int width = 1920,
			unsigned int height = 1080)
			: Title(title), Width(width), Height(height) {}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties());
	};
}
