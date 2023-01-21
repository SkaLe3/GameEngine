#include <Engine.h>
#include <iostream>

#include "glm/glm/glm.hpp"

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