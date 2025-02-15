#include "FakeAng.h"

#include "../../PacketManip/AntiAim/AntiAim.h"

//gets called after fakelag.

void CFakeAng::Run(CUserCmd* pCmd)
{
	if (const auto& pLocal = g_EntityCache.GetLocal())
	{
		if (!pCmd)
			return;

		if (pLocal->IsAlive() && !pLocal->IsAGhost())
		{
			if (const auto& pAnimState = pLocal->GetAnimState()) // doesn't work with certain cosmetics equipped
			{
				Math::Clamp(F::AntiAim.vFakeAngles.x, -89.f, 89.f);

				float flOldFrameTime = I::GlobalVars->frametime;
				int nOldSequence = pLocal->m_nSequence();
				float flOldCycle = pLocal->m_flCycle();
				auto pOldPoseParams = pLocal->GetPoseParam();
				char pOldAnimState[sizeof(CTFPlayerAnimState)] = {};
				memcpy(pOldAnimState, pAnimState, sizeof(CTFPlayerAnimState));

				I::GlobalVars->frametime = 0.f;

				pAnimState->m_flCurrentFeetYaw = F::AntiAim.vFakeAngles.y;
				pAnimState->m_flGoalFeetYaw = F::AntiAim.vFakeAngles.y;
				pAnimState->Update(F::AntiAim.vFakeAngles.y, F::AntiAim.vFakeAngles.x);

				matrix3x4 bones[128];
				if (pLocal->SetupBones(bones, 128, BONE_USED_BY_ANYTHING, I::GlobalVars->curtime))
					BoneMatrix = *reinterpret_cast<FakeMatrixes*>(bones);

				I::GlobalVars->frametime = flOldFrameTime;
				pLocal->m_nSequence() = nOldSequence;
				pLocal->m_flCycle() = flOldCycle;
				pLocal->SetPoseParam(pOldPoseParams);
				memcpy(pAnimState, pOldAnimState, sizeof(CTFPlayerAnimState));
			}
		}
	}
}