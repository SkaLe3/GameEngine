#pragma once
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Engine/Renderer/GraphicsContext.h"

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

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		virtual void* GetNativeWindow() const{ return m_Window; }

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		std::unique_ptr<GraphicsContext> m_Context;
		struct WindowData
		{
			std::string Title= "";
			unsigned int Width = 0, Height = 0;

			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}

