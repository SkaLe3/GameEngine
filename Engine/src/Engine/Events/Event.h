#pragma once
#include <string>
#include "Engine/Core/Core.h"
#include <sstream>



#define EVENT_TYPE(type) virtual const char* GetName() const override { return #type; }

namespace Engine {

	 
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowLostFocus, WindowGainedFocus,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
	public:
		virtual ~Event() = default;
		bool m_Handled = false;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

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

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

