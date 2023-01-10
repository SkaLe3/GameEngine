#pragma once

#include "RendererAPI.h"
namespace Engine {

	class RenderCommand
	{
	public:
		static void Draw(sf::CircleShape* shape)
		{
			s_RendererAPI->Draw(shape);
		}
	private:
		static RendererAPI* s_RendererAPI;
	};
}