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
		EVENT_TYPE(MouseMoved)
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
	private: 
		double m_MouseX, m_MouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent( const float xOffset, const float yOffset)
			:  m_YOffset(yOffset), m_XOffset(xOffset) {}

		float GetYOffset() const { return m_YOffset; }
		float GetXOffset() const { return m_XOffset; }

		static EventType GetStaticType() { return EventType::MouseScrolled; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(MouseScrolled)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}
	private:
		float m_YOffset, m_XOffset;
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
		EVENT_TYPE(MouseButtonPressed)
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

		static EventType GetStaticType() { return EventType::MouseButtonReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(MouseButtonReleased)
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
	};
}