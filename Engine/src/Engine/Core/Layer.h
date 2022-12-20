#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Events/Event.h"
namespace Engine {


	class ENGINE_API Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

	};
}


