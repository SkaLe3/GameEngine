#include "pch.h"
#include "OpenGLContext.h"

#include <Glad/glad.h>
#include "GLFW/glfw3.h"
namespace Engine {


	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{
		EG_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		EG_ASSERT(status, "Failed to initialize Glad!");
		EG_INFO("OpenGL Info:");
		EG_INFO("\tVendor: ", glGetString(GL_VENDOR));
		EG_INFO("\tRenderer: ", glGetString(GL_RENDERER));
		EG_INFO("\tVersion: ", glGetString(GL_VERSION));

		EG_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "StillAlive requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{


		glfwSwapBuffers(m_WindowHandle);
	}
}