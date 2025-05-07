#include "precompiled.h"
#include "MGE/Core/Window.h"

#ifdef MGE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace MGE
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef MGE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		MGE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}