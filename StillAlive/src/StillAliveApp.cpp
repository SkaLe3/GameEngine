#include <Engine.h>
#include <iostream>


class Example : public Engine::Layer
{
	void OnUpdate() override
	{
		std::cout << "updating" << std::endl;
	}
	void OnEvent(Engine::Event& event) override
	{
		std::cout << typeid(event.GetEventType()).name() << std::endl;
	}
};
class StillAliveApp : public  Engine::Application
{
public:
	StillAliveApp() :  Engine::Application() 
	{
		PushLayer(new Example());
	}
	~StillAliveApp()
	{

	}


};

Engine::Application* Engine::CreateApplication()
{
	return new StillAliveApp();
}