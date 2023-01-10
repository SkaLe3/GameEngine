#pragma once

#include "glm/glm.hpp"
namespace sf
{
	class CircleShape;
}
namespace Engine {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, SFML = 1, OpenGL = 2
		};
	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void Draw(sf::CircleShape*) = 0;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};
}
