#include <Engine.h>


class StillAliveApp : public Engine::Application
{
public:
	StillAliveApp()
	{
	}
	~StillAliveApp()
	{

	}


};

Engine::Application* Engine::CreateApplication()
{
	return new StillAliveApp();
}