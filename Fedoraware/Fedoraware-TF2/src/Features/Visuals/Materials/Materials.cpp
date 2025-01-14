#include "Materials.h"

#include <filesystem>
#include <fstream>

#include "../../Menu/ConfigManager/ConfigManager.h"

IMaterial* CMaterials::CreateNRef(char const* szName, void* pKV)
{
	IMaterial* returnMaterial = I::MaterialSystem->Create(szName, pKV);
	returnMaterial->IncrementReferenceCount();
	vMatList.push_back(returnMaterial);
	return returnMaterial;
}

void CMaterials::RemoveMaterials()
{
	// placeholder just in case
	ReloadMaterials();
}

void CMaterials::ReloadMaterials()
{
	// clear existing materials

	for (auto& [_, mat] : mChamMaterials)
	{
		if (!mat.pMaterial)
			continue;

		mat.pMaterial->DecrementReferenceCount();
		mat.pMaterial->DeleteIfUnreferenced();
		mat.pMaterial = nullptr;
	}
	for (auto& [_, mat] : mGlowMaterials)
	{
		if (!mat.pMaterial)
			continue;

		mat.pMaterial->DecrementReferenceCount();
		mat.pMaterial->DeleteIfUnreferenced();
		mat.pMaterial = nullptr;
	}
	mChamMaterials.clear();
	mGlowMaterials.clear();



	// cham materials

	// default materials
	{	// hacky
		Material_t mat = {}; // None

		mat.sVMT =	"\"UnlitGeneric\"";
		mat.sVMT +=	"\n{";
		mat.sVMT +=	"\n	$color2 \"[0 0 0]\"";
		mat.sVMT +=	"\n	$additive \"1\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["None"] = mat;
	}
	{
		Material_t mat = {}; // Flat

		mat.sVMT =	"\"UnlitGeneric\"";
		mat.sVMT +=	"\n{";
		mat.sVMT +=	"\n	$basetexture \"vgui/white_additive\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["Flat"] = mat;
	}
	{
		Material_t mat = {}; // Shaded

		mat.sVMT =	"\"VertexLitGeneric\"";
		mat.sVMT +=	"\n{";
		mat.sVMT +=	"\n	$basetexture \"vgui/white_additive\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["Shaded"] = mat;
	}
	{
		Material_t mat = {}; // Shiny

		mat.sVMT =	"\"VertexLitGeneric\"";
		mat.sVMT +=	"\n{";
		mat.sVMT +=	"\n	$basetexture \"vgui/white_additive\"";
		mat.sVMT +=	"\n	$envmap \"cubemaps/cubemap_sheen001\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["Shiny"] = mat;
	}
	{
		Material_t mat = {}; // Wireframe

		mat.sVMT =	"\"UnlitGeneric\"";
		mat.sVMT += "\n{";
		mat.sVMT += "\n	$basetexture \"vgui/white_additive\"";
		mat.sVMT += "\n	$wireframe \"1\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["Wireframe"] = mat;
	}
	{	// make smoother
		Material_t mat = {}; // Fresnel

		mat.sVMT =	"\"VertexLitGeneric\"";
		mat.sVMT += "\n{";
		mat.sVMT += "\n	$basetexture \"models/player/shared/ice_player\"";
		mat.sVMT += "\n	$bumpmap \"models/player/shared/shared_normal\"";
		mat.sVMT += "\n	$additive \"1\"";
		mat.sVMT += "\n	$phong \"1\"";
		mat.sVMT += "\n	$phongfresnelranges \"[0 0.025 0.05]\"";
		mat.sVMT += "\n	$envmap \"skybox/sky_dustbowl_01\"";
		mat.sVMT += "\n	$envmapfresnel \"1\"";
		mat.sVMT += "\n	$selfillum \"1\"";
		mat.sVMT += "\n	$selfillumtint \"[0 0 0]\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["Fresnel"] = mat;
	}
	{
		Material_t mat = {}; // Tint

		mat.sVMT = "\"VertexLitGeneric\"";
		mat.sVMT += "\n{";
		mat.sVMT += "\n	$basetexture \"models/player/shared/ice_player\"";
		mat.sVMT += "\n	$bumpmap \"models/player/shared/shared_normal\"";
		mat.sVMT += "\n	$additive \"1\"";
		mat.sVMT += "\n	$phong \"1\"";
		mat.sVMT += "\n	$phongfresnelranges \"[0 0.001 0]\"";
		mat.sVMT += "\n	$envmap \"skybox/sky_dustbowl_01\"";
		mat.sVMT += "\n	$envmapfresnel \"1\"";
		mat.sVMT += "\n	$selfillum \"1\"";
		mat.sVMT += "\n	$selfillumtint \"[0 0 0]\"";
		mat.sVMT += "\n}";

		mat.bLocked = true;
		mChamMaterials["Tint"] = mat;
	}
	// user materials
	for (const auto& entry : std::filesystem::directory_iterator(MaterialFolder))
	{
		// Ignore all non-Material files
		if (!entry.is_regular_file() || entry.path().extension() != std::string(".vmt"))
			continue;

		std::ifstream inStream(entry.path());
		if (!inStream.good())
			continue;

		std::string sName = entry.path().filename().string();
		sName.erase(sName.end() - 4, sName.end());
		const std::string sVMT((std::istreambuf_iterator(inStream)), std::istreambuf_iterator<char>());

		Material_t mat = {};
		mat.sVMT = sVMT;

		mChamMaterials[sName] = mat;
	}
	// create materials
	for (auto& [sName, mat] : mChamMaterials)
	{
		const auto kv = new KeyValues(sName.c_str());
		g_KeyValUtils.LoadFromBuffer(kv, sName.c_str(), mat.sVMT.c_str());
		mat.pMaterial = CreateNRef(std::format("m_pMat%s", sName).c_str(), kv);
	}

	

	// glow materials

	{
		Material_t mat = {}; // GlowColor

		mat.pMaterial = I::MaterialSystem->Find("dev/glow_color", TEXTURE_GROUP_OTHER);
		mat.pMaterial->IncrementReferenceCount();

		mGlowMaterials["GlowColor"] = mat;
	}
	{
		Material_t mat = {}; // BlurX

		KeyValues* m_pMatBlurXKV = new KeyValues("BlurFilterX");
		m_pMatBlurXKV->SetString("$basetexture", "glow_buffer_1");
		mat.pMaterial = CreateNRef("m_pMatBlurX", m_pMatBlurXKV);

		mGlowMaterials["BlurX"] = mat;
	}
	{
		Material_t mat = {}; // BlurY

		KeyValues* m_pMatBlurYKV = new KeyValues("BlurFilterY");
		m_pMatBlurYKV->SetString("$basetexture", "glow_buffer_2");
		mat.pMaterial = CreateNRef("m_pMatBlurY", m_pMatBlurYKV);

		mGlowMaterials["BlurY"] = mat;
	}
	{
		Material_t mat = {}; // HaloAddToScreen

		KeyValues* m_pMatHaloAddToScreenKV = new KeyValues("UnlitGeneric");
		m_pMatHaloAddToScreenKV->SetString("$basetexture", "glow_buffer_1");
		m_pMatHaloAddToScreenKV->SetString("$additive", "1");
		mat.pMaterial = CreateNRef("m_pMatHaloAddToScreen", m_pMatHaloAddToScreenKV);

		mGlowMaterials["HaloAddToScreen"] = mat;
	}
}

void CMaterials::SetColor(IMaterial* material, Color_t color, bool bSetColor)
{
	if (bSetColor)
	{
		if (material)
		{
			if (auto $phongtint = material->FindVar("$phongtint", nullptr, false))
				$phongtint->SetVecValue(Color::TOFLOAT(color.r), Color::TOFLOAT(color.g), Color::TOFLOAT(color.b));
			if (auto $envmaptint = material->FindVar("$envmaptint", nullptr, false))
				$envmaptint->SetVecValue(Color::TOFLOAT(color.r), Color::TOFLOAT(color.g), Color::TOFLOAT(color.b));
		}
		I::RenderView->SetColorModulation(Color::TOFLOAT(color.r), Color::TOFLOAT(color.g), Color::TOFLOAT(color.b));
		I::RenderView->SetBlend(Color::TOFLOAT(color.a));
	}
	else
	{
		I::RenderView->SetColorModulation(1.f, 1.f, 1.f);
		I::RenderView->SetBlend(1.f);
	}
}



IMaterial* CMaterials::GetMaterial(std::string sName)
{
	if (sName == "Original")
		return nullptr;

	const auto cham = mChamMaterials.find(sName);
	if (cham != mChamMaterials.end())
		return cham->second.pMaterial;
	
	return nullptr;
}

std::string CMaterials::GetVMT(std::string sName)
{
	const auto cham = mChamMaterials.find(sName);
	if (cham != mChamMaterials.end())
		return cham->second.sVMT;

	return "";
}

void CMaterials::AddMaterial(std::string sName)
{
	if (sName == "Original" || std::filesystem::exists(MaterialFolder + "\\" + sName + ".vmt"))
		return;

	const auto cham = mChamMaterials.find(sName);
	if (cham != mChamMaterials.end())
		return;

	Material_t mat = {};
	mat.sVMT = "\"VertexLitGeneric\"\n{\n\t\n}";

	const auto kv = new KeyValues(sName.c_str());
	g_KeyValUtils.LoadFromBuffer(kv, sName.c_str(), mat.sVMT.c_str());
	mat.pMaterial = CreateNRef(std::format("m_pMat%s", sName).c_str(), kv);

	mChamMaterials[sName] = mat;

	std::ofstream outStream(MaterialFolder + "\\" + sName + ".vmt");
	outStream << mat.sVMT;
	outStream.close();
}

void CMaterials::EditMaterial(std::string sName, std::string sVMT)
{
	if (!std::filesystem::exists(MaterialFolder + "\\" + sName + ".vmt"))
		return;

	const auto cham = mChamMaterials.find(sName);
	if (cham != mChamMaterials.end())
	{
		if (cham->second.bLocked)
			return;

		cham->second.sVMT = sVMT;

		const auto kv = new KeyValues(sName.c_str());
		g_KeyValUtils.LoadFromBuffer(kv, sName.c_str(), sVMT.c_str());
		cham->second.pMaterial = CreateNRef(std::format("m_pMat%s", sName).c_str(), kv);

		std::ofstream outStream(MaterialFolder + "\\" + sName + ".vmt");
		outStream << sVMT;
		outStream.close();
	}
}

void CMaterials::RemoveMaterial(std::string sName)
{
	if (!std::filesystem::exists(MaterialFolder + "\\" + sName + ".vmt"))
		return;

	const auto cham = mChamMaterials.find(sName);
	if (cham != mChamMaterials.end())
	{
		if (cham->second.bLocked)
			return;

		if (cham->second.pMaterial)
		{
			cham->second.pMaterial->DecrementReferenceCount();
			cham->second.pMaterial->DeleteIfUnreferenced();
			cham->second.pMaterial = nullptr;
		}

		mChamMaterials.erase(cham);
	}

	std::filesystem::remove(MaterialFolder + "\\" + sName + ".vmt");

	auto removeFromVar = [sName](std::vector<std::string>& var)
		{
			for (auto it = var.begin(); it != var.end();)
			{
				if (*it == sName)
					it = var.erase(it);
				else
					++it;
			}
		};
	removeFromVar(Vars::Chams::Friendly::Chams.Value.VisibleMaterial);
	removeFromVar(Vars::Chams::Friendly::Chams.Value.OccludedMaterial);
	removeFromVar(Vars::Chams::Enemy::Chams.Value.VisibleMaterial);
	removeFromVar(Vars::Chams::Enemy::Chams.Value.OccludedMaterial);
	removeFromVar(Vars::Chams::World::Chams.Value.VisibleMaterial);
	removeFromVar(Vars::Chams::World::Chams.Value.OccludedMaterial);
	removeFromVar(Vars::Chams::Backtrack::Chams.Value.VisibleMaterial);
	removeFromVar(Vars::Chams::FakeAngle::Chams.Value.VisibleMaterial);
	removeFromVar(Vars::Chams::Viewmodel::Chams.Value.VisibleMaterial);
}