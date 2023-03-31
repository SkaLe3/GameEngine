#include "Layer2D.h"

#include "Libs/OpenGL/OpenGLShader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <Engine.h>
#include <Engine/Scene/SceneSerializer.h>

Sandbox2D::Sandbox2D()
	: Layer(), m_CameraController(1920.0f / 1080.0f, true)
{

}

void Sandbox2D::OnAttach()
{
	Engine::FramebufferSpecification fbSpec;
	fbSpec.Width = 1920;
	fbSpec.Height = 1080;
	m_Framebuffer = Engine::Framebuffer::Create(fbSpec);

	//m_EditorCamera = Engine::EditorCamera(30.0f, 1.778f, 0.1f, 1000.0f);
	//m_EditorCamera.SetViewportSize(1920, 1080);
	//m_CheckerBoard = Engine::Texture2D::Create("assets/textures/CheckerBoard.png");
	//m_SpriteSheet = Engine::Texture2D::Create("assets/textures/RPGpack_sheet_2X.png");

	//m_Stairs = Engine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 7, 6 }, { 128, 128 });
	//m_TextureTree = Engine::SubTexture2D::CreateFromCoords(m_SpriteSheet, { 2, 1 }, { 128, 128 }, {1, 2});

	m_ActiveScene = Engine::CreateRef<Engine::Scene>();
	m_ActiveScene->OnViewportResize(1920, 1080);

	auto square = m_ActiveScene->CreateEntity("Square");
	square.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{0.2f, 0.8f, 0.2f, 1.0f});
#if 1
	// right wall
	auto square2 = m_ActiveScene->CreateEntity("square2");
	square2.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.8f, 0.2f, 0.2f, 1.0f });
	auto& tc2 = square2.GetComponent<Engine::TransformComponent>();
	tc2.Translation = { 0.5f, 0.0f, -0.5f };
	tc2.Rotation = { 0.0f, glm::radians(90.0f), 0.0f };
	// left wall
	auto square3 = m_ActiveScene->CreateEntity("square3");
	square3.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.2f, 0.2f, 0.8f, 1.0f });
	auto& tc3 = square3.GetComponent<Engine::TransformComponent>();
	tc3.Translation = { -0.5f, 0.0f, -0.5f };
	tc3.Rotation = { 0.0f, glm::radians(90.0f), 0.0f };
	// top
	auto square4 = m_ActiveScene->CreateEntity("square4");
	square4.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.2f, 0.8f, 0.8f, 1.0f });
	auto& tc4 = square4.GetComponent<Engine::TransformComponent>();
	tc4.Translation = { 0.0f, 0.5f, -0.5f };
	tc4.Rotation = { glm::radians(90.0f), 0.0f, 0.0f };
	// bottom
	auto square5 = m_ActiveScene->CreateEntity("square5");
	square5.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.8f, 0.8f, 0.2f, 1.0f });
	auto& tc5 = square5.GetComponent<Engine::TransformComponent>();
	tc5.Translation = { 0.0f, -0.5f, -0.5f };
	tc5.Rotation = { glm::radians(90.0f), 0.0f, 0.0f };


	auto top = m_ActiveScene->CreateEntity("top");
	top.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.2f, 0.2f, 0.8f, 1.0f });
	auto& transformComponentTop = top.GetComponent<Engine::TransformComponent>();
	transformComponentTop.Translation = { 3.0f, 1.0f, 0.0f };
	transformComponentTop.Scale.x = 3.0f;

	auto bottom = m_ActiveScene->CreateEntity("bottom");
	bottom.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.8f, 0.8f, 0.0f, 1.0f });
	auto& transformComponentBottom = bottom.GetComponent<Engine::TransformComponent>();
	transformComponentBottom.Translation = { 3.0f, 0.0f, 0.0f };
	transformComponentBottom.Scale.x = 3.0f;

	auto ss = m_ActiveScene->CreateEntity("ss");
	ss.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.3f, 0.2f, 0.2f, 1.0f });
	auto& transformComponentSs = ss.GetComponent<Engine::TransformComponent>();
	transformComponentSs.Translation = { 1.5f, -1.0f, 0.0f };
	transformComponentSs.Scale.x = 0.2f;
	transformComponentSs.Scale.y = 5.0f;
#endif



	m_CameraEntity = m_ActiveScene->CreateEntity("Camera");
	Engine::CameraComponent& cc = m_CameraEntity.AddComponent<Engine::CameraComponent>();
	cc.Camera.SetPerspective(45.0f, 0.01f, 1000.0f); //comment this
	//cc.Camera.SetOrthographic(10.0f, -5.0f, 5.0f);   //comment this
	auto& tcc = m_CameraEntity.GetComponent<Engine::TransformComponent>();
	tcc.Translation = { tcc.Translation.x, tcc.Translation.y, 3.0f }; //comment this
	m_CameraEntity.AddComponent<Engine::SpriteRendererComponent>(glm::vec4{ 0.9f, 0.75f, 0.8f, 1.0f });


#if 0
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
			static bool pause = false;
			auto& translation = GetComponent<Engine::TransformComponent>().Translation;
			auto& rotation = GetComponent<Engine::TransformComponent>().Rotation;
			float speed = 5.0f;
			static bool first = true;
			static int32_t x, y;
			if (first)
			{
				x = Engine::Input::GetMouseX();
				y = Engine::Input::GetMouseY();
				first = false;
			}
			int32_t newx = Engine::Input::GetMouseX();
			int32_t newy = Engine::Input::GetMouseY();
			float offsetx = x - newx;
			float offsety = y - newy;
			x = newx;
			y = newy;

			if (!pause) {
				if (Engine::Input::IsKeyPressed(Engine::Key::A)) {
					translation.x -= glm::cos(rotation.y) * speed * ts;
					translation.z += glm::sin(rotation.y) * speed * ts;
				}
				if (Engine::Input::IsKeyPressed(Engine::Key::D)) {
					translation.x += glm::cos(rotation.y) * speed * ts;
					translation.z -= glm::sin(rotation.y) * speed * ts;
				}

				if (Engine::Input::IsKeyPressed(Engine::Key::Space))
					translation.y += speed * ts;
				if (Engine::Input::IsKeyPressed(Engine::Key::LeftShift))
					translation.y -= speed * ts;
				if (Engine::Input::IsKeyPressed(Engine::Key::S)) {
					glm::vec4 dir = glm::vec4(0.0f, 0.0f, -speed * ts, 0.0f) * glm::rotate(glm::mat4(1.0f), rotation.y, { 0, -1, 0 });
					translation -= glm::vec3(dir.x, dir.y, dir.z);
				}
				if (Engine::Input::IsKeyPressed(Engine::Key::W)) {
					glm::vec4 dir = glm::vec4(0.0f, 0.0f, -speed * ts, 0.0f) * glm::rotate(glm::mat4(1.0f), rotation.y, { 0, -1, 0 });
					translation += glm::vec3(dir.x, dir.y, dir.z);
				}
				rotation.y += glm::radians(offsetx) * ts;
				rotation.y += glm::radians(offsetx) * ts;
				rotation.x += glm::radians(offsety) * ts;
				rotation.x += glm::radians(offsety) * ts;
			}
			if (Engine::Input::IsKeyPressed(Engine::Key::Escape)) {
				pause = !pause;
				if (pause)
					Engine::Input::EnableCursor();
				else Engine::Input::DisableCursor();
			}

		}
	};

	m_CameraEntity.AddComponent<Engine::NativeScriptComponent>().Bind<CameraController>();

#endif
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Engine::Timestep ts)
{
	//m_CameraController.OnUpdate(ts);
	m_Framebuffer->Bind();


	//m_EditorCamera.OnUpdate(ts);


	Engine::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1 });
	Engine::RenderCommand::Clear();
	//m_ActiveScene->OnUpdateEditor(ts, m_EditorCamera);

	static float rotation = 0.0f;
	rotation += ts * 1.0f;


	//Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	m_ActiveScene->OnUpdate(ts);
	//Engine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawRotatedQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, 60, { 0.8f, 0.5f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawQuad({ -0.6f, 0.8f }, { 0.7f, 0.7f }, { 0.8f, 0.5f, 0.3f, 1.0f });
	//Engine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	//Engine::Renderer2D::DrawQuad({  0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerBoard, 10);
	//Engine::Renderer2D::DrawRotatedQuad({ -0.5f, -0.5f, -0.1f }, { 1.0f, 1.0f },rotation, m_CheckerBoard, 20);

	//Engine::Renderer2D::EndScene();
	
	//Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());
	//Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, m_Stairs);
	//Engine::Renderer2D::DrawQuad({ 1.0f, 0.0f, 0.0f }, { 1.0f, 2.0f }, m_TextureTree);
	//Engine::Renderer2D::EndScene();

	m_Framebuffer->Unbind();

}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
	//m_EditorCamera.OnEvent(e);

	Engine::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Engine::KeyPressedEvent>(BIND_EVENT_FN(Sandbox2D::OnKeyPressed));
}

bool Sandbox2D::OnKeyPressed(Engine::KeyPressedEvent& e)
{

	//Shortcut example
	bool controlPressed = Engine:: Input::IsKeyPressed(Engine::Key::LeftControl) || Engine::Input::IsKeyPressed(Engine::Key::RightControl);
	switch (e.GetKeyCode())
	{
	case Engine::Key::S:
	{
		if (controlPressed)
			int pass = 2; // SaveAs()
			break;
	}
	case Engine::Key::N:
	{
		if (controlPressed)
			int pass = 3; // New()
		break;
	}
	}
	return true;
}
