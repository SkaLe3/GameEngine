#include "Layer2D.h"

#include "Libs/OpenGL/OpenGLShader.h"
#include <Engine.h>

Sandbox2D::Sandbox2D()
	: Layer(), m_CameraController(1920.0f / 1080.0f, true)
{

}

void Sandbox2D::OnAttach()
{
	m_CheckerBoard = Engine::Texture2D::Create("assets/textures/CheckerBoard.png");

}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Engine::Timestep ts)
{
	EG_PROFILE_FUNCTION();

	m_CameraController.OnUpdate(ts);
	Engine::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1 });
	Engine::RenderCommand::Clear();

	static float rotation = 0.0f;
	rotation += ts * 50.0f;


	Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Engine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawRotatedQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, 60, { 0.8f, 0.5f, 0.3f, 1.0f });
	Engine::Renderer2D::DrawQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, { 0.8f, 0.5f, 0.3f, 1.0f });
	Engine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Engine::Renderer2D::DrawQuad({  0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerBoard, 10);
	Engine::Renderer2D::DrawRotatedQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f },rotation, m_CheckerBoard, 20);

	Engine::Renderer2D::EndScene();

}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}
