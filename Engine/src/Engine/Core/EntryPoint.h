#pragma once

#include "Application.h"

extern Engine::Application* Engine::CreateApplication();

int main()
{

	auto app = Engine::CreateApplication();

	app->Run();
	delete app;
	return 0;
}