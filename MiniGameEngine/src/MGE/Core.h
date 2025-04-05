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