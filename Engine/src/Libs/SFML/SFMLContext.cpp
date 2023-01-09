#include "pch.h"
#include "SFMLContext.h"

#include "SFML/Graphics.hpp"


namespace Engine {

	SFMLContext::SFMLContext(sf::RenderWindow* windowHandle)
		: m_WindowHandle(windowHandle) {}

	void SFMLContext::Init()
	{
	}

	void SFMLContext::SwapBuffers()
	{
		m_WindowHandle->display();
	}
}