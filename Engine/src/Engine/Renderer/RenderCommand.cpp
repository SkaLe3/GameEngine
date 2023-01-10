#include "pch.h"
#include "RenderCommand.h"
#include "Libs/SFML/SFMLRendererAPI.h"

namespace Engine {

	RendererAPI* RenderCommand::s_RendererAPI = new SFMLRendererAPI;
}