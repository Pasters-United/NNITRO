#pragma once

#include "Const.h"

enum
{
	PARTITION_ENGINE_SOLID_EDICTS = (1 << 0),		// every edict_t that isn't SOLID_TRIGGER or SOLID_NOT (and static props)
	PARTITION_ENGINE_TRIGGER_EDICTS = (1 << 1),		// every edict_t that IS SOLID_TRIGGER
	PARTITION_CLIENT_SOLID_EDICTS = (1 << 2),
	PARTITION_CLIENT_RESPONSIVE_EDICTS = (1 << 3),		// these are client-side only objects that respond to being forces, etc.
	PARTITION_ENGINE_NON_STATIC_EDICTS = (1 << 4),		// everything in solid & trigger except the static props, includes SOLID_NOTs
	PARTITION_CLIENT_STATIC_PROPS = (1 << 5),
	PARTITION_ENGINE_STATIC_PROPS = (1 << 6),
	PARTITION_CLIENT_NON_STATIC_EDICTS = (1 << 7),		// everything except the static props
};

enum MM_PlayerConnectionState_t
{
	MM_DISCONNECTED = 0,
	MM_CONNECTED,
	MM_CONNECTING, // the server knows that this player is coming
	MM_LOADING, // loading into the server
	MM_WAITING_FOR_PLAYER
};

enum EStereoEye
{
	STEREO_EYE_MONO = 0,
	STEREO_EYE_LEFT = 1,
	STEREO_EYE_RIGHT = 2,
	STEREO_EYE_MAX = 3,
};

enum EPreviewImageRetVal
{
	MATERIAL_PREVIEW_IMAGE_BAD = 0,
	MATERIAL_PREVIEW_IMAGE_OK,
	MATERIAL_NO_PREVIEW_IMAGE,
};

enum EMaterialVarFlags
{
	MATERIAL_VAR_DEBUG = (1 << 0),
	MATERIAL_VAR_NO_DEBUG_OVERRIDE = (1 << 1),
	MATERIAL_VAR_NO_DRAW = (1 << 2),
	MATERIAL_VAR_USE_IN_FILLRATE_MODE = (1 << 3),
	MATERIAL_VAR_VERTEXCOLOR = (1 << 4),
	MATERIAL_VAR_VERTEXALPHA = (1 << 5),
	MATERIAL_VAR_SELFILLUM = (1 << 6),
	MATERIAL_VAR_ADDITIVE = (1 << 7),
	MATERIAL_VAR_ALPHATEST = (1 << 8),
	MATERIAL_VAR_ZNEARER = (1 << 10),
	MATERIAL_VAR_MODEL = (1 << 11),
	MATERIAL_VAR_FLAT = (1 << 12),
	MATERIAL_VAR_NOCULL = (1 << 13),
	MATERIAL_VAR_NOFOG = (1 << 14),
	MATERIAL_VAR_IGNOREZ = (1 << 15),
	MATERIAL_VAR_DECAL = (1 << 16),
	MATERIAL_VAR_ENVMAPSPHERE = (1 << 17),
	MATERIAL_VAR_ENVMAPCAMERASPACE = (1 << 19),
	MATERIAL_VAR_BASEALPHAENVMAPMASK = (1 << 20),
	MATERIAL_VAR_TRANSLUCENT = (1 << 21),
	MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
	MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = (1 << 23),
	MATERIAL_VAR_OPAQUETEXTURE = (1 << 24),
	MATERIAL_VAR_ENVMAPMODE = (1 << 25),
	MATERIAL_VAR_SUPPRESS_DECALS = (1 << 26),
	MATERIAL_VAR_HALFLAMBERT = (1 << 27),
	MATERIAL_VAR_WIREFRAME = (1 << 28),
	MATERIAL_VAR_ALLOWALPHATOCOVERAGE = (1 << 29),
	MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY = (1 << 30),
	MATERIAL_VAR_VERTEXFOG = (1 << 31),
};

enum class EOverrideType
{
	OVERRIDE_NORMAL = 0,
	OVERRIDE_BUILD_SHADOWS,
	OVERRIDE_DEPTH_WRITE,
	OVERRIDE_SSAO_DEPTH_WRITE,
};

enum EWeaponSlots
{
	SLOT_PRIMARY,
	SLOT_SECONDARY,
	SLOT_MELEE
};

enum class EImageFormat
{
	IMAGE_FORMAT_UNKNOWN = -1,
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,
	IMAGE_FORMAT_RGB323232F,
	IMAGE_FORMAT_RGBA32323232F,
	IMAGE_FORMAT_NV_DST16,
	IMAGE_FORMAT_NV_DST24,
	IMAGE_FORMAT_NV_INTZ,
	IMAGE_FORMAT_NV_RAWZ,
	IMAGE_FORMAT_ATI_DST16,
	IMAGE_FORMAT_ATI_DST24,
	IMAGE_FORMAT_NV_NULL,
	IMAGE_FORMAT_ATI2N,
	IMAGE_FORMAT_ATI1N,
	IMAGE_FORMAT_DXT1_RUNTIME,
	IMAGE_FORMAT_DXT5_RUNTIME,
	NUM_IMAGE_FORMATS
};

enum ETraceType
{
	TRACE_EVERYTHING,
	TRACE_WORLD_ONLY,
	TRACE_ENTITIES_ONLY,
	TRACE_EVERYTHING_FILTER_PROPS,
};

enum ESurfaceFlags
{
	DISPSURF_FLAG_SURFACE          = (1 << 0),
	DISPSURF_FLAG_WALKABLE         = (1 << 1),
	DISPSURF_FLAG_BUILDABLE        = (1 << 2),
	DISPSURF_FLAG_SURFPROP1        = (1 << 3),
	DISPSURF_FLAG_SURFPROP2        = (1 << 4),
};

enum class EFontDrawType
{
	// Use the "additive" value from the scheme file
	FONT_DRAW_DEFAULT              = 0,

	// Overrides
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,

	FONT_DRAW_TYPE_COUNT           = 2,
};

enum class EClientFrameStage
{
	FRAME_UNDEFINED                = -1,
	FRAME_START,

	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,

	FRAME_RENDER_START,
	FRAME_RENDER_END
};

enum ETFClass
{
	CLASS_NONE                     = 0,
	CLASS_SCOUT,
	CLASS_SNIPER,
	CLASS_SOLDIER,
	CLASS_DEMOMAN,
	CLASS_MEDIC,
	CLASS_HEAVY,
	CLASS_PYRO,
	CLASS_SPY,
	CLASS_ENGINEER
};

enum struct ETFClassID
{
	CTFWearableRazorback = 341,
	CTFWearableDemoShield = 338,
	CTFWearableLevelableItem = 340,
	CTFWearableCampaignItem = 337,
	CTFBaseRocket = 185,
	CTFWeaponBaseMerasmusGrenade = 325,
	CTFWeaponBaseMelee = 324,
	CTFWeaponBaseGun = 323,
	CTFWeaponBaseGrenadeProj = 322,
	CTFWeaponBase = 321,
	CTFWearableRobotArm = 342,
	CTFRobotArm = 287,
	CTFWrench = 344,
	CTFProjectile_ThrowableBreadMonster = 279,
	CTFProjectile_ThrowableBrick = 280,
	CTFProjectile_ThrowableRepel = 281,
	CTFProjectile_Throwable = 278,
	CTFThrowable = 319,
	CTFSyringeGun = 315,
	CTFKatana = 225,
	CTFSword = 314,
	CSniperDot = 118,
	CTFSniperRifleClassic = 308,
	CTFSniperRifleDecap = 309,
	CTFSniperRifle = 307,
	CTFChargedSMG = 197,
	CTFSMG = 306,
	CTFSlap = 305,
	CTFShovel = 304,
	CTFShotgunBuildingRescue = 303,
	CTFPEPBrawlerBlaster = 241,
	CTFSodaPopper = 310,
	CTFShotgun_Revenge = 301,
	CTFScatterGun = 297,
	CTFShotgun_Pyro = 300,
	CTFShotgun_HWG = 299,
	CTFShotgun_Soldier = 302,
	CTFShotgun = 298,
	CTFRocketPack = 296,
	CTFCrossbow = 201,
	CTFRocketLauncher_Mortar = 295,
	CTFRocketLauncher_AirStrike = 293,
	CTFRocketLauncher_DirectHit = 294,
	CTFRocketLauncher = 292,
	CTFRevolver = 286,
	CTFDRGPomson = 202,
	CTFRaygun = 284,
	CTFPistol_ScoutSecondary = 246,
	CTFPistol_ScoutPrimary = 245,
	CTFPistol_Scout = 244,
	CTFPistol = 243,
	CTFPipebombLauncher = 242,
	CTFWeaponPDA_Spy = 332,
	CTFWeaponPDA_Engineer_Destroy = 331,
	CTFWeaponPDA_Engineer_Build = 330,
	CTFWeaponPDAExpansion_Teleporter = 334,
	CTFWeaponPDAExpansion_Dispenser = 333,
	CTFWeaponPDA = 329,
	CTFParticleCannon = 239,
	CTFParachute_Secondary = 238,
	CTFParachute_Primary = 237,
	CTFParachute = 236,
	CTFMinigun = 234,
	CTFMedigunShield = 231,
	CWeaponMedigun = 352,
	CTFProjectile_MechanicalArmOrb = 263,
	CTFMechanicalArm = 230,
	CTFLunchBox_Drink = 229,
	CTFLunchBox = 228,
	CLaserDot = 78,
	CTFLaserPointer = 227,
	CTFKnife = 226,
	CTFGasManager = 212,
	CTFProjectile_JarGas = 261,
	CTFJarGas = 223,
	CTFProjectile_Cleaver = 254,
	CTFProjectile_JarMilk = 262,
	CTFProjectile_Jar = 260,
	CTFCleaver = 198,
	CTFJarMilk = 224,
	CTFJar = 222,
	CTFWeaponInvis = 328,
	CTFCannon = 196,
	CTFGrenadeLauncher = 216,
	CTFGrenadePipebombProjectile = 217,
	CTFGrapplingHook = 215,
	CTFFlareGun_Revenge = 210,
	CTFFlareGun = 209,
	CTFFlameRocket = 207,
	CTFFlameThrower = 208,
	CTFFists = 205,
	CTFFireAxe = 204,
	CTFWeaponFlameBall = 327,
	CTFCompoundBow = 200,
	CTFClub = 199,
	CTFBuffItem = 195,
	CTFStickBomb = 312,
	CTFBreakableSign = 194,
	CTFBottle = 192,
	CTFBreakableMelee = 193,
	CTFBonesaw = 190,
	CTFBall_Ornament = 182,
	CTFStunBall = 313,
	CTFBat_Giftwrap = 188,
	CTFBat_Wood = 189,
	CTFBat_Fish = 187,
	CTFBat = 186,
	CTFProjectile_EnergyRing = 256,
	CTFDroppedWeapon = 203,
	CTFWeaponSapper = 335,
	CTFWeaponBuilder = 326,
	C_TFWeaponBuilder = 0,
	CTFProjectile_Rocket = 264,
	CTFProjectile_Flare = 257,
	CTFProjectile_EnergyBall = 255,
	CTFProjectile_GrapplingHook = 258,
	CTFProjectile_HealingBolt = 259,
	CTFProjectile_Arrow = 252,
	CMannVsMachineStats = 80,
	CTFTankBoss = 316,
	CTFBaseBoss = 183,
	CBossAlpha = 0,
	NextBotCombatCharacter = 357,
	CTFProjectile_SpellKartBats = 268,
	CTFProjectile_SpellKartOrb = 269,
	CTFHellZap = 220,
	CTFProjectile_SpellLightningOrb = 270,
	CTFProjectile_SpellTransposeTeleport = 277,
	CTFProjectile_SpellMeteorShower = 271,
	CTFProjectile_SpellSpawnBoss = 274,
	CTFProjectile_SpellMirv = 272,
	CTFProjectile_SpellPumpkin = 273,
	CTFProjectile_SpellSpawnHorde = 275,
	CTFProjectile_SpellSpawnZombie = 276,
	CTFProjectile_SpellBats = 266,
	CTFProjectile_SpellFireball = 267,
	CTFSpellBook = 311,
	CHightower_TeleportVortex = 74,
	CTeleportVortex = 160,
	CZombie = 354,
	CMerasmusDancer = 83,
	CMerasmus = 82,
	CHeadlessHatman = 73,
	CEyeballBoss = 48,
	CTFBotHintEngineerNest = 191,
	CBotNPCMinion = 0,
	CBotNPC = 0,
	CPasstimeGun = 94,
	CTFViewModel = 320,
	CRobotDispenser = 112,
	CTFRobotDestruction_Robot = 288,
	CTFReviveMarker = 285,
	CTFPumpkinBomb = 282,
	CTFProjectile_BallOfFire = 253,
	CTFBaseProjectile = 184,
	CTFPointManager = 250,
	CBaseObjectUpgrade = 11,
	CTFRobotDestructionLogic = 291,
	CTFRobotDestruction_RobotGroup = 289,
	CTFRobotDestruction_RobotSpawn = 290,
	CTFPlayerDestructionLogic = 248,
	CPlayerDestructionDispenser = 101,
	CTFMinigameLogic = 233,
	CTFHalloweenMinigame_FallingPlatforms = 219,
	CTFHalloweenMinigame = 218,
	CTFMiniGame = 232,
	CTFPowerupBottle = 251,
	CTFItem = 221,
	CHalloweenSoulPack = 71,
	CTFGenericBomb = 213,
	CBonusRoundLogic = 23,
	CTFGameRulesProxy = 211,
	CTETFParticleEffect = 179,
	CTETFExplosion = 178,
	CTETFBlood = 177,
	CTFFlameManager = 206,
	CHalloweenGiftPickup = 69,
	CBonusDuckPickup = 21,
	CHalloweenPickup = 70,
	CCaptureFlagReturnIcon = 27,
	CCaptureFlag = 26,
	CBonusPack = 22,
	CTFTeam = 318,
	CTFTauntProp = 317,
	CTFPlayerResource = 249,
	CTFPlayer = 247,
	CTFRagdoll = 283,
	CTEPlayerAnimEvent = 165,
	CTFPasstimeLogic = 240,
	CPasstimeBall = 93,
	CTFObjectiveResource = 235,
	CTFGlow = 214,
	CTEFireBullets = 152,
	CTFBuffBanner = 0,
	CTFAmmoPack = 181,
	CObjectTeleporter = 89,
	CObjectSentrygun = 88,
	CTFProjectile_SentryRocket = 265,
	CObjectSapper = 87,
	CObjectCartDispenser = 85,
	CObjectDispenser = 86,
	CMonsterResource = 84,
	CFuncRespawnRoomVisualizer = 64,
	CFuncRespawnRoom = 63,
	CFuncPasstimeGoal = 61,
	CFuncForceField = 57,
	CCaptureZone = 28,
	CCurrencyPack = 31,
	CBaseObject = 10,
	CTestTraceline = 176,
	CTEWorldDecal = 180,
	CTESpriteSpray = 174,
	CTESprite = 173,
	CTESparks = 172,
	CTESmoke = 171,
	CTEShowLine = 169,
	CTEProjectedDecal = 167,
	CTEPlayerDecal = 166,
	CTEPhysicsProp = 164,
	CTEParticleSystem = 163,
	CTEMuzzleFlash = 162,
	CTELargeFunnel = 159,
	CTEKillPlayerAttachments = 158,
	CTEImpact = 157,
	CTEGlowSprite = 156,
	CTEShatterSurface = 168,
	CTEFootprintDecal = 154,
	CTEFizz = 153,
	CTEExplosion = 151,
	CTEEnergySplash = 150,
	CTEEffectDispatch = 149,
	CTEDynamicLight = 148,
	CTEDecal = 146,
	CTEClientProjectile = 145,
	CTEBubbleTrail = 144,
	CTEBubbles = 143,
	CTEBSPDecal = 142,
	CTEBreakModel = 141,
	CTEBloodStream = 140,
	CTEBloodSprite = 139,
	CTEBeamSpline = 138,
	CTEBeamRingPoint = 137,
	CTEBeamRing = 136,
	CTEBeamPoints = 135,
	CTEBeamLaser = 134,
	CTEBeamFollow = 133,
	CTEBeamEnts = 132,
	CTEBeamEntPoint = 131,
	CTEBaseBeam = 130,
	CTEArmorRicochet = 129,
	CTEMetalSparks = 161,
	CSteamJet = 123,
	CSmokeStack = 117,
	DustTrail = 355,
	CFireTrail = 50,
	SporeTrail = 362,
	SporeExplosion = 361,
	RocketTrail = 359,
	SmokeTrail = 360,
	CPropVehicleDriveable = 108,
	ParticleSmokeGrenade = 358,
	CParticleFire = 90,
	MovieExplosion = 356,
	CTEGaussExplosion = 155,
	CEnvQuadraticBeam = 43,
	CEmbers = 36,
	CEnvWind = 47,
	CPrecipitation = 107,
	CBaseTempEntity = 17,
	CWeaponIFMSteadyCam = 351,
	CWeaponIFMBaseCamera = 350,
	CWeaponIFMBase = 349,
	CTFWearableVM = 343,
	CTFWearable = 336,
	CTFWearableItem = 339,
	CEconWearable = 35,
	CBaseAttributableItem = 3,
	CEconEntity = 34,
	CHandleTest = 72,
	CTeamplayRoundBasedRulesProxy = 126,
	CTeamRoundTimer = 127,
	CSpriteTrail = 122,
	CSpriteOriented = 121,
	CSprite = 120,
	CRagdollPropAttached = 111,
	CRagdollProp = 110,
	CPoseController = 106,
	CGameRulesProxy = 68,
	CInfoLadderDismount = 75,
	CFuncLadder = 58,
	CEnvDetailController = 40,
	CWorld = 353,
	CWaterLODControl = 348,
	CWaterBullet = 347,
	CVoteController = 346,
	CVGuiScreen = 345,
	CPropJeep = 0,
	CPropVehicleChoreoGeneric = 0,
	CTest_ProxyToggle_Networkable = 175,
	CTesla = 170,
	CTeamTrainWatcher = 128,
	CBaseTeamObjectiveResource = 16,
	CTeam = 125,
	CSun = 124,
	CParticlePerformanceMonitor = 91,
	CSpotlightEnd = 119,
	CSlideshowDisplay = 116,
	CShadowControl = 115,
	CSceneEntity = 114,
	CRopeKeyframe = 113,
	CRagdollManager = 109,
	CPhysicsPropMultiplayer = 98,
	CPhysBoxMultiplayer = 96,
	CBasePropDoor = 15,
	CDynamicProp = 33,
	CPointWorldText = 105,
	CPointCommentaryNode = 104,
	CPointCamera = 103,
	CPlayerResource = 102,
	CPlasma = 100,
	CPhysMagnet = 99,
	CPhysicsProp = 97,
	CPhysBox = 95,
	CParticleSystem = 92,
	CMaterialModifyControl = 81,
	CLightGlow = 79,
	CInfoOverlayAccessor = 77,
	CFuncTrackTrain = 67,
	CFuncSmokeVolume = 66,
	CFuncRotating = 65,
	CFuncReflectiveGlass = 62,
	CFuncOccluder = 60,
	CFuncMonitor = 59,
	CFunc_LOD = 54,
	CTEDust = 147,
	CFunc_Dust = 53,
	CFuncConveyor = 56,
	CBreakableSurface = 25,
	CFuncAreaPortalWindow = 55,
	CFish = 51,
	CEntityFlame = 38,
	CFireSmoke = 49,
	CEnvTonemapController = 46,
	CEnvScreenEffect = 44,
	CEnvScreenOverlay = 45,
	CEnvProjectedTexture = 42,
	CEnvParticleScript = 41,
	CFogController = 52,
	CEntityParticleTrail = 39,
	CEntityDissolve = 37,
	CDynamicLight = 32,
	CColorCorrectionVolume = 30,
	CColorCorrection = 29,
	CBreakableProp = 24,
	CBasePlayer = 13,
	CBaseFlex = 8,
	CBaseEntity = 7,
	CBaseDoor = 6,
	CBaseCombatCharacter = 4,
	CBaseAnimatingOverlay = 2,
	CBoneFollower = 20,
	CBaseAnimating = 1,
	CInfoLightingRelative = 76,
	CAI_BaseNPC = 0,
	CBeam = 19,
	CBaseViewModel = 18,
	CBaseProjectile = 14,
	CBaseParticleEntity = 12,
	CBaseGrenade = 9,
	CBaseCombatWeapon = 5,
};

enum ETFGrenadeProjectileType
{
	TYPE_PIPE,
	TYPE_STICKY
};

enum EPlayerControls
{
	IN_ATTACK                      = (1 << 0),
	IN_JUMP                        = (1 << 1),
	IN_DUCK                        = (1 << 2),
	IN_FORWARD                     = (1 << 3),
	IN_BACK                        = (1 << 4),
	IN_USE                         = (1 << 5),
	IN_CANCEL                      = (1 << 6),
	IN_LEFT                        = (1 << 7),
	IN_RIGHT                       = (1 << 8),
	IN_MOVELEFT                    = (1 << 9),
	IN_MOVERIGHT                   = (1 << 10),
	IN_ATTACK2                     = (1 << 11),
	IN_RUN                         = (1 << 12),
	IN_RELOAD                      = (1 << 13),
	IN_AL1                         = (1 << 14),
	IN_ALT2                        = (1 << 15),
	IN_SCORE                       = (1 << 16),
	IN_SPEED                       = (1 << 17),
	IN_WALK                        = (1 << 18),
	IN_ZOOM                        = (1 << 19),
	IN_WEAPON1                     = (1 << 20),
	IN_WEAPON2                     = (1 << 21),
	IN_BULLRUSH                    = (1 << 22),
	IN_GRENADE1                    = (1 << 23),
	IN_GRENADE2                    = (1 << 24),
	IN_ATTACK3                     = (1 << 25),
};

enum ETFCond
{
	TF_COND_INVALID = -1,
	TF_COND_AIMING,
	TF_COND_ZOOMED,
	TF_COND_DISGUISING,
	TF_COND_DISGUISED,
	TF_COND_STEALTHED,
	TF_COND_INVULNERABLE,
	TF_COND_TELEPORTED,
	TF_COND_TAUNTING,
	TF_COND_INVULNERABLE_WEARINGOFF,
	TF_COND_STEALTHED_BLINK,
	TF_COND_SELECTED_TO_TELEPORT,
	TF_COND_CRITBOOSTED,
	TF_COND_TMPDAMAGEBONUS,
	TF_COND_FEIGN_DEATH,
	TF_COND_PHASE,
	TF_COND_STUNNED,
	TF_COND_OFFENSEBUFF,
	TF_COND_SHIELD_CHARGE,
	TF_COND_DEMO_BUFF,
	TF_COND_ENERGY_BUFF,
	TF_COND_RADIUSHEAL,
	TF_COND_HEALTH_BUFF,
	TF_COND_BURNING,
	TF_COND_HEALTH_OVERHEALED,
	TF_COND_URINE,
	TF_COND_BLEEDING,
	TF_COND_DEFENSEBUFF,
	TF_COND_MAD_MILK,
	TF_COND_MEGAHEAL,
	TF_COND_REGENONDAMAGEBUFF,
	TF_COND_MARKEDFORDEATH,
	TF_COND_NOHEALINGDAMAGEBUFF,
	TF_COND_SPEED_BOOST,
	TF_COND_CRITBOOSTED_PUMPKIN,
	TF_COND_CRITBOOSTED_USER_BUFF,
	TF_COND_CRITBOOSTED_DEMO_CHARGE,
	TF_COND_SODAPOPPER_HYPE,
	TF_COND_CRITBOOSTED_FIRST_BLOOD,
	TF_COND_CRITBOOSTED_BONUS_TIME,
	TF_COND_CRITBOOSTED_CTF_CAPTURE,
	TF_COND_CRITBOOSTED_ON_KILL,
	TF_COND_CANNOT_SWITCH_FROM_MELEE,
	TF_COND_DEFENSEBUFF_NO_CRIT_BLOCK,
	TF_COND_REPROGRAMMED,
	TF_COND_CRITBOOSTED_RAGE_BUFF,
	TF_COND_DEFENSEBUFF_HIGH,
	TF_COND_SNIPERCHARGE_RAGE_BUFF,
	TF_COND_DISGUISE_WEARINGOFF,
	TF_COND_MARKEDFORDEATH_SILENT,
	TF_COND_DISGUISED_AS_DISPENSER,
	TF_COND_SAPPED,
	TF_COND_INVULNERABLE_HIDE_UNLESS_DAMAGED,
	TF_COND_INVULNERABLE_USER_BUFF,
	TF_COND_HALLOWEEN_BOMB_HEAD,
	TF_COND_HALLOWEEN_THRILLER,
	TF_COND_RADIUSHEAL_ON_DAMAGE,
	TF_COND_CRITBOOSTED_CARD_EFFECT,
	TF_COND_INVULNERABLE_CARD_EFFECT,
	TF_COND_MEDIGUN_UBER_BULLET_RESIST,
	TF_COND_MEDIGUN_UBER_BLAST_RESIST,
	TF_COND_MEDIGUN_UBER_FIRE_RESIST,
	TF_COND_MEDIGUN_SMALL_BULLET_RESIST,
	TF_COND_MEDIGUN_SMALL_BLAST_RESIST,
	TF_COND_MEDIGUN_SMALL_FIRE_RESIST,
	TF_COND_STEALTHED_USER_BUFF,
	TF_COND_MEDIGUN_DEBUFF,
	TF_COND_STEALTHED_USER_BUFF_FADING,
	TF_COND_BULLET_IMMUNE,
	TF_COND_BLAST_IMMUNE,
	TF_COND_FIRE_IMMUNE,
	TF_COND_PREVENT_DEATH,
	TF_COND_MVM_BOT_STUN_RADIOWAVE,
	TF_COND_HALLOWEEN_SPEED_BOOST,
	TF_COND_HALLOWEEN_QUICK_HEAL,
	TF_COND_HALLOWEEN_GIANT,
	TF_COND_HALLOWEEN_TINY,
	TF_COND_HALLOWEEN_IN_HELL,
	TF_COND_HALLOWEEN_GHOST_MODE,
	TF_COND_MINICRITBOOSTED_ON_KILL,
	TF_COND_OBSCURED_SMOKE,
	TF_COND_PARACHUTE_ACTIVE,
	TF_COND_BLASTJUMPING,
	TF_COND_HALLOWEEN_KART,
	TF_COND_HALLOWEEN_KART_DASH,
	TF_COND_BALLOON_HEAD,
	TF_COND_MELEE_ONLY,
	TF_COND_SWIMMING_CURSE,
	TF_COND_FREEZE_INPUT,
	TF_COND_HALLOWEEN_KART_CAGE,
	TF_COND_HASRUNE, //TF_COND_DONOTUSE_0
	TF_COND_RUNE_STRENGTH,
	TF_COND_RUNE_HASTE,
	TF_COND_RUNE_REGEN,
	TF_COND_RUNE_RESIST,
	TF_COND_RUNE_VAMPIRE,
	TF_COND_RUNE_REFLECT,
	TF_COND_RUNE_PRECISION,
	TF_COND_RUNE_AGILITY,
	TF_COND_GRAPPLINGHOOK,
	TF_COND_GRAPPLINGHOOK_SAFEFALL,
	TF_COND_GRAPPLINGHOOK_LATCHED,
	TF_COND_GRAPPLINGHOOK_BLEEDING,
	TF_COND_AFTERBURN_IMMUNE,
	TF_COND_RUNE_KNOCKOUT,
	TF_COND_RUNE_IMBALANCE,
	TF_COND_CRITBOOSTED_RUNE_TEMP,
	TF_COND_PASSTIME_INTERCEPTION,
	TF_COND_SWIMMING_NO_EFFECTS,
	TF_COND_PURGATORY,
	TF_COND_RUNE_KING,
	TF_COND_RUNE_PLAGUE,
	TF_COND_RUNE_SUPERNOVA,
	TF_COND_PLAGUE,
	TF_COND_KING_BUFFED,
	TF_COND_TEAM_GLOWS,
	TF_COND_KNOCKED_INTO_AIR,
	TF_COND_COMPETITIVE_WINNER,
	TF_COND_COMPETITIVE_LOSER,
	TF_COND_HEALING_DEBUFF,
	TF_COND_PASSTIME_PENALTY_DEBUFF,
	TF_COND_GRAPPLED_TO_PLAYER,
	TF_COND_GRAPPLED_BY_PLAYER,
	TF_COND_PARACHUTE_DEPLOYED,
	TF_COND_GAS,
	TF_COND_BURNING_PYRO,
	TF_COND_ROCKETPACK,
	TF_COND_LOST_FOOTING,
	TF_COND_AIR_CURRENT,
	TF_COND_HALLOWEEN_HELL_HEAL,
	TF_COND_POWERUPMODE_DOMINANT
};

enum ETFConds
{
	TFCond_Slowed					= (1 << 0), // 0
	TFCond_Zoomed					= (1 << 1), // 1
	TFCond_Disguising				= (1 << 2), // 2
	TFCond_Disguised				= (1 << 3), // 3
	TFCond_Cloaked					= (1 << 4), // 4
	TFCond_Ubercharged				= (1 << 5), // 5
	TFCond_TeleportedGlow			= (1 << 6), // 6
	TFCond_Taunting					= (1 << 7), // 7
	TFCond_UberchargeFading			= (1 << 8), // 8
	TFCond_CloakFlicker				= (1 << 9), // 9
	TFCond_Teleporting				= (1 << 10), // 10
	TFCond_Kritzkrieged				= (1 << 11), // 11
	TFCond_TmpDamageBonus			= (1 << 12), // 12
	TFCond_DeadRingered				= (1 << 13), // 13
	TFCond_Bonked					= (1 << 14), // 14
	TFCond_Stunned					= (1 << 15), // 15
	TFCond_Buffed					= (1 << 16), // 16
	TFCond_Charging					= (1 << 17), // 17
	TFCond_DemoBuff					= (1 << 18), // 18
	TFCond_CritCola					= (1 << 19), // 19
	TFCond_InHealRadius				= (1 << 20), // 20
	TFCond_Healing					= (1 << 21), // 21
	TFCond_OnFire					= (1 << 22), // 22
	TFCond_Overhealed				= (1 << 23), // 23
	TFCond_Jarated					= (1 << 24), // 24
	TFCond_Bleeding					= (1 << 25), // 25
	TFCond_DefenseBuffed			= (1 << 26), // 26
	TFCond_Milked					= (1 << 27), // 27
	TFCond_MegaHeal					= (1 << 28), // 28
	TFCond_RegenBuffed				= (1 << 29), // 29
	TFCond_MarkedForDeath			= (1 << 30), // 30
	TFCond_NoHealingDamageBuff		= (1 << 31), // 31

	TFCondEx_SpeedBuffAlly			= (1 << 0), // 32
	TFCondEx_HalloweenCritCandy		= (1 << 1), // 33
	TFCondEx_CritCanteen			= (1 << 2), // 34
	TFCondEx_CritDemoCharge			= (1 << 3), // 35
	TFCondEx_CritHype				= (1 << 4), // 36
	TFCondEx_CritOnFirstBlood		= (1 << 5), // 37
	TFCondEx_CritOnWin				= (1 << 6), // 38
	TFCondEx_CritOnFlagCapture		= (1 << 7), // 39
	TFCondEx_CritOnKill				= (1 << 8), // 40
	TFCondEx_RestrictToMelee		= (1 << 9), // 41
	TFCondEx_DefenseBuffNoCritBlock	= (1 << 10), // 42
	TFCondEx_Reprogrammed			= (1 << 11), // 43
	TFCondEx_PyroCrits				= (1 << 12), // 44
	TFCondEx_PyroHeal				= (1 << 13), // 45
	TFCondEx_FocusBuff				= (1 << 14), // 46
	TFCondEx_DisguisedRemoved		= (1 << 15), // 47
	TFCondEx_MarkedForDeathSilent	= (1 << 16), // 48
	TFCondEx_DisguisedAsDispenser	= (1 << 17), // 49
	TFCondEx_InKart					= (1 << 18), // 50
	TFCondEx_UberchargedHidden		= (1 << 19), // 51
	TFCondEx_UberchargedCanteen		= (1 << 20), // 52
	TFCondEx_HalloweenBombHead		= (1 << 21), // 53
	TFCondEx_HalloweenThriller		= (1 << 22), // 54
	TFCondEx_BulletCharge			= (1 << 26), // 58
	TFCondEx_ExplosiveCharge		= (1 << 27), // 59
	TFCondEx_FireCharge				= (1 << 28), // 60
	TFCondEx_BulletResistance		= (1 << 29), // 61
	TFCondEx_ExplosiveResistance	= (1 << 30), // 62
	TFCondEx_FireResistance			= (1 << 31), // 63
	TFCondEx_PhlogUber				= 1052672,

	TFCondEx2_Stealthed				= (1 << 0), // 64
	TFCondEx2_MedigunDebuff			= (1 << 1), // 65
	TFCondEx2_StealthedUserBuffFade	= (1 << 2), // 66
	TFCondEx2_BulletImmune			= (1 << 3), // 67
	TFCondEx2_BlastImmune			= (1 << 4), // 68
	TFCondEx2_FireImmune			= (1 << 5), // 69
	TFCondEx2_PreventDeath			= (1 << 6), // 70
	TFCondEx2_MVMBotRadiowave		= (1 << 7), // 71
	TFCondEx2_HalloweenSpeedBoost	= (1 << 8), // 72
	TFCondEx2_HalloweenQuickHeal	= (1 << 9), // 73
	TFCondEx2_HalloweenGiant		= (1 << 10), // 74
	TFCondEx2_HalloweenTiny			= (1 << 11), // 75
	TFCondEx2_HalloweenInHell		= (1 << 12), // 76
	TFCondEx2_HalloweenGhostMode	= (1 << 13), // 77
	TFCondEx2_Parachute				= (1 << 16), // 80
	TFCondEx2_BlastJumping			= (1 << 17), // 81
	TFCondEx2_StrengthRune			= (1 << 26), // 90
	TFCondEx2_HasteRune				= (1 << 27), // 91
	TFCondEx2_RegenRune				= (1 << 28), // 92
	TFCondEx2_ResistRune			= (1 << 29), // 93
	TFCondEx2_VampireRune			= (1 << 30), // 94
	TFCondEx2_ReflectRune			= (1 << 31), // 95
	
	TFCondEx3_PrecisionRune			= (1 << 0), // 96
	TFCondEx3_AgilityRune			= (1 << 1), // 97
	TFCondEx3_KnockoutRune			= (1 << 7), // 103
	TFCondEx3_ImbalanceRune			= (1 << 8), // 104
	TFCondEx3_CritboostedTempRune	= (1 << 9), // 105
	TFCondEx3_KingRune				= (1 << 13), // 109
	TFCondEx3_PlagueRune			= (1 << 14), // 110
	TFCondEx3_SupernovaRune			= (1 << 15), // 111
	TFCondEx3_KingBuff				= (1 << 17), // 113
	//TFCondEx3_RuneDebuff			= (1 << 129),	// I don't know how to get this one :c

	TFCond_IgnoreStates            = (TFCond_Ubercharged | TFCond_Bonked),
	TFCondEx_IgnoreStates          = (TFCondEx_PyroHeal),
	TFCondEx_Criticals = (TFCondEx_CritCanteen | TFCondEx_CritOnFirstBlood | TFCondEx_CritOnWin | TFCondEx_CritOnKill |
		TFCondEx_CritDemoCharge | TFCondEx_CritOnFlagCapture | TFCondEx_HalloweenCritCandy | TFCondEx_PyroCrits)
};

enum ETFMatchGroup {
	k_eTFMatchGroup_Invalid = -1,
	k_eTFMatchGroup_MvM_Practice = 0,
	k_eTFMatchGroup_MvM_MannUp = 1,
	k_eTFMatchGroup_First = 0,
	k_eTFMatchGroup_MvM_Default = 0,
	k_eTFMatchGroup_MvM_First = 0,
	k_eTFMatchGroup_MvM_Last = 1,
	k_eTFMatchGroup_Ladder_6v6 = 2,
	k_eTFMatchGroup_Ladder_9v9 = 3,
	k_eTFMatchGroup_Ladder_12v12 = 4,
	k_eTFMatchGroup_Ladder_Default = 2,
	k_eTFMatchGroup_Ladder_First = 2,
	k_eTFMatchGroup_Ladder_Last = 4,
	k_eTFMatchGroup_Casual_6v6 = 5,
	k_eTFMatchGroup_Casual_9v9 = 6,
	k_eTFMatchGroup_Casual_12v12 = 7,
	k_eTFMatchGroup_Casual_Default = 7,
	k_eTFMatchGroup_Casual_First = 5,
	k_eTFMatchGroup_Casual_Last = 7,
	k_eTFMatchGroup_Event_Placeholder = 8,
	k_eTFMatchGroup_Event_Default = 8,
	k_eTFMatchGroup_Event_First = 8,
	k_eTFMatchGroup_Event_Last = 8,
};

enum class EConVarFlags
{
	FCVAR_NONE                     = 0, // The default, no flags at all

	FCVAR_UNREGISTERED             = (1 << 0), // If this is set, don't add to linked list, etc.
	FCVAR_DEVELOPMENT_ONLY         = (1 << 1), // Hidden in released products. Flag is removed automatically if ALLOW_DEVELOPMENT_CVARS is defined.
	FCVAR_GAME_DLL                 = (1 << 2), // defined by the game DLL
	FCVAR_CLIENT_DLL               = (1 << 3), // defined by the client DLL
	FCVAR_HIDDEN                   = (1 << 4), // Hidden. Doesn't appear in find or autocomplete. Like DEVELOPMENTONLY, but can't be compiled out.

	FCVAR_PROTECTED                = (1 << 5),  // It's a server cvar, but we don't send the data since it's a password, etc.  Sends 1 if it's not bland/zero, 0 otherwise as value
	FCVAR_SP_ONLY                  = (1 << 6),  // This cvar cannot be changed by clients connected to a multiplayer server.
	FCVAR_ARCHIVE                  = (1 << 7),  // set to cause it to be saved to vars.rc
	FCVAR_NOTIFY                   = (1 << 8),  // notifies players when changed
	FCVAR_USER_INFO                = (1 << 9),  // changes the client's info string
	FCVAR_CHEAT                    = (1 << 14), // Only useable in singleplayer / debug / multiplayer & sv_cheats

	FCVAR_PRINTABLE_ONLY           = (1 << 10), // This cvar's string cannot contain unprintable characters ( e.g., used for player name etc ).
	FCVAR_UN_LOGGED                = (1 << 11), // If this is a FCVAR_SERVER, don't log changes to the log file / console if we are creating a log
	FCVAR_NEVER_AS_STRING          = (1 << 12), // never try to print that cvar

	FCVAR_REPLICATED               = (1 << 13), // server setting enforced on clients, TODO rename to FCAR_SERVER at some time
	FCVAR_DEMO                     = (1 << 16), // record this cvar when starting a demo file
	FCVAR_DONT_RECORD              = (1 << 17), // don't record these command in demofiles
	FCVAR_RELOAD_MATERIALS         = (1 << 20), // If this cvar changes, it forces a material reload
	FCVAR_RELOAD_TEXTURES          = (1 << 21), // If this cvar changes, if forces a texture reload

	FCVAR_NOT_CONNECTED            = (1 << 22), // cvar cannot be changed by a client that is connected to a server
	FCVAR_MATERIAL_SYSTEM_THREAD   = (1 << 23), // Indicates this cvar is read from the material system thread
	FCVAR_ARCHIVE_XBOX             = (1 << 24), // cvar written to config.cfg on the Xbox

	FCVAR_ACCESSIBLE_FROM_THREADS  = (1 << 25), // used as a debugging tool necessary to check material system thread convars

	FCVAR_SERVER_CAN_EXECUTE       = (1 << 28), // the server is allowed to execute this command on clients via ClientCommand/NET_StringCmd/CBaseClientState::ProcessStringCmd.
	FCVAR_SERVER_CANNOT_QUERY      = (1 << 29), // If this is set, then the server is not allowed to query this cvar's value (via IServerPluginHelpers::StartQueryCvarValue).
	FCVAR_CLIENT_CMD_CAN_EXECUTE   = (1 << 30), // IVEngineClient::ClientCmd is allowed to execute this command.

	FCVAR_MATERIAL_THREAD_MASK     = (FCVAR_RELOAD_MATERIALS | FCVAR_RELOAD_TEXTURES | FCVAR_MATERIAL_SYSTEM_THREAD)
};

enum class EBuildingType
{
	DISPENSER,
	TELEPORTER,
	SENTRY
};

enum ERenderGroup
{
	RENDER_GROUP_OPAQUE_STATIC_HUGE = 0,		// Huge static prop
	RENDER_GROUP_OPAQUE_ENTITY_HUGE = 1,		// Huge opaque entity
	RENDER_GROUP_OPAQUE_STATIC = RENDER_GROUP_OPAQUE_STATIC_HUGE + (4 - 1) * 2, //RENDER_GROUP_CFG_NUM_OPAQUE_ENT_BUCKETS = 4
	RENDER_GROUP_OPAQUE_ENTITY,					// Opaque entity (smallest size, or default)

	RENDER_GROUP_TRANSLUCENT_ENTITY,
	RENDER_GROUP_TWOPASS,						// Implied opaque and translucent in two passes
	RENDER_GROUP_VIEW_MODEL_OPAQUE,				// Solid weapon view models
	RENDER_GROUP_VIEW_MODEL_TRANSLUCENT,		// Transparent overlays etc

	RENDER_GROUP_OPAQUE_BRUSH,					// Brushes

	RENDER_GROUP_OTHER,							// Unclassfied. Won't get drawn.

	// This one's always gotta be last
	RENDER_GROUP_COUNT
};

enum EFontFlags
{
	FONTFLAG_NONE			= 0x000,
	FONTFLAG_ITALIC			= 0x001,
	FONTFLAG_UNDERLINE		= 0x002,
	FONTFLAG_STRIKEOUT		= 0x004,
	FONTFLAG_SYMBOL			= 0x008,
	FONTFLAG_ANTIALIAS		= 0x010,
	FONTFLAG_GAUSSIAN		= 0x020,
	FONTFLAG_ROTARY			= 0x040,
	FONTFLAG_DROPSHADOW		= 0x080,
	FONTFLAG_ADDITIVE		= 0x100,
	FONTFLAG_OUTLINE		= 0x200,
	FONTFLAG_CUSTOM			= 0x400
};

enum EVGuiPanel
{
	PANEL_ROOT = 0,
	PANEL_GAMEUIDLL,
	PANEL_CLIENTDLL,
	PANEL_TOOLS,
	PANEL_INGAMESCREENS,
	PANEL_GAMEDLL,
	PANEL_CLIENTDLL_TOOLS
};

enum EPaintMode
{
	PAINT_UIPANELS = (1 << 0),
	PAINT_INGAMEPANELS = (1 << 1),
	PAINT_CURSOR = (1 << 2)
};

#define ppp false
enum ETFWeaponType
{
	TF_WEAPON_NONE,// = 0,
	TF_WEAPON_BAT,
	TF_WEAPON_BAT_WOOD,
	TF_WEAPON_BOTTLE,
	TF_WEAPON_FIREAXE,
	TF_WEAPON_CLUB,
	TF_WEAPON_CROWBAR,
	TF_WEAPON_KNIFE,
	TF_WEAPON_FISTS,
	TF_WEAPON_SHOVEL,
	TF_WEAPON_WRENCH,
	TF_WEAPON_BONESAW,
	TF_WEAPON_SHOTGUN_PRIMARY,
	TF_WEAPON_SHOTGUN_SOLDIER,
	TF_WEAPON_SHOTGUN_HWG,
	TF_WEAPON_SHOTGUN_PYRO,
	TF_WEAPON_SCATTERGUN,
	TF_WEAPON_SNIPERRIFLE,
	TF_WEAPON_MINIGUN,
	TF_WEAPON_SMG,
	TF_WEAPON_SYRINGEGUN_MEDIC,
	TF_WEAPON_TRANQ,
	TF_WEAPON_ROCKETLAUNCHER,
	TF_WEAPON_GRENADELAUNCHER,
	TF_WEAPON_PIPEBOMBLAUNCHER,
	TF_WEAPON_FLAMETHROWER,
	TF_WEAPON_GRENADE_NORMAL,
	TF_WEAPON_GRENADE_CONCUSSION,
	TF_WEAPON_GRENADE_NAIL,
	TF_WEAPON_GRENADE_MIRV,
	TF_WEAPON_GRENADE_MIRV_DEMOMAN,
	TF_WEAPON_GRENADE_NAPALM,
	TF_WEAPON_GRENADE_GAS,
	TF_WEAPON_GRENADE_EMP,
	TF_WEAPON_GRENADE_CALTROP,
	TF_WEAPON_GRENADE_PIPEBOMB,
	TF_WEAPON_GRENADE_SMOKE_BOMB,
	TF_WEAPON_GRENADE_HEAL,
	TF_WEAPON_GRENADE_STUNBALL,
	TF_WEAPON_GRENADE_JAR,
	TF_WEAPON_GRENADE_JAR_MILK,
	TF_WEAPON_PISTOL,
	TF_WEAPON_PISTOL_SCOUT,
	TF_WEAPON_REVOLVER,
	TF_WEAPON_NAILGUN,
	TF_WEAPON_PDA,
	TF_WEAPON_PDA_ENGINEER_BUILD,
	TF_WEAPON_PDA_ENGINEER_DESTROY,
	TF_WEAPON_PDA_SPY,
	TF_WEAPON_BUILDER,
	TF_WEAPON_MEDIGUN,
	TF_WEAPON_GRENADE_MIRVBOMB,
	TF_WEAPON_FLAMETHROWER_ROCKET,
	TF_WEAPON_GRENADE_DEMOMAN,
	TF_WEAPON_SENTRY_BULLET,
	TF_WEAPON_SENTRY_ROCKET,
	TF_WEAPON_DISPENSER,
	TF_WEAPON_INVIS,
	TF_WEAPON_FLAREGUN,
	TF_WEAPON_LUNCHBOX,
	TF_WEAPON_JAR,
	TF_WEAPON_COMPOUND_BOW,
	TF_WEAPON_BUFF_ITEM,
	TF_WEAPON_PUMPKIN_BOMB,
	TF_WEAPON_SWORD,
#if ppp
	TF_WEAPON_ROCKETLAUNCHER_DIRECTHIT,
#else
	TF_WEAPON_ROCKETLAUNCHER_DIRECTHIT,
#endif
	TF_WEAPON_LIFELINE,
	TF_WEAPON_LASER_POINTER,
	TF_WEAPON_DISPENSER_GUN,
	TF_WEAPON_SENTRY_REVENGE,
	TF_WEAPON_JAR_MILK,
	TF_WEAPON_HANDGUN_SCOUT_PRIMARY,
	TF_WEAPON_BAT_FISH,
	TF_WEAPON_CROSSBOW,
	TF_WEAPON_STICKBOMB,
#if ppp
	TF_WEAPON_HANDGUN_SCOUT_SECONDARY,
#else
	TF_WEAPON_HANDGUN_SCOUT_SEC,
#endif
	TF_WEAPON_SODA_POPPER,
	TF_WEAPON_SNIPERRIFLE_DECAP,
	TF_WEAPON_RAYGUN,
	TF_WEAPON_PARTICLE_CANNON,
	TF_WEAPON_MECHANICAL_ARM,
	TF_WEAPON_DRG_POMSON,
	TF_WEAPON_BAT_GIFTWRAP,
#if ppp
	TF_WEAPON_GRENADE_ORNAMENT_BALL,
	TF_WEAPON_FLAREGUN_REVENGE,
#else
	TF_WEAPON_GRENADE_ORNAMENT,
	TF_WEAPON_RAYGUN_REVENGE,
#endif
	TF_WEAPON_PEP_BRAWLER_BLASTER,
	TF_WEAPON_CLEAVER,
	TF_WEAPON_GRENADE_CLEAVER,
	TF_WEAPON_STICKY_BALL_LAUNCHER,
	TF_WEAPON_GRENADE_STICKY_BALL,
	TF_WEAPON_SHOTGUN_BUILDING_RESCUE,
	TF_WEAPON_CANNON,
	TF_WEAPON_THROWABLE,
	TF_WEAPON_GRENADE_THROWABLE,
	TF_WEAPON_PDA_SPY_BUILD,
	TF_WEAPON_GRENADE_WATERBALLOON,
	TF_WEAPON_HARVESTER_SAW,
	TF_WEAPON_SPELLBOOK,
	TF_WEAPON_SPELLBOOK_PROJECTILE,
	TF_WEAPON_SNIPERRIFLE_CLASSIC,
	TF_WEAPON_PARACHUTE,
	TF_WEAPON_GRAPPLINGHOOK,
	TF_WEAPON_PASSTIME_GUN,
	TF_WEAPON_CHARGED_SMG,
#if ppp
	TF_WEAPON_COUNT
#else
	TF_WEAPON_BREAKABLE_SIGN,
	TF_WEAPON_ROCKETPACK,
	TF_WEAPON_SLAP,
	TF_WEAPON_JAR_GAS,
	TF_WEAPON_GRENADE_JAR_GAS,
	TF_WEAPON_FLAME_BALL
#endif
};

enum ETFProjectileType {
	TF_PROJECTILE_NONE,
	TF_PROJECTILE_BULLET,
	TF_PROJECTILE_ROCKET,
	TF_PROJECTILE_PIPEBOMB,
	TF_PROJECTILE_PIPEBOMB_REMOTE,
	TF_PROJECTILE_SYRINGE,
	TF_PROJECTILE_FLARE,
	TF_PROJECTILE_JAR,
	TF_PROJECTILE_ARROW,
	TF_PROJECTILE_FLAME_ROCKET,
	TF_PROJECTILE_JAR_MILK,
	TF_PROJECTILE_HEALING_BOLT,
	TF_PROJECTILE_ENERGY_BALL,
	TF_PROJECTILE_ENERGY_RING,
	TF_PROJECTILE_PIPEBOMB_PRACTICE,
	TF_PROJECTILE_CLEAVER,
	TF_PROJECTILE_STICKY_BALL,
	TF_PROJECTILE_CANNONBALL,
	TF_PROJECTILE_BUILDING_REPAIR_BOLT,
	TF_PROJECTILE_FESTIVE_ARROW,
	TF_PROJECTILE_THROWABLE,
	TF_PROJECTILE_SPELL,
	TF_PROJECTILE_FESTIVE_JAR,
	TF_PROJECTILE_FESTIVE_HEALING_BOLT,
	TF_PROJECTILE_BREADMONSTER_JARATE,
	TF_PROJECTILE_BREADMONSTER_MADMILK,
	TF_PROJECTILE_GRAPPLINGHOOK,
	TF_PROJECTILE_SENTRY_ROCKET,
	TF_PROJECTILE_BREAD_MONSTER,
	TF_PROJECTILE_JAR_GAS,
	TF_PROJECTILE_BALLOFFIRE,
	TF_NUM_PROJECTILES
};

enum MedigunWeaponTypes
{
	MEDIGUN_STANDARD = 0,
	MEDIGUN_UBER,
	MEDIGUN_QUICKFIX,
	MEDIGUN_RESIST
};
enum MedigunChargeTypes
{
	MEDIGUN_CHARGE_INVALID = -1,
	MEDIGUN_CHARGE_INVULN = 0,
	MEDIGUN_CHARGE_CRITICALBOOST,
	MEDIGUN_CHARGE_MEGAHEAL,
	MEDIGUN_CHARGE_BULLET_RESIST,
	MEDIGUN_CHARGE_BLAST_RESIST,
	MEDIGUN_CHARGE_FIRE_RESIST,
	MEDIGUN_NUM_CHARGE_TYPES
};
enum MedigunResistTypes
{
	MEDIGUN_BULLET_RESIST = 0,
	MEDIGUN_BLAST_RESIST,
	MEDIGUN_FIRE_RESIST,
	MEDIGUN_NUM_RESISTS
};

enum MinigunState_t
{
	AC_STATE_IDLE = 0,
	AC_STATE_STARTFIRING,
	AC_STATE_FIRING,
	AC_STATE_SPINNING,
	AC_STATE_DRYFIRE
};

enum ETFHitboxes
{
	HITBOX_HEAD,
	HITBOX_PELVIS,
	HITBOX_SPINE_0,
	HITBOX_SPINE_1,
	HITBOX_SPINE_2,
	HITBOX_SPINE_3,
	HITBOX_UPPERARM_L,
	HITBOX_LOWERARM_L,
	HITBOX_HAND_L,
	HITBOX_UPPERARM_R,
	HITBOX_LOWERARM_R,
	HITBOX_HAND_R,
	HITBOX_HIP_L,
	HITBOX_KNEE_L,
	HITBOX_FOOT_L,
	HITBOX_HIP_R,
	HITBOX_KNEE_R,
	HITBOX_FOOT_R,
	HITBOX_MAX
};

enum ETFWeapons
{
	Scout_m_Scattergun                               = 13,
	Scout_m_ScattergunR                              = 200,
	Scout_m_ForceANature                             = 45,
	Scout_m_TheShortstop                             = 220,
	Scout_m_TheSodaPopper                            = 448,
	Scout_m_FestiveScattergun                        = 669,
	Scout_m_BabyFacesBlaster                         = 772,
	Scout_m_SilverBotkillerScattergunMkI             = 799,
	Scout_m_GoldBotkillerScattergunMkI               = 808,
	Scout_m_RustBotkillerScattergunMkI               = 888,
	Scout_m_BloodBotkillerScattergunMkI              = 897,
	Scout_m_CarbonadoBotkillerScattergunMkI          = 906,
	Scout_m_DiamondBotkillerScattergunMkI            = 915,
	Scout_m_SilverBotkillerScattergunMkII            = 964,
	Scout_m_GoldBotkillerScattergunMkII              = 973,
	Scout_m_FestiveForceANature                      = 1078,
	Scout_m_TheBackScatter                           = 1103,
	Scout_m_NightTerror                              = 15002,
	Scout_m_TartanTorpedo                            = 15015,
	Scout_m_CountryCrusher                           = 15021,
	Scout_m_BackcountryBlaster                       = 15029,
	Scout_m_SpruceDeuce                              = 15036,
	Scout_m_CurrentEvent                             = 15053,
	Scout_m_MacabreWeb                               = 15065,
	Scout_m_Nutcracker                               = 15069,
	Scout_m_BlueMew                                  = 15106,
	Scout_m_FlowerPower                              = 15107,
	Scout_m_ShottoHell                               = 15108,
	Scout_m_CoffinNail                               = 15131,
	Scout_m_KillerBee                                = 15151,
	Scout_m_Corsair                                  = 15157,
	Scout_s_ScoutsPistol                             = 23,
	Scout_s_PistolR                                  = 209,
	Scout_s_BonkAtomicPunch                          = 46,
	Scout_s_VintageLugermorph                        = 160,
	Scout_s_CritaCola                                = 163,
	Scout_s_MadMilk                                  = 222,
	Scout_s_Lugermorph                               = 294,
	Scout_s_TheWinger                                = 449,
	Scout_s_PrettyBoysPocketPistol                   = 773,
	Scout_s_TheFlyingGuillotine                      = 812,
	Scout_s_TheFlyingGuillotineG                     = 833,
	Scout_s_MutatedMilk                              = 1121,
	Scout_s_FestiveBonk                              = 1145,
	Scout_s_RedRockRoscoe                            = 15013,
	Scout_s_HomemadeHeater                           = 15018,
	Scout_s_HickoryHolepuncher                       = 15035,
	Scout_s_LocalHero                                = 15041,
	Scout_s_BlackDahlia                              = 15046,
	Scout_s_SandstoneSpecial                         = 15056,
	Scout_s_MacabreWeb                               = 15060,
	Scout_s_Nutcracker                               = 15061,
	Scout_s_BlueMew                                  = 15100,
	Scout_s_BrainCandy                               = 15101,
	Scout_s_ShottoHell                               = 15102,
	Scout_s_DressedToKill                            = 15126,
	Scout_s_Blitzkrieg                               = 15148,
	Scout_s_TheCAPPER                                = 30666,
	Scout_t_Bat                                      = 0,
	Scout_t_BatR                                     = 190,
	Scout_t_TheSandman                               = 44,
	Scout_t_TheHolyMackerel                          = 221,
	Scout_t_TheCandyCane                             = 317,
	Scout_t_TheBostonBasher                          = 325,
	Scout_t_SunonaStick                              = 349,
	Scout_t_TheFanOWar                               = 355,
	Scout_t_TheAtomizer                              = 450,
	Scout_t_ThreeRuneBlade                           = 452,
	Scout_t_TheConscientiousObjector                 = 474,
	Scout_t_UnarmedCombat                            = 572,
	Scout_t_TheWrapAssassin                          = 648,
	Scout_t_FestiveBat                               = 660,
	Scout_t_TheFreedomStaff                          = 880,
	Scout_t_TheBatOuttaHell                          = 939,
	Scout_t_TheMemoryMaker                           = 954,
	Scout_t_FestiveHolyMackerel                      = 999,
	Scout_t_TheHamShank                              = 1013,
	Scout_t_TheNecroSmasher                          = 1123,
	Scout_t_TheCrossingGuard                         = 1127,
	Scout_t_Batsaber                                 = 30667,
	Scout_t_PrinnyMachete                            = 30758,
	Soldier_m_RocketLauncher                         = 18,
	Soldier_m_RocketLauncherR                        = 205,
	Soldier_m_TheDirectHit                           = 127,
	Soldier_m_TheBlackBox                            = 228,
	Soldier_m_RocketJumper                           = 237,
	Soldier_m_TheLibertyLauncher                     = 414,
	Soldier_m_TheCowMangler5000                      = 441,
	Soldier_m_TheOriginal                            = 513,
	Soldier_m_FestiveRocketLauncher                  = 658,
	Soldier_m_TheBeggarsBazooka                      = 730,
	Soldier_m_SilverBotkillerRocketLauncherMkI       = 800,
	Soldier_m_GoldBotkillerRocketLauncherMkI         = 809,
	Soldier_m_RustBotkillerRocketLauncherMkI         = 889,
	Soldier_m_BloodBotkillerRocketLauncherMkI        = 898,
	Soldier_m_CarbonadoBotkillerRocketLauncherMkI    = 907,
	Soldier_m_DiamondBotkillerRocketLauncherMkI      = 916,
	Soldier_m_SilverBotkillerRocketLauncherMkII      = 965,
	Soldier_m_GoldBotkillerRocketLauncherMkII        = 974,
	Soldier_m_FestiveBlackBox                        = 1085,
	Soldier_m_TheAirStrike                           = 1104,
	Soldier_m_WoodlandWarrior                        = 15006,
	Soldier_m_SandCannon                             = 15014,
	Soldier_m_AmericanPastoral                       = 15028,
	Soldier_m_SmalltownBringdown                     = 15043,
	Soldier_m_ShellShocker                           = 15052,
	Soldier_m_AquaMarine                             = 15057,
	Soldier_m_Autumn                                 = 15081,
	Soldier_m_BlueMew                                = 15104,
	Soldier_m_BrainCandy                             = 15105,
	Soldier_m_CoffinNail                             = 15129,
	Soldier_m_HighRollers                            = 15130,
	Soldier_m_Warhawk                                = 15150,
	Soldier_s_SoldiersShotgun                        = 10,
	Soldier_s_ShotgunR                               = 199,
	Soldier_s_TheBuffBanner                          = 129,
	Soldier_s_Gunboats                               = 133,
	Soldier_s_TheBattalionsBackup                    = 226,
	Soldier_s_TheConcheror                           = 354,
	Soldier_s_TheReserveShooter                      = 415,
	Soldier_s_TheRighteousBison                      = 442,
	Soldier_s_TheMantreads                           = 444,
	Soldier_s_FestiveBuffBanner                      = 1001,
	Soldier_s_TheBASEJumper                          = 1101,
	Soldier_s_FestiveShotgun                         = 1141,
	Soldier_s_PanicAttack                            = 1153,
	Soldier_s_BackwoodsBoomstick                     = 15003,
	Soldier_s_RusticRuiner                           = 15016,
	Soldier_s_CivicDuty                              = 15044,
	Soldier_s_LightningRod                           = 15047,
	Soldier_s_Autumn                                 = 15085,
	Soldier_s_FlowerPower                            = 15109,
	Soldier_s_CoffinNail                             = 15132,
	Soldier_s_DressedtoKill                          = 15133,
	Soldier_s_RedBear                                = 15152,
	Soldier_t_Shovel                                 = 6,
	Soldier_t_ShovelR                                = 196,
	Soldier_t_TheEqualizer                           = 128,
	Soldier_t_ThePainTrain                           = 154,
	Soldier_t_TheHalfZatoichi                        = 357,
	Soldier_t_TheMarketGardener                      = 416,
	Soldier_t_TheDisciplinaryAction                  = 447,
	Soldier_t_TheConscientiousObjector               = 474,
	Soldier_t_TheEscapePlan                          = 775,
	Soldier_t_TheFreedomStaff                        = 880,
	Soldier_t_TheBatOuttaHell                        = 939,
	Soldier_t_TheMemoryMaker                         = 954,
	Soldier_t_TheHamShank                            = 1013,
	Soldier_t_TheNecroSmasher                        = 1123,
	Soldier_t_TheCrossingGuard                       = 1127,
	Soldier_t_PrinnyMachete                          = 30758,
	Pyro_m_FlameThrower                              = 21,
	Pyro_m_FlameThrowerR                             = 208,
	Pyro_m_TheBackburner                             = 40,
	Pyro_m_TheDegreaser                              = 215,
	Pyro_m_ThePhlogistinator                         = 594,
	Pyro_m_FestiveFlameThrower                       = 659,
	Pyro_m_TheRainblower                             = 741,
	Pyro_m_SilverBotkillerFlameThrowerMkI            = 798,
	Pyro_m_GoldBotkillerFlameThrowerMkI              = 807,
	Pyro_m_RustBotkillerFlameThrowerMkI              = 887,
	Pyro_m_BloodBotkillerFlameThrowerMkI             = 896,
	Pyro_m_CarbonadoBotkillerFlameThrowerMkI         = 905,
	Pyro_m_DiamondBotkillerFlameThrowerMkI           = 914,
	Pyro_m_SilverBotkillerFlameThrowerMkII           = 963,
	Pyro_m_GoldBotkillerFlameThrowerMkII             = 972,
	Pyro_m_FestiveBackburner                         = 1146,
	Pyro_m_DragonsFury                               = 1178,
	Pyro_m_ForestFire                                = 15005,
	Pyro_m_BarnBurner                                = 15017,
	Pyro_m_BovineBlazemaker                          = 15030,
	Pyro_m_EarthSkyandFire                           = 15034,
	Pyro_m_FlashFryer                                = 15049,
	Pyro_m_TurbineTorcher                            = 15054,
	Pyro_m_Autumn                                    = 15066,
	Pyro_m_PumpkinPatch                              = 15067,
	Pyro_m_Nutcracker                                = 15068,
	Pyro_m_Balloonicorn                              = 15089,
	Pyro_m_Rainbow                                   = 15090,
	Pyro_m_CoffinNail                                = 15115,
	Pyro_m_Warhawk                                   = 15141,
	Pyro_m_NostromoNapalmer                          = 30474,
	Pyro_s_PyrosShotgun                              = 12,
	Pyro_s_ShotgunR                                  = 199,
	Pyro_s_TheFlareGun                               = 39,
	Pyro_s_TheDetonator                              = 351,
	Pyro_s_TheReserveShooter                         = 415,
	Pyro_s_TheManmelter                              = 595,
	Pyro_s_TheScorchShot                             = 740,
	Pyro_s_FestiveFlareGun                           = 1081,
	Pyro_s_FestiveShotgun                            = 1141,
	Pyro_s_PanicAttack                               = 1153,
	Pyro_s_ThermalThruster                           = 1179,
	Pyro_s_GasPasser                                 = 1180,
	Pyro_s_BackwoodsBoomstick                        = 15003,
	Pyro_s_RusticRuiner                              = 15016,
	Pyro_s_CivicDuty                                 = 15044,
	Pyro_s_LightningRod                              = 15047,
	Pyro_s_Autumn                                    = 15085,
	Pyro_s_FlowerPower                               = 15109,
	Pyro_s_CoffinNail                                = 15132,
	Pyro_s_DressedtoKill                             = 15133,
	Pyro_s_RedBear                                   = 15152,
	Pyro_t_FireAxe                                   = 2,
	Pyro_t_FireAxeR                                  = 192,
	Pyro_t_TheAxtinguisher                           = 38,
	Pyro_t_Homewrecker                               = 153,
	Pyro_t_ThePowerjack                              = 214,
	Pyro_t_TheBackScratcher                          = 326,
	Pyro_t_SharpenedVolcanoFragment                  = 348,
	Pyro_t_ThePostalPummeler                         = 457,
	Pyro_t_TheMaul                                   = 466,
	Pyro_t_TheConscientiousObjector                  = 474,
	Pyro_t_TheThirdDegree                            = 593,
	Pyro_t_TheLollichop                              = 739,
	Pyro_t_NeonAnnihilator                           = 813,
	Pyro_t_NeonAnnihilatorG                          = 834,
	Pyro_t_TheFreedomStaff                           = 880,
	Pyro_t_TheBatOuttaHell                           = 939,
	Pyro_t_TheMemoryMaker                            = 954,
	Pyro_t_TheFestiveAxtinguisher                    = 1000,
	Pyro_t_TheHamShank                               = 1013,
	Pyro_t_TheNecroSmasher                           = 1123,
	Pyro_t_TheCrossingGuard                          = 1127,
	Pyro_t_HotHand                                   = 1181,
	Pyro_t_PrinnyMachete                             = 30758,
	Demoman_m_GrenadeLauncher                        = 19,
	Demoman_m_GrenadeLauncherR                       = 206,
	Demoman_m_TheLochnLoad                           = 308,
	Demoman_m_AliBabasWeeBooties                     = 405,
	Demoman_m_TheBootlegger                          = 608,
	Demoman_m_TheLooseCannon                         = 996,
	Demoman_m_FestiveGrenadeLauncher                 = 1007,
	Demoman_m_TheBASEJumper                          = 1101,
	Demoman_m_TheIronBomber                          = 1151,
	Demoman_m_Autumn                                 = 15077,
	Demoman_m_MacabreWeb                             = 15079,
	Demoman_m_Rainbow                                = 15091,
	Demoman_m_SweetDreams                            = 15092,
	Demoman_m_CoffinNail                             = 15116,
	Demoman_m_TopShelf                               = 15117,
	Demoman_m_Warhawk                                = 15142,
	Demoman_m_ButcherBird                            = 15158,
	Demoman_s_StickybombLauncher                     = 20,
	Demoman_s_StickybombLauncherR                    = 207,
	Demoman_s_TheScottishResistance                  = 130,
	Demoman_s_TheCharginTarge                        = 131,
	Demoman_s_StickyJumper                           = 265,
	Demoman_s_TheSplendidScreen                      = 406,
	Demoman_s_FestiveStickybombLauncher              = 661,
	Demoman_s_SilverBotkillerStickybombLauncherMkI   = 797,
	Demoman_s_GoldBotkillerStickybombLauncherMkI     = 806,
	Demoman_s_RustBotkillerStickybombLauncherMkI     = 886,
	Demoman_s_BloodBotkillerStickybombLauncherMkI    = 895,
	Demoman_s_CarbonadoBotkillerStickybombLauncherMkI= 904,
	Demoman_s_DiamondBotkillerStickybombLauncherMkI  = 913,
	Demoman_s_SilverBotkillerStickybombLauncherMkII  = 962,
	Demoman_s_GoldBotkillerStickybombLauncherMkII    = 971,
	Demoman_s_TheTideTurner                          = 1099,
	Demoman_s_FestiveTarge                           = 1144,
	Demoman_s_TheQuickiebombLauncher                 = 1150,
	Demoman_s_SuddenFlurry                           = 15009,
	Demoman_s_CarpetBomber                           = 15012,
	Demoman_s_BlastedBombardier                      = 15024,
	Demoman_s_RooftopWrangler                        = 15038,
	Demoman_s_LiquidAsset                            = 15045,
	Demoman_s_PinkElephant                           = 15048,
	Demoman_s_Autumn                                 = 15082,
	Demoman_s_PumpkinPatch                           = 15083,
	Demoman_s_MacabreWeb                             = 15084,
	Demoman_s_SweetDreams                            = 15113,
	Demoman_s_CoffinNail                             = 15137,
	Demoman_s_DressedtoKill                          = 15138,
	Demoman_s_Blitzkrieg                             = 15155,
	Demoman_t_Bottle                                 = 1,
	Demoman_t_BottleR                                = 191,
	Demoman_t_TheEyelander                           = 132,
	Demoman_t_ThePainTrain                           = 154,
	Demoman_t_TheScotsmansSkullcutter                = 172,
	Demoman_t_HorselessHeadlessHorsemannsHeadtaker   = 266,
	Demoman_t_UllapoolCaber                          = 307,
	Demoman_t_TheClaidheamhMor                       = 327,
	Demoman_t_TheHalfZatoichi                        = 357,
	Demoman_t_ThePersianPersuader                    = 404,
	Demoman_t_TheConscientiousObjector               = 474,
	Demoman_t_NessiesNineIron                        = 482,
	Demoman_t_TheScottishHandshake                   = 609,
	Demoman_t_TheFreedomStaff                        = 880,
	Demoman_t_TheBatOuttaHell                        = 939,
	Demoman_t_TheMemoryMaker                         = 954,
	Demoman_t_TheHamShank                            = 1013,
	Demoman_t_FestiveEyelander                       = 1082,
	Demoman_t_TheNecroSmasher                        = 1123,
	Demoman_t_TheCrossingGuard                       = 1127,
	Demoman_t_PrinnyMachete                          = 30758,
	Heavy_m_Minigun                                  = 15,
	Heavy_m_MinigunR                                 = 202,
	Heavy_m_Natascha                                 = 41,
	Heavy_m_IronCurtain                              = 298,
	Heavy_m_TheBrassBeast                            = 312,
	Heavy_m_Tomislav                                 = 424,
	Heavy_m_FestiveMinigun                           = 654,
	Heavy_m_SilverBotkillerMinigunMkI                = 793,
	Heavy_m_GoldBotkillerMinigunMkI                  = 802,
	Heavy_m_TheHuoLongHeater                         = 811,
	Heavy_m_TheHuoLongHeaterG                        = 832,
	Heavy_m_Deflector_mvm                            = 850,
	Heavy_m_RustBotkillerMinigunMkI                  = 882,
	Heavy_m_BloodBotkillerMinigunMkI                 = 891,
	Heavy_m_CarbonadoBotkillerMinigunMkI             = 900,
	Heavy_m_DiamondBotkillerMinigunMkI               = 909,
	Heavy_m_SilverBotkillerMinigunMkII               = 958,
	Heavy_m_GoldBotkillerMinigunMkII                 = 967,
	Heavy_m_KingoftheJungle                          = 15004,
	Heavy_m_IronWood                                 = 15020,
	Heavy_m_AntiqueAnnihilator                       = 15026,
	Heavy_m_WarRoom                                  = 15031,
	Heavy_m_CitizenPain                              = 15040,
	Heavy_m_BrickHouse                               = 15055,
	Heavy_m_MacabreWeb                               = 15086,
	Heavy_m_PumpkinPatch                             = 15087,
	Heavy_m_Nutcracker                               = 15088,
	Heavy_m_BrainCandy                               = 15098,
	Heavy_m_MisterCuddles                            = 15099,
	Heavy_m_CoffinNail                               = 15123,
	Heavy_m_DressedtoKill                            = 15124,
	Heavy_m_TopShelf                                 = 15125,
	Heavy_m_ButcherBird                              = 15147,
	Heavy_s_HeavysShotgun                            = 11,
	Heavy_s_ShotgunR                                 = 199,
	Heavy_s_Sandvich                                 = 42,
	Heavy_s_TheDalokohsBar                           = 159,
	Heavy_s_TheBuffaloSteakSandvich                  = 311,
	Heavy_s_TheFamilyBusiness                        = 425,
	Heavy_s_Fishcake                                 = 433,
	Heavy_s_RoboSandvich                             = 863,
	Heavy_s_FestiveSandvich                          = 1002,
	Heavy_s_FestiveShotgun                           = 1141,
	Heavy_s_PanicAttack                              = 1153,
	Heavy_s_SecondBanana                             = 1190,
	Heavy_s_BackwoodsBoomstick                       = 15003,
	Heavy_s_RusticRuiner                             = 15016,
	Heavy_s_CivicDuty                                = 15044,
	Heavy_s_LightningRod                             = 15047,
	Heavy_s_Autumn                                   = 15085,
	Heavy_s_FlowerPower                              = 15109,
	Heavy_s_CoffinNail                               = 15132,
	Heavy_s_DressedtoKill                            = 15133,
	Heavy_s_RedBear                                  = 15152,
	Heavy_t_Fists                                    = 5,
	Heavy_t_FistsR                                   = 195,
	Heavy_t_TheKillingGlovesofBoxing                 = 43,
	Heavy_t_GlovesofRunningUrgently                  = 239,
	Heavy_t_WarriorsSpirit                           = 310,
	Heavy_t_FistsofSteel                             = 331,
	Heavy_t_TheEvictionNotice                        = 426,
	Heavy_t_TheConscientiousObjector                 = 474,
	Heavy_t_ApocoFists                               = 587,
	Heavy_t_TheHolidayPunch                          = 656,
	Heavy_t_TheFreedomStaff                          = 880,
	Heavy_t_TheBatOuttaHell                          = 939,
	Heavy_t_TheMemoryMaker                           = 954,
	Heavy_t_TheHamShank                              = 1013,
	Heavy_t_FestiveGlovesofRunningUrgently           = 1084,
	Heavy_t_TheBreadBite                             = 1100,
	Heavy_t_TheNecroSmasher                          = 1123,
	Heavy_t_TheCrossingGuard                         = 1127,
	Heavy_t_GlovesofRunningUrgentlyMvM               = 1184,
	Heavy_t_PrinnyMachete                            = 30758,
	Engi_m_EngineersShotgun                          = 9,
	Engi_m_ShotgunR                                  = 199,
	Engi_m_TheFrontierJustice                        = 141,
	Engi_m_TheWidowmaker                             = 527,
	Engi_m_ThePomson6000                             = 588,
	Engi_m_TheRescueRanger                           = 997,
	Engi_m_FestiveFrontierJustice                    = 1004,
	Engi_m_FestiveShotgun                            = 1141,
	Engi_m_PanicAttack                               = 1153,
	Engi_m_BackwoodsBoomstick                        = 15003,
	Engi_m_RusticRuiner                              = 15016,
	Engi_m_CivicDuty                                 = 15044,
	Engi_m_LightningRod                              = 15047,
	Engi_m_Autumn                                    = 15085,
	Engi_m_FlowerPower                               = 15109,
	Engi_m_CoffinNail                                = 15132,
	Engi_m_DressedtoKill                             = 15133,
	Engi_m_RedBear                                   = 15152,
	Engi_s_EngineersPistol                           = 22,
	Engi_s_PistolR                                   = 209,
	Engi_s_TheWrangler                               = 140,
	Engi_s_VintageLugermorph                         = 160,
	Engi_s_Lugermorph                                = 294,
	Engi_s_TheShortCircuit                           = 528,
	Engi_s_FestiveWrangler                           = 1086,
	Engi_s_RedRockRoscoe                             = 15013,
	Engi_s_HomemadeHeater                            = 15018,
	Engi_s_HickoryHolepuncher                        = 15035,
	Engi_s_LocalHero                                 = 15041,
	Engi_s_BlackDahlia                               = 15046,
	Engi_s_SandstoneSpecial                          = 15056,
	Engi_s_MacabreWeb                                = 15060,
	Engi_s_Nutcracker                                = 15061,
	Engi_s_BlueMew                                   = 15100,
	Engi_s_BrainCandy                                = 15101,
	Engi_s_ShottoHell                                = 15102,
	Engi_s_DressedToKill                             = 15126,
	Engi_s_Blitzkrieg                                = 15148,
	Engi_s_TheCAPPER                                 = 30666,
	Engi_s_TheGigarCounter                           = 30668,
	Engi_t_Wrench                                    = 7,
	Engi_t_WrenchR                                   = 197,
	Engi_t_TheGunslinger                             = 142,
	Engi_t_TheSouthernHospitality                    = 155,
	Engi_t_GoldenWrench                              = 169,
	Engi_t_TheJag                                    = 329,
	Engi_t_TheEurekaEffect                           = 589,
	Engi_t_FestiveWrench                             = 662,
	Engi_t_SilverBotkillerWrenchMkI                  = 795,
	Engi_t_GoldBotkillerWrenchMkI                    = 804,
	Engi_t_RustBotkillerWrenchMkI                    = 884,
	Engi_t_BloodBotkillerWrenchMkI                   = 893,
	Engi_t_CarbonadoBotkillerWrenchMkI               = 902,
	Engi_t_DiamondBotkillerWrenchMkI                 = 911,
	Engi_t_SilverBotkillerWrenchMkII                 = 960,
	Engi_t_GoldBotkillerWrenchMkII                   = 969,
	Engi_t_TheNecroSmasher                           = 1123,
	Engi_t_Nutcracker                                = 15073,
	Engi_t_Autumn                                    = 15074,
	Engi_t_Boneyard                                  = 15075,
	Engi_t_DressedtoKill                             = 15139,
	Engi_t_TopShelf                                  = 15140,
	Engi_t_TorquedtoHell                             = 15114,
	Engi_t_Airwolf                                   = 15156,
	Engi_t_PrinnyMachete                             = 30758,
	Engi_p_ConstructionPDA                           = 25,
	Engi_p_ConstructionPDAR                          = 737,
	Engi_p_DestructionPDA                            = 26,
	Engi_p_PDA                                       = 28,
	Medic_m_SyringeGun                               = 17,
	Medic_m_SyringeGunR                              = 204,
	Medic_m_TheBlutsauger                            = 36,
	Medic_m_CrusadersCrossbow                        = 305,
	Medic_m_TheOverdose                              = 412,
	Medic_m_FestiveCrusadersCrossbow                 = 1079,
	Medic_s_MediGun                                  = 29,
	Medic_s_MediGunR                                 = 211,
	Medic_s_TheKritzkrieg                            = 35,
	Medic_s_TheQuickFix                              = 411,
	Medic_s_FestiveMediGun                           = 663,
	Medic_s_SilverBotkillerMediGunMkI                = 796,
	Medic_s_GoldBotkillerMediGunMkI                  = 805,
	Medic_s_RustBotkillerMediGunMkI                  = 885,
	Medic_s_BloodBotkillerMediGunMkI                 = 894,
	Medic_s_CarbonadoBotkillerMediGunMkI             = 903,
	Medic_s_DiamondBotkillerMediGunMkI               = 912,
	Medic_s_SilverBotkillerMediGunMkII               = 961,
	Medic_s_GoldBotkillerMediGunMkII                 = 970,
	Medic_s_TheVaccinator                            = 998,
	Medic_s_MaskedMender                             = 15008,
	Medic_s_WrappedReviver                           = 15010,
	Medic_s_ReclaimedReanimator                      = 15025,
	Medic_s_CivilServant                             = 15039,
	Medic_s_SparkofLife                              = 15050,
	Medic_s_Wildwood                                 = 15078,
	Medic_s_FlowerPower                              = 15097,
	Medic_s_DressedToKill                            = 15121,
	Medic_s_HighRollers                              = 15122,
	Medic_s_CoffinNail                               = 15123,
	Medic_s_Blitzkrieg                               = 15145,
	Medic_s_Corsair                                  = 15146,
	Medic_t_Bonesaw                                  = 8,
	Medic_t_BonesawR                                 = 198,
	Medic_t_TheUbersaw                               = 37,
	Medic_t_TheVitaSaw                               = 173,
	Medic_t_Amputator                                = 304,
	Medic_t_TheSolemnVow                             = 413,
	Medic_t_TheConscientiousObjector                 = 474,
	Medic_t_TheFreedomStaff                          = 880,
	Medic_t_TheBatOuttaHell                          = 939,
	Medic_t_TheMemoryMaker                           = 954,
	Medic_t_FestiveUbersaw                           = 1003,
	Medic_t_TheHamShank                              = 1013,
	Medic_t_TheNecroSmasher                          = 1123,
	Medic_t_TheCrossingGuard                         = 1127,
	Medic_t_FestiveBonesaw                           = 1143,
	Medic_t_PrinnyMachete                            = 30758,
	Sniper_m_SniperRifle                             = 14,
	Sniper_m_SniperRifleR                            = 201,
	Sniper_m_TheHuntsman                             = 56,
	Sniper_m_TheSydneySleeper                        = 230,
	Sniper_m_TheBazaarBargain                        = 402,
	Sniper_m_TheMachina                              = 526,
	Sniper_m_FestiveSniperRifle                      = 664,
	Sniper_m_TheHitmansHeatmaker                     = 752,
	Sniper_m_SilverBotkillerSniperRifleMkI           = 792,
	Sniper_m_GoldBotkillerSniperRifleMkI             = 801,
	Sniper_m_TheAWPerHand                            = 851,
	Sniper_m_RustBotkillerSniperRifleMkI             = 881,
	Sniper_m_BloodBotkillerSniperRifleMkI            = 890,
	Sniper_m_CarbonadoBotkillerSniperRifleMkI        = 899,
	Sniper_m_DiamondBotkillerSniperRifleMkI          = 908,
	Sniper_m_SilverBotkillerSniperRifleMkII          = 957,
	Sniper_m_GoldBotkillerSniperRifleMkII            = 966,
	Sniper_m_FestiveHuntsman                         = 1005,
	Sniper_m_TheFortifiedCompound                    = 1092,
	Sniper_m_TheClassic                              = 1098,
	Sniper_m_NightOwl                                = 15000,
	Sniper_m_PurpleRange                             = 15007,
	Sniper_m_LumberFromDownUnder                     = 15019,
	Sniper_m_ShotintheDark                           = 15023,
	Sniper_m_Bogtrotter                              = 15033,
	Sniper_m_Thunderbolt                             = 15059,
	Sniper_m_PumpkinPatch                            = 15070,
	Sniper_m_Boneyard                                = 15071,
	Sniper_m_Wildwood                                = 15072,
	Sniper_m_Balloonicorn                            = 15111,
	Sniper_m_Rainbow                                 = 15112,
	Sniper_m_CoffinNail                              = 15135,
	Sniper_m_DressedtoKill                           = 15136,
	Sniper_m_Airwolf                                 = 15154,
	Sniper_m_ShootingStar                            = 30665,
	Sniper_s_SMG                                     = 16,
	Sniper_s_SMGR                                    = 203,
	Sniper_s_TheRazorback                            = 57,
	Sniper_s_Jarate                                  = 58,
	Sniper_s_DarwinsDangerShield                     = 231,
	Sniper_s_CozyCamper                              = 642,
	Sniper_s_TheCleanersCarbine                      = 751,
	Sniper_s_FestiveJarate                           = 1083,
	Sniper_s_TheSelfAwareBeautyMark                  = 1105,
	Sniper_s_FestiveSMG                              = 1149,
	Sniper_s_WoodsyWidowmaker                        = 15001,
	Sniper_s_PlaidPotshotter                         = 15022,
	Sniper_s_TreadplateTormenter                     = 15032,
	Sniper_s_TeamSprayer                             = 15037,
	Sniper_s_LowProfile                              = 15058,
	Sniper_s_Wildwood                                = 15076,
	Sniper_s_BlueMew                                 = 15110,
	Sniper_s_HighRollers                             = 15134,
	Sniper_s_Blitzkrieg                              = 15153,
	Sniper_t_Kukri                                   = 3,
	Sniper_t_KukriR                                  = 193,
	Sniper_t_TheTribalmansShiv                       = 171,
	Sniper_t_TheBushwacka                            = 232,
	Sniper_t_TheShahanshah                           = 401,
	Sniper_t_TheConscientiousObjector                = 474,
	Sniper_t_TheFreedomStaff                         = 880,
	Sniper_t_TheBatOuttaHell                         = 939,
	Sniper_t_TheMemoryMaker                          = 954,
	Sniper_t_TheHamShank                             = 1013,
	Sniper_t_TheNecroSmasher                         = 1123,
	Sniper_t_TheCrossingGuard                        = 1127,
	Sniper_t_PrinnyMachete                           = 30758,
	Spy_m_Revolver                                   = 24,
	Spy_m_RevolverR                                  = 210,
	Spy_m_TheAmbassador                              = 61,
	Spy_m_BigKill                                    = 161,
	Spy_m_LEtranger                                  = 224,
	Spy_m_TheEnforcer                                = 460,
	Spy_m_TheDiamondback                             = 525,
	Spy_m_FestiveAmbassador                          = 1006,
	Spy_m_FestiveRevolver                            = 1142,
	Spy_m_PsychedelicSlugger                         = 15011,
	Spy_m_OldCountry                                 = 15027,
	Spy_m_Mayor                                      = 15042,
	Spy_m_DeadReckoner                               = 15051,
	Spy_m_Boneyard                                   = 15062,
	Spy_m_Wildwood                                   = 15063,
	Spy_m_MacabreWeb                                 = 15064,
	Spy_m_FlowerPower                                = 15103,
	Spy_m_TopShelf                                   = 15128,
	Spy_m_CoffinNail                                 = 15129,
	Spy_m_Blitzkrieg                                 = 15149,
	Spy_s_Sapper                                     = 735,
	Spy_s_SapperR                                    = 736,
	Spy_s_TheRedTapeRecorder                         = 810,
	Spy_s_TheRedTapeRecorderG                        = 831,
	Spy_s_TheApSapG                                  = 933,
	Spy_s_FestiveSapper                              = 1080,
	Spy_s_TheSnackAttack                             = 1102,
	Spy_t_Knife                                      = 4,
	Spy_t_KnifeR                                     = 194,
	Spy_t_YourEternalReward                          = 225,
	Spy_t_ConniversKunai                             = 356,
	Spy_t_TheBigEarner                               = 461,
	Spy_t_TheWangaPrick                              = 574,
	Spy_t_TheSharpDresser                            = 638,
	Spy_t_TheSpycicle                                = 649,
	Spy_t_FestiveKnife                               = 665,
	Spy_t_TheBlackRose                               = 727,
	Spy_t_SilverBotkillerKnifeMkI                    = 794,
	Spy_t_GoldBotkillerKnifeMkI                      = 803,
	Spy_t_RustBotkillerKnifeMkI                      = 883,
	Spy_t_BloodBotkillerKnifeMkI                     = 892,
	Spy_t_CarbonadoBotkillerKnifeMkI                 = 901,
	Spy_t_DiamondBotkillerKnifeMkI                   = 910,
	Spy_t_SilverBotkillerKnifeMkII                   = 959,
	Spy_t_GoldBotkillerKnifeMkII                     = 968,
	Spy_t_Boneyard                                   = 15062,
	Spy_t_BlueMew                                    = 15094,
	Spy_t_BrainCandy                                 = 15095,
	Spy_t_StabbedtoHell                              = 15096,
	Spy_t_DressedtoKill                              = 15118,
	Spy_t_TopShelf                                   = 15119,
	Spy_t_Blitzkrieg                                 = 15143,
	Spy_t_Airwolf                                    = 15144,
	Spy_t_PrinnyMachete                              = 30758,
	Spy_d_DisguiseKitPDA                             = 27,
	Spy_w_InvisWatch                                 = 30,
	Spy_w_InvisWatchR                                = 212,
	Spy_w_TheDeadRinger                              = 59,
	Spy_w_TheCloakandDagger                          = 60,
	Spy_w_EnthusiastsTimepiece                       = 297,
	Spy_w_TheQuackenbirdt                            = 947,
	Misc_t_FryingPan                                 = 264,
	Misc_t_GoldFryingPan                             = 1071,
	Misc_t_Saxxy                                     = 423,
};

enum ETFPlayerState
{
	TF_STATE_ACTIVE = 0,		// Happily running around in the game.
	TF_STATE_WELCOME,			// First entering the server (shows level intro screen).
	TF_STATE_OBSERVER,			// Game observer mode.
	TF_STATE_DYING,				// Player is dying.
	TF_STATE_COUNT
};

enum EObserverModes
{
	OBS_MODE_NONE = 0,		// not in spectator mode
	OBS_MODE_DEATHCAM,		// special mode for death cam animation
	OBS_MODE_FREEZECAM,		// zooms to a target, and freeze-frames on them
	OBS_MODE_FIXED,			// view from a fixed camera position
	OBS_MODE_FIRSTPERSON,	// follow a player in first person view
	OBS_MODE_THIRDPERSON,	// follow a player in third person view
	OBS_MODE_ROAMING,		// free roaming
};

enum UserMessageType
{
	Geiger = 0,
	Train,
	HudText,
	SayText,
	SayText2,
	TextMsg,
	ResetHUD,
	GameTitle,
	ItemPickup,
	ShowMenu,
	Shake,
	Fade,
	VGUIMenu,
	Rumble,
	CloseCaption,
	SendAudio,
	VoiceMask,
	RequestState,
	Damage,
	HintText,
	KeyHintText,
	HudMsg,
	AmmoDenied,
	AchievementEvent,
	UpdateRadar,
	VoiceSubtitle,
	HudNotify,
	HudNotifyCustom,
	PlayerStatsUpdate,
	MapStatsUpdate,
	PlayerIgnited,
	PlayerIgnitedInv,
	HudArenaNotify,
	UpdateAchievement,
	TrainingMsg,
	TrainingObjective,
	DamageDodged,
	PlayerJarated,
	PlayerExtinguished,
	PlayerJaratedFade,
	PlayerShieldBlocked,
	BreakModel,
	CheapBreakModel,
	BreakModel_Pumpkin,
	BreakModelRocketDud,
	CallVoteFailed,
	VoteStart,
	VotePass,
	VoteFailed,
	VoteSetup,
	PlayerBonusPoints,
	RDTeamPointsChanged,
	SpawnFlyingBird,
	PlayerGodRayEffect,
	PlayerTeleportHomeEffect,
	MVMStatsReset,
	MVMPlayerEvent,
	MVMResetPlayerStats,
	MVMWaveFailed,
	MVMAnnouncement,
	MVMPlayerUpgradedEvent,
	MVMVictory,
	MVMWaveChange,
	MVMLocalPlayerUpgradesClear,
	MVMLocalPlayerUpgradesValue,
	MVMResetPlayerWaveSpendingStats,
	MVMLocalPlayerWaveSpendingValue,
	MVMResetPlayerUpgradeSpending,
	MVMServerKickTimeUpdate,
	PlayerLoadoutUpdated,
	PlayerTauntSoundLoopStart,
	PlayerTauntSoundLoopEnd,
	ForcePlayerViewAngles,
	BonusDucks,
	EOTLDuckEvent,
	PlayerPickupWeapon,
	QuestObjectiveCompleted,
	SPHapWeapEvent,
	HapDmg,
	HapPunch,
	HapSetDrag,
	HapSetConst,
	HapMeleeContact
};

inline int g_aWeaponDamageTypes[] =
{
	DMG_GENERIC,	// TF_WEAPON_NONE
	DMG_CLUB,		// TF_WEAPON_BAT,
	DMG_CLUB,		// TF_WEAPON_BAT_WOOD,
	DMG_CLUB,		// TF_WEAPON_BOTTLE,
	DMG_CLUB,		// TF_WEAPON_FIREAXE,
	DMG_CLUB,		// TF_WEAPON_CLUB,
	DMG_CLUB,		// TF_WEAPON_CROWBAR,
	DMG_SLASH,		// TF_WEAPON_KNIFE,
	DMG_CLUB,		// TF_WEAPON_FISTS,
	DMG_CLUB,		// TF_WEAPON_SHOVEL,
	DMG_CLUB,		// TF_WEAPON_WRENCH,
	DMG_SLASH,		// TF_WEAPON_BONESAW,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,	// TF_WEAPON_SHOTGUN_PRIMARY,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,	// TF_WEAPON_SHOTGUN_SOLDIER,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,	// TF_WEAPON_SHOTGUN_HWG,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,	// TF_WEAPON_SHOTGUN_PYRO,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,  // TF_WEAPON_SCATTERGUN,
	DMG_BULLET | DMG_USE_HITLOCATIONS,	// TF_WEAPON_SNIPERRIFLE,
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_MINIGUN,
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_SMG,
	DMG_BULLET | DMG_USEDISTANCEMOD | DMG_NOCLOSEDISTANCEMOD | DMG_PREVENT_PHYSICS_FORCE,		// TF_WEAPON_SYRINGEGUN_MEDIC,
	DMG_BULLET | DMG_USEDISTANCEMOD | DMG_PREVENT_PHYSICS_FORCE | DMG_PARALYZE,		// TF_WEAPON_TRANQ,
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_USEDISTANCEMOD,		// TF_WEAPON_ROCKETLAUNCHER,
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_USEDISTANCEMOD,		// TF_WEAPON_GRENADELAUNCHER,
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_NOCLOSEDISTANCEMOD,		// TF_WEAPON_PIPEBOMBLAUNCHER,
	DMG_IGNITE | DMG_PREVENT_PHYSICS_FORCE | DMG_PREVENT_PHYSICS_FORCE,		// TF_WEAPON_FLAMETHROWER,
	DMG_BLAST | DMG_HALF_FALLOFF,		// TF_WEAPON_GRENADE_NORMAL,
	DMG_SONIC | DMG_HALF_FALLOFF,		// TF_WEAPON_GRENADE_CONCUSSION,
	DMG_BULLET | DMG_HALF_FALLOFF,		// TF_WEAPON_GRENADE_NAIL,
	DMG_BLAST | DMG_HALF_FALLOFF,		// TF_WEAPON_GRENADE_MIRV,
	DMG_BLAST | DMG_HALF_FALLOFF,		// TF_WEAPON_GRENADE_MIRV_DEMOMAN,
	DMG_BURN | DMG_RADIUS_MAX,		// TF_WEAPON_GRENADE_NAPALM,
	DMG_POISON | DMG_HALF_FALLOFF,		// TF_WEAPON_GRENADE_GAS,
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_PREVENT_PHYSICS_FORCE,		// TF_WEAPON_GRENADE_EMP,
	DMG_GENERIC,	// TF_WEAPON_GRENADE_CALTROP,
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_NOCLOSEDISTANCEMOD,		// TF_WEAPON_GRENADE_PIPEBOMB,
	DMG_GENERIC,	// TF_WEAPON_GRENADE_SMOKE_BOMB,
	DMG_GENERIC,	// TF_WEAPON_GRENADE_HEAL
	DMG_CLUB,		// TF_WEAPON_GRENADE_STUNBALL
	DMG_CLUB,		// TF_WEAPON_GRENADE_JAR
	DMG_CLUB,		// TF_WEAPON_GRENADE_JAR_MILK
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_PISTOL,
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_PISTOL_SCOUT,
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_REVOLVER,
	DMG_BULLET | DMG_USEDISTANCEMOD | DMG_NOCLOSEDISTANCEMOD | DMG_PREVENT_PHYSICS_FORCE,		// TF_WEAPON_NAILGUN,
	DMG_BULLET,		// TF_WEAPON_PDA,
	DMG_BULLET,		// TF_WEAPON_PDA_ENGINEER_BUILD,
	DMG_BULLET,		// TF_WEAPON_PDA_ENGINEER_DESTROY,
	DMG_BULLET,		// TF_WEAPON_PDA_SPY,
	DMG_BULLET,		// TF_WEAPON_BUILDER
	DMG_BULLET,		// TF_WEAPON_MEDIGUN
	DMG_BLAST,		// TF_WEAPON_GRENADE_MIRVBOMB
	DMG_BLAST | DMG_IGNITE | DMG_RADIUS_MAX,		// TF_WEAPON_FLAMETHROWER_ROCKET
	DMG_BLAST | DMG_HALF_FALLOFF,					// TF_WEAPON_GRENADE_DEMOMAN
	DMG_BULLET,	// TF_WEAPON_SENTRY_BULLET
	DMG_BLAST,	// TF_WEAPON_SENTRY_ROCKET
	DMG_GENERIC,	// TF_WEAPON_DISPENSER
	DMG_GENERIC,	// TF_WEAPON_INVIS
	DMG_BULLET | DMG_IGNITE,		// TF_WEAPON_FLAREGUN
	DMG_GENERIC,	// TF_WEAPON_LUNCHBOX
	DMG_GENERIC,	// TF_WEAPON_JAR
	DMG_BULLET | DMG_USE_HITLOCATIONS,		// TF_WEAPON_COMPOUND_BOW
	DMG_GENERIC,	// TF_WEAPON_BUFF_ITEM
	DMG_CLUB,		// TF_WEAPON_PUMPKIN_BOMB
	DMG_CLUB,		// TF_WEAPON_SWORD
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_USEDISTANCEMOD,		// TF_WEAPON_ROCKETLAUNCHER_DIRECTHIT,
	DMG_CLUB,		// TF_WEAPON_LIFELINE
	DMG_CLUB,		// TF_WEAPON_LASER_POINTER
	DMG_BULLET,		// TF_WEAPON_DISPENSER_GUN
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD, // TF_WEAPON_SENTRY_REVENGE
	DMG_GENERIC,	// TF_WEAPON_JAR_MILK
	DMG_BUCKSHOT | DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_HANDGUN_SCOUT_PRIMARY
	DMG_CLUB,		// TF_WEAPON_BAT_FISH
	DMG_BULLET | DMG_USE_HITLOCATIONS,
	DMG_CLUB, // TF_WEAPON_STICKBOMB
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_HANDGUN_SCOUT_SECONDARY
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,  // TF_WEAPON_SODA_POPPER,
	DMG_BULLET | DMG_USE_HITLOCATIONS,	// TF_WEAPON_SNIPERRIFLE_DECAP,
	DMG_BULLET | DMG_USEDISTANCEMOD | DMG_NOCLOSEDISTANCEMOD,	// TF_WEAPON_RAYGUN,
	DMG_BLAST | DMG_HALF_FALLOFF | DMG_USEDISTANCEMOD,		// TF_WEAPON_PARTICLE_CANNON,
	DMG_BULLET | DMG_USEDISTANCEMOD,	// TF_WEAPON_MECHANICAL_ARM,
	DMG_BULLET | DMG_USEDISTANCEMOD | DMG_NOCLOSEDISTANCEMOD,	// TF_WEAPON_DRG_POMSON,
	DMG_CLUB,		// TF_WEAPON_BAT_GIFTWRAP,
	DMG_CLUB,		// TF_WEAPON_GRENADE_ORNAMENT_BALL
	DMG_BULLET | DMG_IGNITE,	// TF_WEAPON_FLAREGUN_REVENGE,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,  // TF_WEAPON_PEP_BRAWLER_BLASTER,
	DMG_GENERIC,	// TF_WEAPON_CLEAVER
	DMG_SLASH,		// TF_WEAPON_GRENADE_CLEAVER
	DMG_GENERIC,	// TF_WEAPON_STICKY_BALL_LAUNCHER,
	DMG_GENERIC,	// TF_WEAPON_GRENADE_STICKY_BALL,
	DMG_BUCKSHOT | DMG_USEDISTANCEMOD,	// TF_WEAPON_SHOTGUN_BUILDING_RESCUE,
	DMG_BLAST | DMG_HALF_FALLOFF,	// TF_WEAPON_CANNON
	DMG_BULLET,		// TF_WEAPON_THROWABLE
	DMG_BULLET,		// TF_WEAPON_GRENADE_THROWABLE
	DMG_BULLET,		// TF_WEAPON_PDA_SPY_BUILD
	DMG_BULLET,		// TF_WEAPON_GRENADE_WATERBALLOON
	DMG_SLASH,		// TF_WEAPON_HARVESTER_SAW
	DMG_GENERIC,	// TF_WEAPON_SPELLBOOK
	DMG_GENERIC,	// TF_WEAPON_SPELLBOOK_PROJECTILE
	DMG_BULLET | DMG_USE_HITLOCATIONS,	// TF_WEAPON_SNIPERRIFLE_CLASSIC,
	DMG_GENERIC, // TF_WEAPON_PARACHUTE,
	DMG_GENERIC, // TF_WEAPON_GRAPPLINGHOOK,
	DMG_GENERIC, // TF_WEAPON_PASSTIME_GUN
#ifdef STAGING_ONLY
	DMG_BULLET | DMG_USE_HITLOCATIONS,	// TF_WEAPON_SNIPERRIFLE_REVOLVER,
#endif
	DMG_BULLET | DMG_USEDISTANCEMOD,		// TF_WEAPON_CHARGED_SMG,
};

enum struct EWeaponType
{
	UNKNOWN, HITSCAN, PROJECTILE, MELEE
};

enum RenderTargetSizeMode_t
{
	RT_SIZE_NO_CHANGE = 0,			// Only allowed for render targets that don't want a depth buffer
	// (because if they have a depth buffer, the render target must be less than or equal to the size of the framebuffer).
	RT_SIZE_DEFAULT = 1,				// Don't play with the specified width and height other than making sure it fits in the framebuffer.
	RT_SIZE_PICMIP = 2,				// Apply picmip to the render target's width and height.
	RT_SIZE_HDR = 3,					// frame_buffer_width / 4
	RT_SIZE_FULL_FRAME_BUFFER = 4,	// Same size as frame buffer, or next lower power of 2 if we can't do that.
	RT_SIZE_OFFSCREEN = 5,			// Target of specified size, don't mess with dimensions
	RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP = 6, // Same size as the frame buffer, rounded up if necessary for systems that can't do non-power of two textures.
	RT_SIZE_REPLAY_SCREENSHOT = 7,	// Rounded down to power of 2, essentially...
	RT_SIZE_LITERAL = 8,			// Use the size passed in. Don't clamp it to the frame buffer size. Really.
	RT_SIZE_LITERAL_PICMIP = 9		// Use the size passed in, don't clamp to the frame buffer size, but do apply picmip restrictions.
};

enum ImageFormat
{
	IMAGE_FORMAT_UNKNOWN = -1,
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,			// Single-channel 32-bit floating point
	IMAGE_FORMAT_RGB323232F,
	IMAGE_FORMAT_RGBA32323232F,

	// Depth-stencil texture formats for shadow depth mapping
	IMAGE_FORMAT_NV_DST16,		//
	IMAGE_FORMAT_NV_DST24,		//
	IMAGE_FORMAT_NV_INTZ,		// Vendor-specific depth-stencil texture
	IMAGE_FORMAT_NV_RAWZ,		// formats for shadow depth mapping
	IMAGE_FORMAT_ATI_DST16,		//
	IMAGE_FORMAT_ATI_DST24,		//
	IMAGE_FORMAT_NV_NULL,		// Dummy format which takes no video memory

	// Compressed normal map formats
	IMAGE_FORMAT_ATI2N,			// One-surface ATI2N / DXN format
	IMAGE_FORMAT_ATI1N,			// Two-surface ATI1N format

	IMAGE_FORMAT_DXT1_RUNTIME,
	IMAGE_FORMAT_DXT5_RUNTIME,

	NUM_IMAGE_FORMATS
};

enum MaterialRenderTargetDepth_t
{
	MATERIAL_RT_DEPTH_SHARED = 0x0,
	MATERIAL_RT_DEPTH_SEPARATE = 0x1,
	MATERIAL_RT_DEPTH_NONE = 0x2,
	MATERIAL_RT_DEPTH_ONLY = 0x3,
};

enum CompiledVtfFlags
{
	// flags from the *.txt config file
	TEXTUREFLAGS_POINTSAMPLE = 0x00000001,
	TEXTUREFLAGS_TRILINEAR = 0x00000002,
	TEXTUREFLAGS_CLAMPS = 0x00000004,
	TEXTUREFLAGS_CLAMPT = 0x00000008,
	TEXTUREFLAGS_ANISOTROPIC = 0x00000010,
	TEXTUREFLAGS_HINT_DXT5 = 0x00000020,
	TEXTUREFLAGS_SRGB = 0x00000040,
	TEXTUREFLAGS_NORMAL = 0x00000080,
	TEXTUREFLAGS_NOMIP = 0x00000100,
	TEXTUREFLAGS_NOLOD = 0x00000200,
	TEXTUREFLAGS_ALL_MIPS = 0x00000400,
	TEXTUREFLAGS_PROCEDURAL = 0x00000800,

	// These are automatically generated by vtex from the texture data.
	TEXTUREFLAGS_ONEBITALPHA = 0x00001000,
	TEXTUREFLAGS_EIGHTBITALPHA = 0x00002000,

	// newer flags from the *.txt config file
	TEXTUREFLAGS_ENVMAP = 0x00004000,
	TEXTUREFLAGS_RENDERTARGET = 0x00008000,
	TEXTUREFLAGS_DEPTHRENDERTARGET = 0x00010000,
	TEXTUREFLAGS_NODEBUGOVERRIDE = 0x00020000,
	TEXTUREFLAGS_SINGLECOPY = 0x00040000,

	TEXTUREFLAGS_STAGING_MEMORY = 0x00080000,
	TEXTUREFLAGS_IMMEDIATE_CLEANUP = 0x00100000,
	TEXTUREFLAGS_IGNORE_PICMIP = 0x00200000,

	TEXTUREFLAGS_UNUSED_00400000 = 0x00400000,

	TEXTUREFLAGS_NODEPTHBUFFER = 0x00800000,

	TEXTUREFLAGS_UNUSED_01000000 = 0x01000000,

	TEXTUREFLAGS_CLAMPU = 0x02000000,

	TEXTUREFLAGS_VERTEXTEXTURE = 0x04000000,					// Useable as a vertex texture

	TEXTUREFLAGS_SSBUMP = 0x08000000,

	TEXTUREFLAGS_UNUSED_10000000 = 0x10000000,

	// Clamp to border color on all texture coordinates
	TEXTUREFLAGS_BORDER = 0x20000000,

	TEXTUREFLAGS_STREAMABLE_COARSE = 0x40000000,
	TEXTUREFLAGS_STREAMABLE_FINE = 0x80000000,
	TEXTUREFLAGS_STREAMABLE = (TEXTUREFLAGS_STREAMABLE_COARSE | TEXTUREFLAGS_STREAMABLE_FINE)

};

enum StencilOperation_t
{
#if !defined( _X360 )
	STENCILOPERATION_KEEP = 1,
	STENCILOPERATION_ZERO = 2,
	STENCILOPERATION_REPLACE = 3,
	STENCILOPERATION_INCRSAT = 4,
	STENCILOPERATION_DECRSAT = 5,
	STENCILOPERATION_INVERT = 6,
	STENCILOPERATION_INCR = 7,
	STENCILOPERATION_DECR = 8,
#else
	STENCILOPERATION_KEEP = D3DSTENCILOP_KEEP,
	STENCILOPERATION_ZERO = D3DSTENCILOP_ZERO,
	STENCILOPERATION_REPLACE = D3DSTENCILOP_REPLACE,
	STENCILOPERATION_INCRSAT = D3DSTENCILOP_INCRSAT,
	STENCILOPERATION_DECRSAT = D3DSTENCILOP_DECRSAT,
	STENCILOPERATION_INVERT = D3DSTENCILOP_INVERT,
	STENCILOPERATION_INCR = D3DSTENCILOP_INCR,
	STENCILOPERATION_DECR = D3DSTENCILOP_DECR,
#endif
	STENCILOPERATION_FORCE_DWORD = 0x7fffffff
};

enum StencilComparisonFunction_t
{
#if !defined( _X360 )
	STENCILCOMPARISONFUNCTION_NEVER = 1,
	STENCILCOMPARISONFUNCTION_LESS = 2,
	STENCILCOMPARISONFUNCTION_EQUAL = 3,
	STENCILCOMPARISONFUNCTION_LESSEQUAL = 4,
	STENCILCOMPARISONFUNCTION_GREATER = 5,
	STENCILCOMPARISONFUNCTION_NOTEQUAL = 6,
	STENCILCOMPARISONFUNCTION_GREATEREQUAL = 7,
	STENCILCOMPARISONFUNCTION_ALWAYS = 8,
#else
	STENCILCOMPARISONFUNCTION_NEVER = D3DCMP_NEVER,
	STENCILCOMPARISONFUNCTION_LESS = D3DCMP_LESS,
	STENCILCOMPARISONFUNCTION_EQUAL = D3DCMP_EQUAL,
	STENCILCOMPARISONFUNCTION_LESSEQUAL = D3DCMP_LESSEQUAL,
	STENCILCOMPARISONFUNCTION_GREATER = D3DCMP_GREATER,
	STENCILCOMPARISONFUNCTION_NOTEQUAL = D3DCMP_NOTEQUAL,
	STENCILCOMPARISONFUNCTION_GREATEREQUAL = D3DCMP_GREATEREQUAL,
	STENCILCOMPARISONFUNCTION_ALWAYS = D3DCMP_ALWAYS,
#endif

	STENCILCOMPARISONFUNCTION_FORCE_DWORD = 0x7fffffff
};

enum MorphFormatFlags_t
{
	MORPH_POSITION = 0x0001,	// 3D
	MORPH_NORMAL = 0x0002,	// 3D
	MORPH_WRINKLE = 0x0004,	// 1D
	MORPH_SPEED = 0x0008,	// 1D
	MORPH_SIDE = 0x0010,	// 1D
};

typedef unsigned int MorphFormat_t;

enum StandardLightmap_t
{
	MATERIAL_SYSTEM_LIGHTMAP_PAGE_WHITE = -1,
	MATERIAL_SYSTEM_LIGHTMAP_PAGE_WHITE_BUMP = -2,
	MATERIAL_SYSTEM_LIGHTMAP_PAGE_USER_DEFINED = -3
};
