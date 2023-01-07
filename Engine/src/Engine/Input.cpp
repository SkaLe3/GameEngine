#include "pch.h"
#include "Input.h"
#include "Engine/Core/Application.h"


#include "SFML/Window.hpp"
namespace Engine
{
	bool Input::IsKeyPressed(KeyCode keycode)
	{
		return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(static_cast<int>(keycode)));
	}
}