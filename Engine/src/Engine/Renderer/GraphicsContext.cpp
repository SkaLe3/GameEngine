#include "pch.h"
#include "GraphicsContext.h"

#include "Libs/SFML/SFMLContext.h"
#include "SFML/Graphics.hpp"

namespace Engine {

	std::unique_ptr<GraphicsContext> GraphicsContext::Create(void* window)
	{
		return std::make_unique<SFMLContext>(static_cast<sf::RenderWindow*>(window));
	}
}