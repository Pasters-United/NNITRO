#pragma once
#include "../../Feature.h"

class CAutoAirblast
{
public:
	void Run(CBaseEntity* pLocal, CBaseCombatWeapon* pWeapon, CUserCmd* pCmd);
	int id;
};

ADD_FEATURE(CAutoAirblast, AutoAirblast)