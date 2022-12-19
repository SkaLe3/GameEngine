#pragma once

#include "Application.h"
#include <iostream>

extern Engine::Application* Engine::CreateApplication();

int main()
{
	auto app = Engine::CreateApplication();

	app->Run();
	delete app;
	return 0;
}