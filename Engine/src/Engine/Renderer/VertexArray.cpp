#include "pch.h"
#include "VertexArray.h"

#include "RendererAPI.h"
#include "Renderer.h"

#include "Libs/OpenGL/OpenGLVertexArray.h"

namespace Engine {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexArray>();
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}
}