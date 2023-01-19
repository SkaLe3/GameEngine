#include "pch.h"
#include "GraphicsContext.h"

#include "Libs/OpenGL/OpenGLContext.h"


#include "Renderer.h"

namespace Engine {

	std::unique_ptr<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ERROR("RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return std::make_unique<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}
		return nullptr;
	}
}