#include "pch.h"
#include "Renderer2D.h"

#include "VertexArray.h"
#include "Shader.h"
#include "RenderCommand.h"
#include "Libs/OpenGL/OpenGLShader.h"
namespace Engine {

	struct Renderer2DStorage 
	{
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader> FlatColorShader;

	};
	static Renderer2DStorage* s_Data;

	void Renderer2D::Init()
	{
		s_Data = new Renderer2DStorage();
		s_Data->QuadVertexArray = VertexArray::Create();
		float squarevertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f

		};

		Ref<VertexBuffer> squareVB;
		squareVB = Engine::VertexBuffer::Create(squarevertices, sizeof(squarevertices));


		BufferLayout squarelayout = {
			{ShaderDataType::Float3, "a_Position"}
		};
		squareVB->SetLayout(squarelayout);
		s_Data->QuadVertexArray->AddVertexBuffer(squareVB);

		unsigned int squareindices[6] = { 0, 1, 2, 2, 3, 0 };
		Ref<IndexBuffer> squareIB;
		squareIB = IndexBuffer::Create(squareindices, 6);
		s_Data->QuadVertexArray->SetIndexBuffer(squareIB);



		s_Data->FlatColorShader = Shader::Create("assets/shaders/FlatColor.glsl");
	}

	void Renderer2D::ShutDown()
	{
		delete s_Data;
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		std::static_pointer_cast<OpenGLShader>(s_Data->FlatColorShader)->Bind();
		std::static_pointer_cast<OpenGLShader>(s_Data->FlatColorShader)->UploadUniformMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
		std::static_pointer_cast<OpenGLShader>(s_Data->FlatColorShader)->UploadUniformMat4("u_Transform", glm::mat4(1.0f));
	}

	void Renderer2D::EndScene()
	{

	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, color);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
	{
		std::static_pointer_cast<OpenGLShader>(s_Data->FlatColorShader)->Bind();
		std::static_pointer_cast<OpenGLShader>(s_Data->FlatColorShader)->UploadUniformFloat4("u_Color", color);

		s_Data->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}

}