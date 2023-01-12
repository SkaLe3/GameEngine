#pragma once

#include "Engine/Core/Core.h"
namespace Engine {

	 
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowLostFocus, WindowGainedFocus,
		KeyPressed, KeyReleased, KeyEntered,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
	public:
		virtual ~Event() = default;
		bool m_Handled = false;
		virtual EventType GetEventType() const = 0;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event) : m_Event(event){}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}

