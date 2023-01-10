#pragma once

#include "Engine/Renderer/RendererAPI.h"

namespace Engine {

	class SFMLRendererAPI : public RendererAPI
	{
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;
		virtual void Draw(sf::Shape* shape) override;
	};
}