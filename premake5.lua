workspace "MiniGameEngine"
	architecture "x64"
	startproject "MGE-Editor"

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
IncludeDir["entt"] = "MiniGameEngine/vendor/entt/include"
IncludeDir["yaml_cpp"] = "MiniGameEngine/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "MiniGameEngine/vendor/ImGuizmo"
IncludeDir["box2d"] = "MiniGameEngine/vendor/box2d/include"

include "MiniGameEngine/vendor/glfw"
include "MiniGameEngine/vendor/glad"
include "MiniGameEngine/vendor/imgui"
include "MiniGameEngine/vendor/yaml-cpp"
include "MiniGameEngine/vendor/box2d"

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

		"%{prj.name}/vendor/ImGuizmo/ImGuizmo.h",
		"%{prj.name}/vendor/ImGuizmo/ImGuizmo.cpp"
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
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}",
		"%{IncludeDir.box2d}"
	}

	links 
	{ 
		"glfw",
		"glad",
		"imgui",
		"yaml-cpp",
		"box2d",
		"opengl32.lib"
	}

	filter "files:MiniGameEngine/vendor/ImGuizmo/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MGE_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
			"YAML_CPP_STATIC_DEFINE"
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
			"%{IncludeDir.imgui}",
			"%{IncludeDir.entt}",
			"%{IncludeDir.ImGuizmo}"
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