#pragma once

#include "Event.h"
#include "Engine/Core/KeyCodes.h"

namespace Engine
{
	class KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(KeyCode keycode) : m_KeyCode(keycode) {}
		KeyCode m_KeyCode;

		
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode)
			: KeyEvent(keycode)  {}

		//bool isRepeat() const { return m_IsRepeat; }

		static EventType GetStaticType() { return EventType::KeyPressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(KeyPressed)
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode): KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(KeyReleasedEvent)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyTyped; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		EVENT_TYPE(KeyTyped)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}
	};
}
