#include <Engine.h>
#include <Engine/Core/EntryPoint.h>
#include <iostream>

#include "glm/glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include "Libs/OpenGL/OpenGLShader.h"
#include "Engine/Renderer/Shader.h"
#include "Layer2D.h"


class Example : public Engine::Layer
{
public:
	Example() : Layer(), m_CameraController(1920.0f/1080.0f, true)

	{
		m_VertexArray = Engine::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.1f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.1f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.1f, 1.0f
		};

		Engine::Ref<Engine::VertexBuffer> vertexBuffer;
		vertexBuffer = Engine::VertexBuffer::Create(vertices, sizeof(vertices));

		Engine::BufferLayout layout = {
			{ Engine::ShaderDataType::Float3, "a_Position"},
			{ Engine::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);


		m_VertexArray->AddVertexBuffer(vertexBuffer);
		unsigned int indices[3] = { 0, 1, 2 };
		Engine::Ref<Engine::IndexBuffer> indexBuffer;
		indexBuffer = Engine::IndexBuffer::Create(indices, 3);
		m_VertexArray->SetIndexBuffer(indexBuffer);


		float squarevertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f

		};

		m_SquareVA = Engine::VertexArray::Create();
		Engine::Ref<Engine::VertexBuffer> squareVB;
		squareVB = Engine::VertexBuffer::Create(squarevertices, sizeof(squarevertices));


		Engine::BufferLayout squarelayout = {
			{ Engine::ShaderDataType::Float3, "a_Position"},
			{ Engine::ShaderDataType::FLoat2, "a_TexCoord"}
		};
		squareVB->SetLayout(squarelayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareindices[6] = { 0, 1, 2, 2, 3, 0 };
		Engine::Ref<Engine::IndexBuffer> squareIB;
		squareIB = Engine::IndexBuffer::Create(squareindices, 6);
		m_SquareVA->SetIndexBuffer(squareIB);


		std::string	vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}	
		)";

		std::string	fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;
			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				a_Color = vec4(v_Position*0.5+0.5, 1.0);
				a_Color = v_Color;
				
			}	
		)";
		m_Shader = Engine::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);


		std::string	vertexSrc2 = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}	
		)";

		std::string	fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;
			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				a_Color = vec4(u_Color, 1.0);

				
			}	
		)";

		m_Shader2 = Engine::Shader::Create("FlatColor", vertexSrc2, fragmentSrc2);

		

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Engine::Texture2D::Create("assets/textures/CheckerBoard.png");
		m_TextureLogo = Engine::Texture2D::Create("assets/textures/StillAliveCat.png");

		std::static_pointer_cast<Engine::OpenGLShader>(textureShader)->Bind();
		std::static_pointer_cast<Engine::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}
	void OnUpdate(Engine::Timestep ts) override
	{
		m_CameraController.OnUpdate(ts);
		Engine::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1 });
		Engine::RenderCommand::Clear();



		Engine::Renderer::BeginScene(m_CameraController.GetCamera());
		 

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::static_pointer_cast<Engine::OpenGLShader>(m_Shader2)->Bind();
		std::static_pointer_cast<Engine::OpenGLShader>(m_Shader2)->UploadUniformFloat3("u_Color", m_SquareColor);
		for (int y = 0; y < 20; y++) 
		{

			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Engine::Renderer::Submit(m_Shader2, m_SquareVA, transform);

			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");
		m_Texture->Bind();
		Engine::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_TextureLogo->Bind();
		Engine::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		//Engine::Renderer::Submit(m_Shader, m_VertexArray);

		Engine::Renderer::EndScene();
	}
	void OnEvent(Engine::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

private:
	Engine::ShaderLibrary m_ShaderLibrary;
	Engine::Ref<Engine::Shader> m_Shader;
	std::shared_ptr<Engine::VertexArray> m_VertexArray;


	std::shared_ptr<Engine::Shader> m_Shader2;
	std::shared_ptr<Engine::VertexArray> m_SquareVA;

	Engine::Ref<Engine::Texture2D> m_Texture;
	Engine::Ref<Engine::Texture2D> m_TextureLogo;

	Engine::OrthographicCameraController m_CameraController;


	glm::vec3 m_SquareColor = { 0.2f, 0.4f, 0.8f };

};


class StillAliveApp : public  Engine::Application
{
public:
	StillAliveApp()
	{
		//PushLayer(new Example());
		PushLayer(new Sandbox2D);
	}
	~StillAliveApp()
	{

	}

private:
	


};

Engine::Application* Engine::CreateApplication()
{
	return new StillAliveApp();
}