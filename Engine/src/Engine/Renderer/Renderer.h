#pragma once

#include "RenderCommand.h"
namespace Engine {


	class Renderer
	{
	public:
		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}