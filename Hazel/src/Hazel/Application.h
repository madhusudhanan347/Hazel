#pragma once

#include"core.h"
#include"Events/Event.h"
#include"Hazel/Window.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	//Tp be defined in a client
	Application* CreateApplication();
}
