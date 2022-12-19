#pragma once

#include "Engine/Core/Core.h"
#include "SFML/Window/Event.hpp"
namespace Engine {

	using EventType = sf::Event::EventType;
	 
	/*enum class EventType
	{
		None = 0,
		WindowClose,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved
	};*/

	class ENGINE_API Event
	{
	public:
		virtual ~Event() = default;
		bool m_Handled = false;
		virtual EventType GetEventType() const = 0;
	};

	class EventManager
	{
	public:
		EventManager(Event& event) : m_Event(event){}

		template<typename T, typename F>
		bool Manage(const F& func)
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

