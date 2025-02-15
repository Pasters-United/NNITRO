#include "../Hooks.h"

namespace S
{
	MAKE_SIGNATURE(CTFPlayerShared_IsPlayerDominated_Desired, CLIENT_DLL, "84 C0 74 ? 80 7D ? ? 74 ? 8B 83", 0x0);
	MAKE_SIGNATURE(CTFPlayerShared_IsPlayerDominated_Jump, CLIENT_DLL, "89 45 BC E8 ? ? ? ? 3B C7 75 1D 80 7D F8 00 75 17 8B 4D C0", 0x0);
}

MAKE_HOOK(CTFPlayerShared_IsPlayerDominated, S::CTFPlayerShared_IsPlayerDominated(), bool, __fastcall,
	void* ecx, void* edx, int index)
{
	static auto dwDesired = S::CTFPlayerShared_IsPlayerDominated_Desired();
	static auto dwJump = S::CTFPlayerShared_IsPlayerDominated_Jump();
	const auto dwRetAddr = reinterpret_cast<DWORD>(_ReturnAddress());

	const bool bResult = Hook.Original<FN>()(ecx, edx, index);

	if (!bResult && Vars::Visuals::RevealScoreboard.Value)
	{
		if (dwRetAddr == dwDesired)
			*static_cast<uintptr_t*>(_AddressOfReturnAddress()) = dwJump;
	}

	return bResult;
}