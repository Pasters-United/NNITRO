#pragma once
#include "../../Feature.h"

class CChams
{
	bool GetChams(CBaseEntity* pEntity, Chams_t* pChams, bool* bViewmodel);

	void StencilBegin(IMatRenderContext* pRenderContext, bool bTwoModels = false);
	void StencilVisible(IMatRenderContext* pRenderContext, bool bTwoModels = false);
	void StencilOccluded(IMatRenderContext* pRenderContext);
	void StencilEnd(IMatRenderContext* pRenderContext, bool bTwoModels = false);

	void DrawModel(CBaseEntity* pEntity, Chams_t chams, IMatRenderContext* pRenderContext, bool bTwoModels = true, bool bViewmodel = false);

	void RenderBacktrack(const DrawModelState_t& pState, const ModelRenderInfo_t& pInfo, matrix3x4* pBoneToWorld);
	void RenderFakeAngle(const DrawModelState_t& pState, const ModelRenderInfo_t& pInfo, matrix3x4* pBoneToWorld);

public:
	void RenderMain();
	void RenderHandler(const DrawModelState_t& pState, const ModelRenderInfo_t& pInfo, matrix3x4* pBoneToWorld);

	bool RenderViewmodel(void* ecx, int flags, int* iReturn);
	bool RenderViewmodel(const DrawModelState_t& pState, const ModelRenderInfo_t& pInfo, matrix3x4* pBoneToWorld);

	bool bRendering = false;
	bool bExtra = false;

	std::unordered_map<int, bool> mEntities = {};
};

ADD_FEATURE(CChams, Chams)