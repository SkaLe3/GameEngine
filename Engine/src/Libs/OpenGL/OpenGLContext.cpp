#include "pch.h"
#include "OpenGLContext.h"

#include <Glad/glad.h>
#include "GLFW/glfw3.h"
namespace Engine {


	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle)
	{

	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	void OpenGLContext::SwapBuffers()
	{

	}
}