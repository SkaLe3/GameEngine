#include "pch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Libs/OpenGL/OpenGLTexture.h"

namespace Engine {

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLTexture2D>(path);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}
}