#include "pch.h"
#include "SFMLRendererAPI.h"
#include <SFML/OpenGL.hpp>
#include "SFML/Graphics.hpp"

#include "Engine/Core/Application.h"

namespace Engine {

	void SFMLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void SFMLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void SFMLRendererAPI::Draw(sf::Shape* shape)
	{
		static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow())->draw(*static_cast<sf::Shape*>(shape));
	}
}