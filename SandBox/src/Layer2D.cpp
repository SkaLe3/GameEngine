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
	m_SpriteSheet = Engine::Texture2D::Create("assets/textures/RPGpack_sheet_2X.png");

	m_Stairs = Engine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128, 128 });
	m_TextureTree = Engine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, {1, 2});
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

#if 0
	static float rotation = 0.0f;
	rotation += ts * 1.0f;


	Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Engine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Engine::Renderer2D::DrawRotatedQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, 60, { 0.8f, 0.5f, 0.3f, 1.0f });
	Engine::Renderer2D::DrawQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, { 0.8f, 0.5f, 0.3f, 1.0f });
	Engine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Engine::Renderer2D::DrawQuad({  0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerBoard, 10);
	Engine::Renderer2D::DrawRotatedQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f },rotation, m_CheckerBoard, 20);

	Engine::Renderer2D::EndScene();

#endif
	Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, m_Stairs);
	Engine::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.0f }, { 1.0f, 2.0f }, m_TextureTree);
	Engine::Renderer2D::EndScene();

}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}
