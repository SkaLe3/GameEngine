#include "pch.h"
#include "Framebuffer.h"
#include "Engine/Renderer/Renderer.h"
#include "Libs/OpenGL/OpenGLFramebuffer.h"

namespace Engine {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpengGLFramebuffer>(spec);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

}