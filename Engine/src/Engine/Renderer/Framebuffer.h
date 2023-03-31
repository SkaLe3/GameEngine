#pragma once
#include "Engine/Core/Core.h"

namespace Engine {

	struct FramebufferSpecification
	{
		uint32_t Width, Height;
		uint32_t Samples;

		bool SwapChainTrager = false;

	};



	class Framebuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual const FramebufferSpecification& GetSpecificaion() const = 0;

		virtual uint32_t GetColorAttachmentRendererID() const = 0;

		static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
	private:
	};

}