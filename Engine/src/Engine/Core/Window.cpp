#include "pch.h"
#include "Window.h"
#include "WindowsWindow.h"


namespace Engine {

	std::unique_ptr<Window> Window::Create(const WindowProperties& props)
	{
		return std::make_unique<WindowsWindow>(props);
	}
}