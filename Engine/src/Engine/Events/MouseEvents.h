#pragma once

#include "Event.h"
#include "Engine/Core/MouseCodes.h"

namespace Engine {

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(double x, double y) : m_MouseX(x), m_MouseY(y) {}
		
		double GetX() const { return m_MouseX; }
		double GetY() const { return m_MouseY; }

		static EventType GetStaticType() { return EventType::MouseMoved; }
		virtual EventType GetEventType() const override { return GetStaticType(); }

	private: 
		double m_MouseX, m_MouseY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseCode GetMouseButton() const { return m_Button; }

	protected: 
		MouseButtonEvent(const MouseCode button) : m_Button(button){}

		MouseCode m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}

		static EventType GetStaticType() { return EventType::MouseButtonPressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

		static EventType GetStaticType() { return EventType::MouseButtonReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
	};
}