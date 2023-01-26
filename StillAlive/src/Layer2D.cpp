#include "Layer2D.h"

#include "Libs/OpenGL/OpenGLShader.h"
#include <Engine.h>

Sandbox2D::Sandbox2D()
	: Layer(), m_CameraController(1920.0f / 1080.0f, true)
{

}

void Sandbox2D::OnAttach()
{


}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Engine::Timestep ts)
{
	m_CameraController.OnUpdate(ts);
	Engine::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1 });
	Engine::RenderCommand::Clear();



	Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, { 0.8f, 0.2f, 0.3f, 1.0f });

	Engine::Renderer2D::EndScene();

	//std::static_pointer_cast<Engine::OpenGLShader>(m_FlatColorShader)->Bind();
	//std::static_pointer_cast<Engine::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}
