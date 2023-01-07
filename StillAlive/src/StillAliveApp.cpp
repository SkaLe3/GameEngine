#include <Engine.h>
#include <iostream>

#include "glm/glm.hpp"

class Example : public Engine::Layer
{
	void OnUpdate() override
	{

	}
	void OnEvent(Engine::Event& event) override
	{

	}
};

class Example1 : public Engine::Layer
{
	void OnUpdate() override
	{
		//std::cout << Engine::Input::GetMousePosition().first << "\t" << Engine::Input::GetMousePosition().second<< std::endl;
	}
	void OnEvent(Engine::Event& event) override
	{

	}
};
class StillAliveApp : public  Engine::Application
{
public:
	StillAliveApp() :  Engine::Application() 
	{
		PushLayer(new Example());
		PushLayer(new Example1());
	}
	~StillAliveApp()
	{

	}


};

Engine::Application* Engine::CreateApplication()
{
	return new StillAliveApp();
}