#pragma once

#include "RendererAPI.h"

namespace Engine {

	class RenderCommand
	{
	public:

		static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}
		static void Clear()
		{
			s_RendererAPI->Clear();
		}

		static void Draw()
		{
			s_RendererAPI->Draw();
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}