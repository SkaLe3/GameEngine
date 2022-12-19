#include <Engine.h>


class StillAliveApp : public  Engine::Application
{
public:
	StillAliveApp() :  Engine::Application() {}
	~StillAliveApp()
	{

	}


};

Engine::Application* Engine::CreateApplication()
{
	return new StillAliveApp();
}