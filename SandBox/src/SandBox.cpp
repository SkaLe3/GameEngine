#include <Engine.h>
#include <Engine/Core/EntryPoint.h>
#include <iostream>

#include "glm/glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include "Libs/OpenGL/OpenGLShader.h"
#include "Engine/Renderer/Shader.h"
#include "Layer2D.h"




class SandBoxApp : public  Engine::Application
{
public:
	SandBoxApp() : Application("SandBox2D")
	{
		PushLayer(new Sandbox2D);
	}
	~SandBoxApp()
	{

	}

private:
	


};

Engine::Application* Engine::CreateApplication()
{
	return new SandBoxApp();
}