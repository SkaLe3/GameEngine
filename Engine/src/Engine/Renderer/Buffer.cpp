#include "pch.h"
#include "Buffer.h"
#include "Engine/Renderer/Renderer.h"
#include "Libs/OpenGL/OpenGLBuffer.h"
namespace Engine {


	Engine::VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ERROR("RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}
		EG_ERROR("Unknown Renderer API");
		return nullptr;
	}

	Engine::IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ERROR("RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, count);
		}
		EG_ERROR("Unknown Renderer API");
		return nullptr;
	}

}