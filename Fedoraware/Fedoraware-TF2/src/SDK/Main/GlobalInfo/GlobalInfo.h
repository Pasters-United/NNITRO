#pragma once
#include "../BaseEntity/BaseEntity.h"

constexpr auto DT_WAIT_CALLS = 26;

struct VelFixRecord {
	Vec3 m_vecOrigin;
	int m_nFlags;
	float m_flSimulationTime;
};

struct PlayerCache {
	Vec3 m_vecOrigin;
	Vec3 m_vecVelocity;
	Vec3 eyePosition;
	int playersPredictedTick;
	bool didDamage = false;
};

struct DormantData {
	Vec3 Location;
	float LastUpdate = 0.f;
};

struct DrawBullet {
	std::pair<Vec3, Vec3> m_line;
	float m_flTime;
	Color_t m_color;
	bool m_bZBuffer = false;
};

struct DrawLine {
	std::deque<std::pair<Vec3, Vec3>> m_line;
	float m_flTime;
	Color_t m_color;
	bool m_bZBuffer = false;
};

struct DrawBox {
	Vec3 m_vecPos;
	//Vec3 m_vecSize;
	Vec3 m_vecMins;
	Vec3 m_vecMaxs;
	Vec3 m_vecOrientation;
	float m_flTime;
	Color_t m_colorEdge;
	Color_t m_colorFace;
	bool m_bZBuffer = false;
};

namespace G
{
	inline std::pair<int, int> CurrentTarget = { 0, 0 }; // Index of the current aimbot target
	inline int CurItemDefIndex = 0; // DefIndex of the current weapon
	inline float LerpTime = 0.f;	//	current lerp time
	inline bool WeaponCanHeadShot = false; // Can the current weapon headshot?
	inline bool WeaponCanAttack = false; // Can the current weapon attack?
	inline bool WeaponCanSecondaryAttack = false;
	inline bool AntiAim = false; // Is the Anti-Aim active?
	inline bool AvoidingBackstab = false; // Are we currently avoiding a backstab? (Overwrites AA)
	inline bool FirstSpectated = false; // currently unused
	inline bool ThirdSpectated = false; // currently unused
	inline bool ShouldStop = false; // Stops our players movement, takes 1 tick.
	inline bool UnloadWndProcHook = false;
	inline bool Frozen = false;	//	angles & movement are frozen.

	/* Double tap / Tick shift */
	inline int ShiftedTicks = 0; // Amount of ticks that are shifted
	inline int ShiftedGoal = 0; // Amount of shifted ticks goal
	inline int WaitForShift = 0;
	inline bool DoubleTap = false;
	inline bool AntiWarp = false;
	inline bool Teleport = false;
	inline bool Recharge = false; // Are we currently recharging?
	inline int MaxShift = 24;

	/* Choking / Packets */
	inline int ChokeAmount = 0; // How many ticks have been choked
	inline int ChokeGoal = 0; // How many ticks should be choked
	inline int AnticipatedChoke = 0; // what the choke is expected to be (backtrack)
	inline bool UpdatingAnims = false;

	/* Aimbot */
	inline bool IsAttacking = false;
	inline bool PSilentAngles = false;
	inline bool SilentAngles = false;
	inline Vec3 AimPos = {};
	inline VMatrix WorldToProjection = {};

	/* Angles */
	inline Vec3 ViewAngles = {};
	inline Vec3 PunchAngles = {};

	/* Thirdperson Antiaim */
	inline bool Choking = false;
	inline std::vector<Vec3> ChokedAngles;

	/* Bullets */
	inline std::vector<DrawBullet> BulletsStorage;

	/* Prediction */
	inline Vec3 LinearPredLine = {};
	inline std::deque<std::pair<Vec3, Vec3>> MoveLines;
	inline std::deque<std::pair<Vec3, Vec3>> ProjLines;
	inline std::vector<DrawLine> LinesStorage;

	/* Boxes */
	inline std::vector<DrawBox> BoxesStorage;

	inline CUserCmd* CurrentUserCmd{nullptr}; // Unreliable! Only use this if you really have to.
	inline CUserCmd* LastUserCmd{nullptr};
	inline int Buttons = 0;
	inline bool AnimateKart = false;
	
	inline EWeaponType CurWeaponType = {};
	inline std::unordered_map<int, DormantData> DormantPlayerESP; // <Index, DormantData>
	inline std::unordered_map<int, int> ChokeMap; // Choked packets of players <Index, Amount>
	inline std::vector<int> MedicCallers;
	inline std::unordered_map<CBaseEntity*, VelFixRecord> VelFixRecords;

	inline std::unordered_map<uint32_t, std::vector<std::string>> PlayerTags; // This only contains tags, get priority through F::Playerlist

	inline bool InKeybind = false;
	inline bool DrawingStaticProps = false;
	inline bool ShouldUpdateMaterialCache = false;
};
