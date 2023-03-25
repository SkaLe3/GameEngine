#include "pch.h"
#include "Buffer.h"
#include "Engine/Renderer/Renderer.h"
#include "Libs/OpenGL/OpenGLBuffer.h"
namespace Engine {
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(size);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}


	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices, count);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

}