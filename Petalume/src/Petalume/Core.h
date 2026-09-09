#pragma once

#ifdef PL_PLATFORM_WINDOWS
	#ifdef PL_BUILD_DLL
		#define PETALUME_API __declspec(dllexport)
	#else
		#define PETALUME_API __declspec(dllimport)
	#endif
#else
	#error Petalume only supports Windows!
#endif


#define BIT(x) (1 << x)