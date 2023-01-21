#include "pch.h"
#include "RenderCommand.h"
#include "Libs/OpenGL/OpenGLRendererAPI.h"

namespace Engine {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}