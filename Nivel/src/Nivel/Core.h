#pragma once

#ifdef	NV_PLATFORM_WINDOWS
	#ifdef NV_BUILD_DLL
		#define	NIVEL_API __declspec(dllexport)
	#else
		#define NIVEL_API __declspec(dllimport)
	#endif

#else
	#error Nivel only supports Windows!
#endif
