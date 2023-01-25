#include "pch.h"
#include "Engine/Renderer/Shader.h"
	
#include "Engine/Renderer/Renderer.h"

#include "Libs/OpenGL/OpenGLShader.h"


namespace Engine {
	
	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(filepath);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}
		
	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None: EG_ASSERT(false, "RendererAPI::None"); return nullptr;

		case RendererAPI::API::OpenGL: return CreateRef<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}
		EG_ASSERT(false, "Unknown Renderer API");
		return nullptr;
	}

	void ShaderLibrary::Add(const std::string& name, Ref<Shader>& shader)
	{
		EG_ASSERT(!Exists(name), "Shader already exists!");
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}


	Ref<Engine::Shader> ShaderLibrary::Load(const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	Ref<Engine::Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}

	Ref<Engine::Shader> ShaderLibrary::Get(const std::string& name)
	{
		EG_ASSERT(Exists(name), "Shader not found!");
		return m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

}