// Copyright Epic Games, Inc. All Rights Reserved.

#include "GConfigManagerBPLibrary.h"
#include "GConfigManager.h"


UGConfigManagerBPLibrary::UGConfigManagerBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UGConfigManagerBPLibrary::GConfigManagerSampleFunction(float Param)
{
	return -1;
}

void UGConfigManagerBPLibrary::SetGIMethod(EGlobalIllumination GIMethod, bool SaveConfig)
{
	UWorld* world = GEngine->GameViewport->GetWorld();
	FString Index(TEXT("0"));
	FString DefaultGlobalIllumination;

	if (GIMethod == EGlobalIllumination::GI_NONE)
	{
		Index = TEXT("0");
		GEngine->Exec(world->GetWorld(), TEXT("r.DynamicGlobalIlluminationMethod 0"));
	}
	else if (GIMethod == EGlobalIllumination::GI_LUMEN)
	{
		Index = TEXT("1");
		GEngine->Exec(world->GetWorld(), TEXT("r.DynamicGlobalIlluminationMethod 1"));
	}
	else if (GIMethod == EGlobalIllumination::GI_SCREENSPACE)
	{
		Index = TEXT("2");
		GEngine->Exec(world->GetWorld(), TEXT("r.DynamicGlobalIlluminationMethod 2"));
	}
	else
	{
		Index = TEXT("3");
		GEngine->Exec(world->GetWorld(), TEXT("r.DynamicGlobalIlluminationMethod 3"));
	}

	if (SaveConfig)
	{
		GConfig->GetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.DynamicGlobalIlluminationMethod"), DefaultGlobalIllumination, GEngineIni);

		GConfig->SetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.DynamicGlobalIlluminationMethod"), *Index, GEngineIni);
		GConfig->Flush(true, GEngineIni);
	}

	if (GIMethod != EGlobalIllumination::GI_LUMEN || GetReflectionMethod() == EReflection::RF_LUMEN)
	{
		SetReflectionMethod(EReflection::RF_SCREENSPACE, true);
	}
	
}

void UGConfigManagerBPLibrary::SetReflectionMethod(EReflection ReflectionMethod, bool SaveConfig)
{
	UWorld* world = GEngine->GameViewport->GetWorld();
	FString Index(TEXT("0"));
	FString DefaultReflectionMethod;

	if (ReflectionMethod == EReflection::RF_NONE)
	{
		Index = TEXT("0");
		GEngine->Exec(world->GetWorld(), TEXT("r.ReflectionMethod 0"));
	}
	else if (ReflectionMethod == EReflection::RF_LUMEN)
	{
		if (GetGIMethod() == EGlobalIllumination::GI_LUMEN)
		{
			Index = TEXT("1");
			GEngine->Exec(world->GetWorld(), TEXT("r.ReflectionMethod 1"));
		}
		else
		{
			Index = TEXT("2");
			GEngine->Exec(world->GetWorld(), TEXT("r.ReflectionMethod 2"));
		}
		
	}
	else if (ReflectionMethod == EReflection::RF_SCREENSPACE)
	{
		Index = TEXT("2");
		GEngine->Exec(world->GetWorld(), TEXT("r.ReflectionMethod 2"));
	}
	else
	{
		Index = TEXT("3");
		GEngine->Exec(world->GetWorld(), TEXT("r.ReflectionMethod 3"));
	}
	
	if (SaveConfig)
	{
		GConfig->GetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.ReflectionMethod"), DefaultReflectionMethod, GEngineIni);

		GConfig->SetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.ReflectionMethod"), *Index, GEngineIni);
		GConfig->Flush(true, GEngineIni);
	}
	
}

void UGConfigManagerBPLibrary::SetShadowMethod(EShadowMap ShadowMapMethod, bool SaveConfig)
{
	UWorld* world = GEngine->GameViewport->GetWorld();
	FString Index(TEXT("0"));
	FString DefaultShadowMapMethod;

	if (ShadowMapMethod == EShadowMap::SD_SHADOWMAP)
	{
		Index = TEXT("0");
		GEngine->Exec(world->GetWorld(), TEXT("r.Shadow.Virtual.Enable 0"));
	}
	else
	{
		Index = TEXT("1");
		GEngine->Exec(world->GetWorld(), TEXT("r.Shadow.Virtual.Enable 1"));
	}
	
	if (SaveConfig)
	{
		GConfig->GetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.Shadow.Virtual.Enable"), DefaultShadowMapMethod, GEngineIni);

		GConfig->SetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.Shadow.Virtual.Enable"), *Index, GEngineIni);
		GConfig->Flush(true, GEngineIni);
	}
	
}

void UGConfigManagerBPLibrary::SetAAMethod(EAntialiasing AntialiasingMethod, bool SaveConfig)
{
	UWorld* world = GEngine->GameViewport->GetWorld();
	FString Index(TEXT("0"));
	FString DefaultAAMethod;

	if (AntialiasingMethod == EAntialiasing::AA_NONE)
	{
		Index = TEXT("0");
		GEngine->Exec(world->GetWorld(), TEXT("r.AntiAliasingMethod 0"));
	}
	else if (AntialiasingMethod == EAntialiasing::AA_FXAA)
	{
		Index = TEXT("1");
		GEngine->Exec(world->GetWorld(), TEXT("r.AntiAliasingMethod 1"));
	}
	else if (AntialiasingMethod == EAntialiasing::AA_TAA)
	{
		Index = TEXT("2");
		GEngine->Exec(world->GetWorld(), TEXT("r.AntiAliasingMethod 2"));
	}
	else if (AntialiasingMethod == EAntialiasing::AA_MSAA)
	{
		Index = TEXT("3");
		GEngine->Exec(world->GetWorld(), TEXT("r.AntiAliasingMethod 3"));
	}
	else
	{
		Index = TEXT("4");
		GEngine->Exec(world->GetWorld(), TEXT("r.AntiAliasingMethod 4"));
	}
	
	if (SaveConfig)
	{
		GConfig->GetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.AntiAliasingMethod"), DefaultAAMethod, GEngineIni);

		GConfig->SetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.AntiAliasingMethod"), *Index, GEngineIni);
		GConfig->Flush(true, GEngineIni);
	}
	
}

void UGConfigManagerBPLibrary::SetMSAAQuality(EMSAAQuality MSAAQuality, bool SaveConfig)
{
	UWorld* world = GEngine->GameViewport->GetWorld();
	FString Index(TEXT("0"));
	FString DefaultMSAAQuality;

	if (MSAAQuality == EMSAAQuality::MSAA_NONE)
	{
		Index = TEXT("0");
		GEngine->Exec(world->GetWorld(), TEXT("r.MSAACount 0"));
	}
	else if (MSAAQuality == EMSAAQuality::MSAA_2X)
	{
		Index = TEXT("2");
		GEngine->Exec(world->GetWorld(), TEXT("r.MSAACount 2"));
	}
	else if (MSAAQuality == EMSAAQuality::MSAA_4X)
	{
		Index = TEXT("4");
		GEngine->Exec(world->GetWorld(), TEXT("r.MSAACount 4"));
	}
	else
	{
		Index = TEXT("8");
		GEngine->Exec(world->GetWorld(), TEXT("r.MSAACount 8"));
	}
	
	if (SaveConfig)
	{
		GConfig->GetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.MSAACount"), DefaultMSAAQuality, GEngineIni);

		GConfig->SetString(TEXT("Script/Engine.RendererSettings"), TEXT("r.MSAACount"), *Index, GEngineIni);
		GConfig->Flush(true, GEngineIni);
	}
}

void UGConfigManagerBPLibrary::SetGraphicsRHI(EGraphicsRHI GraphicsRHI)
{
	FString TargetPlataform = UGameplayStatics::GetPlatformName();
	FString DefaultGraphicsRHI;
	FString RHI_DX11(TEXT("DefaultGraphicsRHI_DX11"));
	FString RHI_DX12(TEXT("DefaultGraphicsRHI_DX12"));
	FString RHI_VULKAN(TEXT("DefaultGraphicsRHI_Vulkan"));

	if (TargetPlataform == "Windows")
	{
		GConfig->GetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), DefaultGraphicsRHI, GEngineIni);
		switch (GraphicsRHI)
		{
		case EGraphicsRHI::RHI_DX11 :
			GConfig->SetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), *RHI_DX11, GEngineIni);
			GConfig->Flush(true, GEngineIni);
			return;

		case EGraphicsRHI::RHI_DX12 :
			GConfig->SetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), *RHI_DX12, GEngineIni);
			GConfig->Flush(true, GEngineIni);
			return;

		case EGraphicsRHI::RHI_VULKAN :
			GConfig->SetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), *RHI_VULKAN, GEngineIni);
			GConfig->Flush(true, GEngineIni);
			return;
		}
		
	}
}

EGraphicsRHI UGConfigManagerBPLibrary::GetCurrentGraphicsRHI()
{
	FString TargetPlataform = UGameplayStatics::GetPlatformName();
	FString DefaultGraphicsRHI;

	GConfig->GetString(TEXT("/Script/WindowsTargetPlatform.WindowsTargetSettings"), TEXT("DefaultGraphicsRHI"), DefaultGraphicsRHI, GEngineIni);

	if (DefaultGraphicsRHI == "DefaultGraphicsRHI_DX11")
	{
		return EGraphicsRHI::RHI_DX11;
	}
	else if (DefaultGraphicsRHI == "DefaultGraphicsRHI_DX12")
	{
		return EGraphicsRHI::RHI_DX12;
	}
	return EGraphicsRHI::RHI_VULKAN;
}

EGlobalIllumination UGConfigManagerBPLibrary::GetGIMethod()
{
	int Index = UKismetSystemLibrary::GetConsoleVariableIntValue("r.DynamicGlobalIlluminationMethod");
	
	switch (Index)
	{
	case 0 :
		return EGlobalIllumination::GI_NONE;

	case 1 :
		return EGlobalIllumination::GI_LUMEN;

	case 2 :
		return EGlobalIllumination::GI_SCREENSPACE;

	case 3 :
		return EGlobalIllumination::GI_RT;
	}
	
	return EGlobalIllumination::GI_NONE;
}

EReflection UGConfigManagerBPLibrary::GetReflectionMethod()
{
	int Index = UKismetSystemLibrary::GetConsoleVariableIntValue("r.ReflectionMethod");
	
	switch (Index)
	{
	case 0 :
		return EReflection::RF_NONE;

	case 1 :
		return EReflection::RF_LUMEN;

	case 2 :
		return EReflection::RF_SCREENSPACE;

	case 3 :
		return EReflection::RF_RT;
	}
	
	return EReflection::RF_NONE;
}

EShadowMap UGConfigManagerBPLibrary::GetShadowMethod()
{
	int Index = UKismetSystemLibrary::GetConsoleVariableIntValue("r.Shadow.Virtual.Enable");
	
	switch (Index)
	{
	case 0 :
		return EShadowMap::SD_SHADOWMAP;

	case 1 :
		return EShadowMap::SD_VIRTUALSHADOWMAP;
	}
	
	return EShadowMap::SD_SHADOWMAP;
}

EAntialiasing UGConfigManagerBPLibrary::GetAAMethod()
{
	int Index = UKismetSystemLibrary::GetConsoleVariableIntValue("r.AntiAliasingMethod");
	
	switch (Index)
	{
	case 0 :
		return EAntialiasing::AA_NONE;

	case 1 :
		return EAntialiasing::AA_FXAA;

	case 2 :
		return EAntialiasing::AA_TAA;

	case 3 :
		return EAntialiasing::AA_MSAA;
		
	case 4 :
		return EAntialiasing::AA_TSR;
	}
	
	return EAntialiasing::AA_NONE;
}

int UGConfigManagerBPLibrary::GetMSAAQuality()
{
	return UKismetSystemLibrary::GetConsoleVariableIntValue("r.MSAACount");
}

