#ifdef HARA_PLATFORM_WINDOWS
#ifdef HARA_BUILD_DLL
#define HARA_API __declspec(dllexport)
#else
#define HARA_API __declspec(dllimport)
#endif
#else
#error Only windows for now
#endif