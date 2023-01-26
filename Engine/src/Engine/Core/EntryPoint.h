#pragma once

#include "Application.h"

extern Engine::Application* Engine::CreateApplication();

int main()
{

	EG_PROFILE_BEGIN_SESSION("Startup", "EngineProfile-Runtime.jason");
	auto app = Engine::CreateApplication();

	app->Run();
	EG_PROFILE_END_SESSION();
	delete app;
	return 0;
}