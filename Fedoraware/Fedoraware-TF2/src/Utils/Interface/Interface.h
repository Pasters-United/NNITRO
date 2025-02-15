#pragma once

#include <Windows.h>

class CInterface
{
private:
	typedef void*(*InstantiateInterface)();

	struct Interface_t
	{
		InstantiateInterface Interface;
		PCHAR szInterfaceName;
		Interface_t *NextInterface;
	};

public:
	template<typename T>
	__inline T Get(LPCSTR szModule, PCCH szObject)
	{
		if (const auto hModule = GetModuleHandleA(szModule))
		{
			if (const auto fnFactory = reinterpret_cast<void* (__cdecl*)(const char* pName, int* pReturnCode)>(GetProcAddress(hModule, "CreateInterface")))
			{
				return reinterpret_cast<T>(fnFactory(szObject, nullptr));
			}
		}

		return nullptr;
	}
};

inline CInterface g_Interface;