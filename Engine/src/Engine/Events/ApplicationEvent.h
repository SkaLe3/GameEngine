#pragma once

#include "Event.h"

namespace Engine {

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		static EventType GetStaticType() { return EventType::WindowClose; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(WindowClose)
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		static EventType GetStaticType() { return EventType::WindowResize; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};
}