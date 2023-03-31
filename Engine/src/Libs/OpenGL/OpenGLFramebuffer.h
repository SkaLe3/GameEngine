#pragma once
#include "Engine/Renderer/Framebuffer.h"
namespace Engine {

	class OpengGLFramebuffer :public Framebuffer
	{
	public:
		OpengGLFramebuffer(const FramebufferSpecification& spec);
		virtual ~OpengGLFramebuffer();

		void Invalidate();

		void Bind() override;
		void Unbind() override;

		virtual uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment; }

		virtual const FramebufferSpecification& GetSpecificaion() const override { return m_Specification; }
	private:
		uint32_t m_RendererID;
		uint32_t m_ColorAttachment, m_DepthAttachment;
		FramebufferSpecification m_Specification;
	};

}