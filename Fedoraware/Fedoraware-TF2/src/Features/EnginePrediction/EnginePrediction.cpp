#include "EnginePrediction.h"

#include "../TickHandler/TickHandler.h"

int CEnginePrediction::GetTickbase(CUserCmd* pCmd, CBaseEntity* pLocal)
{
	static int nTick = 0;
	static CUserCmd* pLastCmd = nullptr;

	if (pCmd)
	{
		if (!pLastCmd || pLastCmd->hasbeenpredicted)
			nTick = pLocal->m_nTickBase();
		else
			nTick++;
		pLastCmd = pCmd;
	}

	return nTick;
}

void CEnginePrediction::Start(CUserCmd* pCmd)
{
	CBaseEntity* pLocal = g_EntityCache.GetLocal();
	if (!pLocal || !pLocal->IsAlive() || !I::MoveHelper)
		return;

	pLocal->SetCurrentCmd(pCmd);

	*I::RandomSeed = MD5_PseudoRandom(pCmd->command_number) & std::numeric_limits<int>::max();

	m_nOldTickCount = I::GlobalVars->tickcount;
	m_fOldCurrentTime = I::GlobalVars->curtime;
	m_fOldFrameTime = I::GlobalVars->frametime;

	I::GlobalVars->tickcount = G::TickBase = GetTickbase(pCmd, pLocal);
	I::GlobalVars->curtime = TICKS_TO_TIME(I::GlobalVars->tickcount);
	I::GlobalVars->frametime = I::Prediction->m_bEnginePaused ? 0.0f : TICK_INTERVAL;

	// don't mess up eye pos with antiwarp (this might be able to be removed now, test)
	if (G::DoubleTap && Vars::CL_Move::DoubleTap::AntiWarp.Value && pLocal->OnSolid())
		return;

	const int nOldTickBase = pLocal->m_nTickBase();
	const bool bOldIsFirstPrediction = I::Prediction->m_bFirstTimePredicted;
	const bool bOldInPrediction = I::Prediction->m_bInPrediction;

	I::Prediction->m_bFirstTimePredicted = false;
	I::Prediction->m_bInPrediction = true;

	I::Prediction->SetLocalViewAngles(pCmd->viewangles);

	I::Prediction->SetupMove(pLocal, pCmd, I::MoveHelper, &m_MoveData);
	// demo charge fix pt 2 (still currently iffy without antiwarp occasionally)
	if (G::DoubleTap && G::CurWeaponType == EWeaponType::MELEE && pLocal->IsCharging() && F::Ticks.GetTicks(pLocal) <= 14)
		m_MoveData.m_flMaxSpeed = m_MoveData.m_flClientMaxSpeed = pLocal->TeamFortress_CalculateMaxSpeed(true);
	I::GameMovement->ProcessMovement(pLocal, &m_MoveData);
	// I::Prediction->FinishMove occasionally fucks with pCmd, might only be when respawning within a tick
	I::Prediction->FinishMove(pLocal, pCmd, &m_MoveData); // CRASH: read access violation. pCmd was 0x... (after call)

	pLocal->m_nTickBase() = nOldTickBase;
	I::Prediction->m_bFirstTimePredicted = bOldIsFirstPrediction;
	I::Prediction->m_bInPrediction = bOldInPrediction;
}

void CEnginePrediction::End(CUserCmd* pCmd)
{
	CBaseEntity* pLocal = g_EntityCache.GetLocal();
	if (!pLocal || !pLocal->IsAlive() || !I::MoveHelper)
		return;

	I::MoveHelper->SetHost(nullptr);

	I::GlobalVars->tickcount = m_nOldTickCount;
	I::GlobalVars->curtime = m_fOldCurrentTime;
	I::GlobalVars->frametime = m_fOldFrameTime;

	pLocal->SetCurrentCmd(nullptr);

	*I::RandomSeed = -1;
}