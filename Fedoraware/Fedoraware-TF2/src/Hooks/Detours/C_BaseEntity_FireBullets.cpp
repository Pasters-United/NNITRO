#include "../Hooks.h"
#include "../../Features/Commands/Commands.h"
#include "../../Features/Visuals/Visuals.h"

struct FireBulletsInfo_t
{
	FireBulletsInfo_t()
	{
		m_iShots = 1;
		m_vecSpread.Clear();
		m_flDistance = 8192;
		m_iTracerFreq = 4;
		m_flDamage = 0;
		m_iPlayerDamage = 0;
		m_pAttacker = nullptr;
		m_nFlags = 0;
		m_pAdditionalIgnoreEnt = nullptr;
		m_flDamageForceScale = 1.0f;
		m_bPrimaryAttack = true;
		m_bUseServerRandomSeed = false;
	}

	FireBulletsInfo_t(int nShots, const Vec3& vecSrc, const Vec3& vecDir, const Vec3& vecSpread, float flDistance,
					  int nAmmoType, bool bPrimaryAttack = true)
	{
		m_iShots = nShots;
		m_vecSrc = vecSrc;
		m_vecDirShooting = vecDir;
		m_vecSpread = vecSpread;
		m_flDistance = flDistance;
		m_iAmmoType = nAmmoType;
		m_iTracerFreq = 4;
		m_flDamage = 0;
		m_iPlayerDamage = 0;
		m_pAttacker = nullptr;
		m_nFlags = 0;
		m_pAdditionalIgnoreEnt = nullptr;
		m_flDamageForceScale = 1.0f;
		m_bPrimaryAttack = bPrimaryAttack;
		m_bUseServerRandomSeed = false;
	}

	int m_iShots = 0;
	Vec3 m_vecSrc = {};
	Vec3 m_vecDirShooting = {};
	Vec3 m_vecSpread = {};
	float m_flDistance = 0.f;
	int m_iAmmoType = 0;
	int m_iTracerFreq = 0;
	float m_flDamage = 0.f;
	int m_iPlayerDamage = 0; // Damage to be used instead of m_flDamage if we hit a player
	int m_nFlags = 0; // See FireBulletsFlags_t
	float m_flDamageForceScale = 0.f;
	CBaseEntity* m_pAttacker = nullptr;
	CBaseEntity* m_pAdditionalIgnoreEnt = nullptr;
	bool m_bPrimaryAttack = false;
	bool m_bUseServerRandomSeed = false;
};

using LookupAttachment_t = int(*)(CBaseEntity*, const char*);

void DrawBeam(const Vector& source, const Vector& end)
{
	BeamInfo_t beamInfo;
	beamInfo.m_nType = 0;
	beamInfo.m_pszModelName = Vars::Visuals::Beans::UseCustomModel.Value ? Vars::Visuals::Beans::Model.Value.c_str() : "sprites/physbeam.vmt";
	beamInfo.m_nModelIndex = -1; // will be set by CreateBeamPoints if its -1
	beamInfo.m_flHaloScale = 0.0f;
	beamInfo.m_flLife = Vars::Visuals::Beans::Life.Value;
	beamInfo.m_flWidth = Vars::Visuals::Beans::Width.Value;
	beamInfo.m_flEndWidth = Vars::Visuals::Beans::EndWidth.Value;
	beamInfo.m_flFadeLength = Vars::Visuals::Beans::FadeLength.Value;
	beamInfo.m_flAmplitude = Vars::Visuals::Beans::Amplitude.Value;
	beamInfo.m_flBrightness = Vars::Visuals::Beans::Brightness.Value;
	beamInfo.m_flSpeed = Vars::Visuals::Beans::Speed.Value;
	beamInfo.m_nStartFrame = 0;
	beamInfo.m_flFrameRate = 0;
	beamInfo.m_flRed = Vars::Visuals::Beans::Rainbow.Value ? floor(sin(I::GlobalVars->curtime + 0) * 128.0f + 128.0f) : Vars::Visuals::Beans::BeamColor.Value.r;
	beamInfo.m_flGreen = Vars::Visuals::Beans::Rainbow.Value ? floor(sin(I::GlobalVars->curtime + 2) * 128.0f + 128.0f) : Vars::Visuals::Beans::BeamColor.Value.g;
	beamInfo.m_flBlue = Vars::Visuals::Beans::Rainbow.Value ? floor(sin(I::GlobalVars->curtime + 4) * 128.0f + 128.0f) : Vars::Visuals::Beans::BeamColor.Value.b;
	beamInfo.m_nSegments = Vars::Visuals::Beans::Segments.Value;
	beamInfo.m_bRenderable = true;
	beamInfo.m_nFlags = Vars::Visuals::Beans::Flags.Value;
	beamInfo.m_vecStart = source;
	beamInfo.m_vecEnd = end;

	Beam_t* coolBeam = I::ViewRenderBeams->CreateBeamPoints(beamInfo);
	if (coolBeam)
		I::ViewRenderBeams->DrawBeam(coolBeam);
}

//C_BaseCombatWeapon_ItemPostFrame L"client.dll", L"E8 ? ? ? ? 80 BE ? ? ? ? ? 74 07 8B CE E8 ? ? ? ? 8B 06"
//C_TFWeaponBaseGun_PrimaryAttack L"client.dll", L"E8 ? ? ? ? A1 ? ? ? ? 8D 4D F0"
//C_TFWeaponBaseGun_FireProjectile L"client.dll", L"E8 ? ? ? ? 8B 8F ? ? ? ? 8B F0 33 C0"
//C_TFWeaponBaseGun_FireBullet L"client.dll", L"55 8B EC 83 EC 20 53 8B D9 56 57 89 5D FC"

bool FireBulletsHandler(CBaseCombatWeapon* pWeapon)
{
	static int nLastTickCount = 0;
	static int nLastBulletAmount = 0;
	static int nShotCount = 0;
	if (!pWeapon || pWeapon != g_EntityCache.GetWeapon() || !I::Prediction->m_bFirstTimePredicted)
	{
		nShotCount = 0;
		return false;
	}

	const int nBulletAmount = pWeapon->GetBulletAmount();

	if (nBulletAmount != nLastBulletAmount)
	{
		nShotCount = 0;
		nLastBulletAmount = nBulletAmount;
		return true;
	}

	if (nLastTickCount == I::GlobalVars->tickcount)
	{
		nShotCount++;
		if (nShotCount > nBulletAmount)
			return false;
	}
	nShotCount = 0;
	nLastTickCount = I::GlobalVars->tickcount;

	return true;
}

MAKE_HOOK(C_BaseEntity_FireBullets, S::CBaseEntity_FireBullets(), void, __fastcall,
	void* ecx, void* edx, CBaseCombatWeapon* pWeapon, const FireBulletsInfo_t& info, bool bDoEffects, int nDamageType, int nCustomDamageType)
{
	if (!FireBulletsHandler(pWeapon))
		return;

	if (const auto& pLocal = g_EntityCache.GetLocal())
	{
		if (!pLocal->IsInValidTeam())
			return;

		const Vec3 vStart = info.m_vecSrc;
		const Vec3 vEnd = vStart + info.m_vecDirShooting * info.m_flDistance;
		CGameTrace trace = {};
		CTraceFilterHitscan filter = {};
		filter.pSkip = pLocal;
		Utils::Trace(vStart, vEnd, MASK_SHOT | CONTENTS_GRATE, &filter, &trace);

		const int iAttachment = pWeapon->LookupAttachment("muzzle");
		pWeapon->GetAttachment(iAttachment, trace.vStartPos);

		const bool bCrit = nDamageType & DMG_CRITICAL || pLocal->IsCritBoosted(); // crithack mayb does something to nDamageType
		const int iTeam = pLocal->m_iTeamNum();

		auto& string = bCrit ? Vars::Visuals::Tracers::ParticleTracerCrits.Value : Vars::Visuals::Tracers::ParticleTracer.Value;
		if (string == "Off" || string == "Default")
			Hook.Original<FN>()(ecx, edx, pWeapon, info, bDoEffects, nDamageType, nCustomDamageType);
		else if (string == "Machina")
			Particles::ParticleTracer(iTeam == TEAM_RED ? "dxhr_sniper_rail_red" : "dxhr_sniper_rail_blue", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "C.A.P.P.E.R")
			Particles::ParticleTracer(iTeam == TEAM_RED ? "bullet_tracer_raygun_red" : "bullet_tracer_raygun_blue", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "Short Circuit")
			Particles::ParticleTracer(iTeam == TEAM_RED ? "dxhr_lightningball_hit_zap_red" : "dxhr_lightningball_hit_zap_blue", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "Merasmus ZAP")
			Particles::ParticleTracer("merasmus_zap", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "Merasmus ZAP 2")
			Particles::ParticleTracer("merasmus_zap_beam02", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "Big Nasty")
			Particles::ParticleTracer(iTeam == TEAM_RED ? "bullet_bignasty_tracer01_blue" : "bullet_bignasty_tracer01_red", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "Distortion Trail")
			Particles::ParticleTracer("tfc_sniper_distortion_trail", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else if (string == "Black Ink")
			Particles::ParticleTracer("merasmus_zap_beam01", trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);
		else
			Particles::ParticleTracer(string.c_str(), trace.vStartPos, trace.vEndPos, pLocal->GetIndex(), iAttachment, true);

		if (Vars::Visuals::Beans::Active.Value)
			DrawBeam(trace.vStartPos, trace.vEndPos);
	}
}