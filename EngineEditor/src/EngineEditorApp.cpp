#include <Engine.h>
#include <Engine/Core/EntryPoint.h>
#include "EditorLayer.h"

namespace Engine {

	class EngineEditor : public Application
	{
	public:
		EngineEditor() : Application("Editor")
		{
			PushLayer(new EditorLayer());
		}
		~EngineEditor()
		{
	
		}
	
	private:
		
	
	
	};
	}

Engine::Application* Engine::CreateApplication()
{
	return new EngineEditor();
}