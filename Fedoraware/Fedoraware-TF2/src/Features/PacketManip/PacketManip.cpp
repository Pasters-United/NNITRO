#include "PacketManip.h"

inline bool CPacketManip::WillTimeOut()
{
	INetChannel* iNetChan = I::EngineClient->GetNetChannelInfo();
	if (!iNetChan)
		return false;

	return iNetChan->m_nChokedPackets >= 22;
}

inline bool CPacketManip::AACheck(CUserCmd* pCmd)
{
	INetChannel* iNetChan = I::EngineClient->GetNetChannelInfo();
	CBaseEntity* pLocal = g_EntityCache.GetLocal();
	if (!iNetChan || !pLocal)
		return false;

	if ((G::DoubleTap || G::Teleport) && G::ShiftedTicks == G::ShiftedGoal)
		return false;

	return iNetChan->m_nChokedPackets < 3 && F::AntiAim.ShouldAntiAim(pLocal);
}

void CPacketManip::CreateMove(CUserCmd* pCmd, bool* pSendPacket)
{
	*pSendPacket = true;

	// prevent overchoking by just not running anything below if we believe it will cause us to time out
	if (!WillTimeOut())
	{
		// anti aim will no longer set pSendPacket to false/true
		if (AACheck(pCmd))
		{
			*pSendPacket = false;
			F::AntiAim.Run(pCmd, pSendPacket);
			return;
		}
		else if (G::PSilentAngles)
			return;
		// F::AntiAim.Run(pCmd, pSendPacket);
		F::FakeLag.Run(pCmd, pSendPacket);
	}
	else
		G::ChokeAmount = 0;

	//if (G::DoubleTap)
	//	*pSendPacket = G::ShiftedTicks == 1;
	//if (*pSendPacket)
	//{ // if we are now sending we need to run antiaim again for our fake angle.
	//	F::AntiAim.Run(pCmd, pSendPacket);
	//}

	return F::AntiAim.Run(pCmd, pSendPacket);
}