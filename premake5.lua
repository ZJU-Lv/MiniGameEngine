workspace "MiniGameEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["glfw"] = "MiniGameEngine/vendor/glfw/include"
IncludeDir["glad"] = "MiniGameEngine/vendor/glad/include"
IncludeDir["imgui"] = "MiniGameEngine/vendor/imgui"
IncludeDir["glm"] = "MiniGameEngine/vendor/glm"
IncludeDir["stb_image"] = "MiniGameEngine/vendor/stb_image"

include "MiniGameEngine/vendor/glfw"
include "MiniGameEngine/vendor/glad"
include "MiniGameEngine/vendor/imgui"

project "MiniGameEngine"
	location "MiniGameEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    buildoptions { "/utf-8" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "precompiled.h"
	pchsource "MiniGameEngine/src/precompiled.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"glfw",
		"glad",
		"imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MGE_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "MGE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MGE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MGE_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

    buildoptions { "/utf-8" }

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"MiniGameEngine/vendor/spdlog/include",
		"MiniGameEngine/src",
		"MiniGameEngine/vendor",
		"%{IncludeDir.glm}",
        "%{IncludeDir.imgui}"
	}

	links
	{
		"MiniGameEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MGE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MGE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MHE_DIST"
		runtime "Release"
		optimize "on"
		

project "MGE-Editor"
		location "MGE-Editor"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
	
		buildoptions { "/utf-8" }
	
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
	
		includedirs
		{
			"MiniGameEngine/vendor/spdlog/include",
			"MiniGameEngine/src",
			"MiniGameEngine/vendor",
			"%{IncludeDir.glm}",
			"%{IncludeDir.imgui}"
		}
	
		links
		{
			"MiniGameEngine"
		}
	
		filter "system:windows"
			systemversion "latest"
	
			defines
			{
				"MGE_PLATFORM_WINDOWS"
			}
	
		filter "configurations:Debug"
			defines "MGE_DEBUG"
			runtime "Debug"
			symbols "on"
	
		filter "configurations:Release"
			defines "MGE_RELEASE"
			runtime "Release"
			optimize "on"
	
		filter "configurations:Dist"
			defines "MHE_DIST"
			runtime "Release"
			optimize "on"