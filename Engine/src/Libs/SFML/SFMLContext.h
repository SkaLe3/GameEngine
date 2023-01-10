#pragma once


#include "Engine/Renderer/GraphicsContext.h"
namespace sf {
class RenderWindow;
}

namespace Engine {

	class SFMLContext : public GraphicsContext
	{
	public:
		SFMLContext(sf::RenderWindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		sf::RenderWindow* m_WindowHandle;
	};
}