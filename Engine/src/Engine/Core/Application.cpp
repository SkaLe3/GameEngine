#include "pch.h"
#include "Application.h"
#include "Window.h"

#include "Engine/Renderer/Renderer.h"
#include "Engine/Core/Input.h"

#include "Engine/Renderer/Renderer.h"



namespace Engine {

	Application* Application::s_Instance = nullptr;

	
	Application::Application()
	{
		Log::GetLogger()->Init();
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		m_VertexArray.reset(VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.1f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.1f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.1f, 1.0f 
		};

		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		BufferLayout layout = {
			{ ShaderDataType::Float3, "a_Position"},
			{ ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout); 

		
		m_VertexArray->AddVertexBuffer(vertexBuffer);
		unsigned int indices[3] = { 0, 1, 2 };
		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices, 3));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		float squarevertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,

		};

		m_SquareVA.reset(VertexArray::Create());
		std::shared_ptr<VertexBuffer> squareVB;
		squareVB.reset(VertexBuffer::Create(squarevertices, sizeof(squarevertices)));


		BufferLayout squarelayout = {
			{ ShaderDataType::Float3, "a_Position"}
		};
		squareVB->SetLayout(squarelayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		unsigned int squareindices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<IndexBuffer> squareIB;
		squareIB.reset(IndexBuffer::Create(squareindices, 6));
		m_SquareVA->SetIndexBuffer(squareIB);


		std::string	vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);
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
		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));

		std::string	vertexSrc2 = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;


			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
			}	
		)";

		std::string	fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 a_Color;
			in vec3 v_Position;

			void main()
			{
				a_Color = vec4(0.2, 0.3, 0.8, 1.0);

				
			}	
		)";

		m_Shader2.reset(new Shader(vertexSrc2, fragmentSrc2));
	}


	Application::~Application() 
	{
	}
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClosed));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
			
		}

	}

	void Application::Run()
	{
		while (m_Running) {


			RenderCommand::SetClearColor({ 0.15f, 0.15f, 0.15f, 1 });
			RenderCommand::Clear();

			
			m_Shader2->Bind();
			Renderer::Submit(m_SquareVA);
			 
			m_Shader->Bind();
			Renderer::Submit(m_VertexArray);

			Renderer::EndScene();


			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();

	}

	void Application::PopLayer(Layer* layer)
	{
		m_LayerStack.PopLayer(layer);
		layer->OnDetach();
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}