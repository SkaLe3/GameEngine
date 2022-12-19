#pragma once

#include "Event.h"
#include "Engine/Core/KeyCodes.h"

namespace Engine
{
	class ENGINE_API KeyEvent : public Event
	{
	public:
		KeyCode GetKeyCode() const { return m_KeyCode; }

	protected:
		KeyEvent(KeyCode keycode) : m_KeyCode(keycode) {}
		KeyCode m_KeyCode;
	};

	class ENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode, bool isRepeat = false)
			: KeyEvent(keycode), m_IsRepeat(isRepeat) {}

		bool isRepeat() const { return m_IsRepeat; }

		static EventType GetStaticType() { return EventType::KeyPressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }

	private:
		int m_IsRepeat;
	};

	class ENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode): KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
	};

	class ENGINE_API KeyEnteredEvent : public KeyEvent
	{
	public:
		KeyEnteredEvent(const KeyCode keycode) : KeyEvent(keycode) {}

		static EventType GetStaticType() { return EventType::KeyEntered; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
	};
}
