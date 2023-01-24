#include "pch.h"
#include "Engine/Renderer/Shader.h"
	
#include "Engine/Renderer/Renderer.h"

#include "Libs/OpenGL/OpenGLShader.h"


namespace Engine {
		
	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return new OpenGLShader(vertexSrc, fragmentSrc);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}
}