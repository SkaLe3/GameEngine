#pragma once
#include "Engine.h"
#include "Engine/Renderer/EditorCamera.h"

class Sandbox2D : public Engine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Engine::Timestep ts) override;
	void OnEvent(Engine::Event& e) override;

	bool OnKeyPressed(Engine::KeyPressedEvent& e); // Example of realizations

	// void New();
	// void SaveAs();           Example of realizations
private:
	Engine::OrthographicCameraController m_CameraController;
	Engine::Entity m_CameraEntity;

	Engine::Ref<Engine::VertexArray> m_SquareVA;
	Engine::Ref<Engine::Shader> m_FlatColorShader;

	Engine::Ref<Engine::Framebuffer> m_Framebuffer;

	Engine::Ref<Engine::Texture2D> m_CheckerBoard;
	Engine::Ref<Engine::Texture2D> m_SpriteSheet;
	Engine::Ref<Engine::SubTexture2D> m_Stairs, m_TextureTree;

	Engine::Ref<Engine::Scene> m_ActiveScene;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f }; 

	Engine::EditorCamera m_EditorCamera;

};