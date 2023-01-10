#pragma once

namespace Engine {

	enum class RendererAPI
	{
		None = 0, SFML = 1, OpenGL = 2
	};


	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};
}