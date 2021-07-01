#pragma once

#include "Event.h"

namespace Hazel {

	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent( float x, float y)
			:m_MouseX(x), m_MouseY(y) {}

		inline int GetX() const { return m_MouseX; }
		inline int GetY() const { return m_MouseY; }


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << "," << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y)
			:m_OffsetX(x), m_OffsetY(y) {}

		inline int GetX() const { return m_OffsetX; }
		inline int GetY() const { return m_OffsetY; }


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_OffsetX << "," << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_OffsetX, m_OffsetY;
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton()	const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}
		int m_Button;
	};

	class HAZEL_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int Button)
			:MouseButtonEvent(Button) {}
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int Button)
			:MouseButtonEvent(Button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


}
