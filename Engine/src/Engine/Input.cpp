#include "pch.h"
#include "Input.h"
#include "Engine/Core/Application.h"


#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
namespace Engine {

	bool Input::IsKeyPressed(KeyCode keycode)
	{
		return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(static_cast<int>(keycode)));
	}
	bool Input::IsMouseButtonPressed(MouseCode keycode)
	{
		return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(static_cast<int>(keycode)));
	}
	std::pair<int,int> Input::GetMousePosition()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());

		auto[x,y] = sf::Mouse::getPosition(*window);
		std::pair<int, int> p;
		p.first = x;
		p.second = y;

		return p;
	}
	double Input::GetMouseX()
	{
		auto[x, y] = GetMousePosition();
		return x;
	}
	double Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
}