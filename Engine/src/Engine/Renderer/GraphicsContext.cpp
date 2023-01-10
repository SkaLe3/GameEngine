#include "pch.h"
#include "GraphicsContext.h"

#include "Libs/SFML/SFMLContext.h"
#include "SFML/Graphics.hpp"

#include "Renderer.h"

namespace Engine {

	std::unique_ptr<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: std::cout << "RendererAPI::None" << std::endl; return nullptr;
			// OpenGL currently isn't supported. It will be implemented later whily learning it
		case RendererAPI::API::OpenGL: std::cout << "RendererAPI::OpenGL not supported" << std::endl; return nullptr;

		case RendererAPI::API::SFML: return std::make_unique<SFMLContext>(static_cast<sf::RenderWindow*>(window));
		}
		return nullptr;
	}
}