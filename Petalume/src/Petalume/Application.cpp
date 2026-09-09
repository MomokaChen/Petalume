#include "plpch.h"
#include "Application.h"

#include "Petalume/Events/ApplicationEvent.h"
#include "Petalume/Log.h"

namespace Petalume {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			PL_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			PL_TRACE(e.ToString());
		}

		while (true);
	}

}