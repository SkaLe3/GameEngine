#include <Engine.h>
#include <iostream>

#include "glm/glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include "Libs/OpenGL/OpenGLShader.h"
#include "Engine/Renderer/Shader.h"


class Example : public Engine::Layer
{
public:
	Example() : Layer(), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)

	{
		Engine::Application::Get().GetWindow().SetVSync(0);
		m_VertexArray.reset(Engine::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.1f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.1f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.1f, 1.0f
		};

		Engine::Ref<Engine::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Engine::VertexBuffer::Create(vertices, sizeof(vertices)));

		Engine::BufferLayout layout = {
			{ Engine::ShaderDataType::Float3, "a_Position"},
			{ Engine::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);


		m_VertexArray->AddVertexBuffer(vertexBuffer);
		unsigned int indices[3] = { 0, 1, 2 };
		Engine::Ref<Engine::IndexBuffer> indexBuffer;
		indexBuffer.reset(Engine::IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		float squarevertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f

		};

		m_SquareVA.reset(Engine::VertexArray::Create());
		Engine::Ref<Engine::VertexBuffer> squareVB;
		squareVB.reset(Engine::VertexBuffer::Create(squarevertices, sizeof(squarevertices)));


		Engine::BufferLayout squarelayout = {
			{ Engine::ShaderDataType::Float3, "a_Position"},
			{ Engine::ShaderDataType::FLoat2, "a_TexCoord"}
		};
		squareVB->SetLayout(squarelayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareindices[6] = { 0, 1, 2, 2, 3, 0 };
		Engine::Ref<Engine::IndexBuffer> squareIB;
		squareIB.reset(Engine::IndexBuffer::Create(squareindices, 6));
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
		m_Shader.reset(Engine::Shader::Create(vertexSrc, fragmentSrc));

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

		m_Shader2.reset(Engine::Shader::Create(vertexSrc2, fragmentSrc2));

		std::string	textureVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_TexCoord;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			out vec2 v_TexCoord;

			void main()
			{
				v_TexCoord = a_TexCoord;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}	
		)";

		std::string	textureFragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;
			
			in vec2 v_TexCoord;
			uniform sampler2D u_Texture;

			void main()
			{
				a_Color = texture(u_Texture, v_TexCoord);

				
			}	
		)";

		m_TextureShader.reset(Engine::Shader::Create(textureVertexSrc, textureFragmentSrc2));

		m_Texture = Engine::Texture2D::Create("assets/textures/CheckerBoard.png");
		m_TextureLogo = Engine::Texture2D::Create("assets/textures/StillAliveCat.png");

		std::static_pointer_cast<Engine::OpenGLShader>(m_TextureShader)->Bind();
		std::static_pointer_cast<Engine::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}
	void OnUpdate(Engine::Timestep ts) override
	{
		//EG_TRACE("FPS Debug: ", int(1.0/ts));
		if (Engine::Input::IsKeyPressed(Engine::Key::A)) 
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;

		else if (Engine::Input::IsKeyPressed(Engine::Key::D))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Engine::Input::IsKeyPressed(Engine::Key::S))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		else if (Engine::Input::IsKeyPressed(Engine::Key::W))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		if (Engine::Input::IsKeyPressed(Engine::Key::Left))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Engine::Input::IsKeyPressed(Engine::Key::Right))
			m_CameraRotation -= m_CameraRotationSpeed * ts;





		Engine::RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1 });
		Engine::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.Setrotation(m_CameraRotation);

		Engine::Renderer::BeginScene(m_Camera);
		 

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

		m_Texture->Bind();
		Engine::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_TextureLogo->Bind();
		Engine::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		//Engine::Renderer::Submit(m_Shader, m_VertexArray);

		Engine::Renderer::EndScene();
	}
	void OnEvent(Engine::Event& event) override
	{

	}

private:
	Engine::Ref<Engine::Shader> m_Shader;
	std::shared_ptr<Engine::VertexArray> m_VertexArray;


	std::shared_ptr<Engine::Shader> m_Shader2, m_TextureShader;
	std::shared_ptr<Engine::VertexArray> m_SquareVA;

	Engine::Ref<Engine::Texture2D> m_Texture;
	Engine::Ref<Engine::Texture2D> m_TextureLogo;

	Engine::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition; 
	float m_CameraRotation = 0.0f;
	float m_CameraMoveSpeed = 5.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.4f, 0.8f };

};


class StillAliveApp : public  Engine::Application
{
public:
	StillAliveApp()
	{
		PushLayer(new Example());
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