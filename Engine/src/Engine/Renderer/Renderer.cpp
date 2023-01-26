#include "pch.h"
#include "Renderer.h"
#include "Renderer2D.h"
#include "Libs/OpenGL/OpenGLShader.h"

namespace Engine {

	Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

	void Renderer::Init()
	{
		RenderCommand::Init();
		Renderer2D::Init();
	}

	void Renderer::OnWindowResized(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transfrom)
	{
		shader->Bind();
		//OpenGL is only supported API -> type check is unnecessary 
		std::static_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
		std::static_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transfrom);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}