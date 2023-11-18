#include "../Hooks.h"

MAKE_HOOK(CBaseAnimating_UpdateClientSideAnimation, S::CBaseAnimating_UpdateClientSideAnimation(), void, __fastcall,
	void* ecx, void* edx)
{
	if (!G::UpdatingAnims && Vars::Misc::DisableInterpolation.Value)
		return;

	auto pEntity = reinterpret_cast<CBaseEntity*>(ecx);
	if (!pEntity || pEntity->m_flSimulationTime() == pEntity->m_flOldSimulationTime() || pEntity == g_EntityCache.GetLocal())
		return;

	Hook.Original<FN>()(ecx, edx);
}