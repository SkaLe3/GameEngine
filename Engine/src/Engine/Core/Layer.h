#pragma once

#include "Engine/Core/Core.h"
#include "Engine/Events/Event.h"
#include "Engine/Core/Timestep.h"
namespace Engine {


	class Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event& event) {}

	};
}


