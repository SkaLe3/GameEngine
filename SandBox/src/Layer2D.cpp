#include "Layer2D.h"

#include "Libs/OpenGL/OpenGLShader.h"
#include <glm/gtc/matrix_transform.hpp>
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

	m_ActiveScene = Engine::CreateRef<Engine::Scene>();

	auto square = m_ActiveScene->CreateEntity("Square");
	square.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{0.0f, 1.0f, 0.0f, 1.0f});

	m_CameraEntity = m_ActiveScene->CreateEntity("Camera");
	m_CameraEntity.AddComponent<Engine::CameraComponent>();


	class CameraController : public Engine::ScriptableEntity
	{
	public:
		void OnCreate()
		{
			//GetComponent<Engine::TransformComponent>();
			std::cout << "OnCreate!" << std::endl;
		}

		void OnDestroy()
		{

		}

		void OnUpdate(Engine::Timestep ts)
		{
			auto& translation = GetComponent<Engine::TransformComponent>().Translation;
			float speed = 5.0f;
			if (Engine::Input::IsKeyPressed(Engine::Key::A))
				translation.x -= speed * ts;
			if (Engine::Input::IsKeyPressed(Engine::Key::D))
				translation.x += speed * ts;
			if (Engine::Input::IsKeyPressed(Engine::Key::W))
				translation.y += speed * ts;
			if (Engine::Input::IsKeyPressed(Engine::Key::S))
				translation.y -= speed * ts;

		}
	};

	m_CameraEntity.AddComponent<Engine::NativeScriptComponent>().Bind<CameraController>();

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
	rotation += ts * 1.0f;


	//Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	m_ActiveScene->OnUpdate(ts);
	//Engine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawRotatedQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, 60, { 0.8f, 0.5f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, { 0.8f, 0.5f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	//Engine::Renderer2D::DrawQuad({  0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerBoard, 10);
	//Engine::Renderer2D::DrawRotatedQuad({ -0.5f, -0.5f, 0.0f }, { 1.0f, 1.0f },rotation, m_CheckerBoard, 20);

	//Engine::Renderer2D::EndScene();

	//Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());
	//Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, m_Stairs);
	//Engine::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.0f }, { 1.0f, 2.0f }, m_TextureTree);
	//Engine::Renderer2D::EndScene();

}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}
