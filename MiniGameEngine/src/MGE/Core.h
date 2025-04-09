#pragma once

#ifdef MGE_PLATFORM_WINDOWS
	#ifdef MGE_BUILD_DLL
		#define MGE_API __declspec(dllexport)
	#else
		#define MGE_API __declspec(dllimport)
	#endif
#else
	#error MGE only supports windows!
#endif

#define MGE_ASSERT(x, ...) { if(!(x)) { MGE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define MGE_CORE_ASSERT(x, ...) { if(!(x)) { MGE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#define BIT(x) (1 << x)