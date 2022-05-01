// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGlobalIllumination : uint8
{
    GI_NONE	        UMETA(DisplayName = "None"),
    GI_LUMEN	    UMETA(DisplayName = "Lumen"),
    GI_SCREENSPACE	UMETA(DisplayName = "Screen Space"),
    GI_RT           UMETA(DisplayName = "Ray Trace")
};

UENUM(BlueprintType)
enum class EReflection : uint8
{
    RF_NONE	        UMETA(DisplayName = "None"),
    RF_LUMEN	    UMETA(DisplayName = "Lumen"),
    RF_SCREENSPACE	UMETA(DisplayName = "Screen Space"),
    RF_RT           UMETA(DisplayName = "Ray Trace")
};

UENUM(BlueprintType)
enum class EShadowMap : uint8
{
    SD_SHADOWMAP	        UMETA(DisplayName = "Shadow Map"),
    SD_VIRTUALSHADOWMAP	    UMETA(DisplayName = "Virtual Shadow Map")
};

UENUM(BlueprintType)
enum class EAntialiasing : uint8
{
    AA_NONE	        UMETA(DisplayName = "None"),
    AA_FXAA	        UMETA(DisplayName = "FXAA"),
    AA_TAA          UMETA(DisplayName = "TAA"),
    AA_MSAA         UMETA(DisplayName = "MSAA"),
    AA_TSR          UMETA(DisplayName = "TSR")
};

UENUM(BlueprintType)
enum class EMSAAQuality : uint8
{
    MSAA_NONE	        UMETA(DisplayName = "None"),
    MSAA_2X				UMETA(DisplayName = "2X"),
    MSAA_4X				UMETA(DisplayName = "4X"),
    MSAA_8X				UMETA(DisplayName = "8X")
};

UENUM(BlueprintType)
enum class EGraphicsRHI : uint8
{
    RHI_DX11	UMETA(DisplayName = "DirectX 11"),
    RHI_DX12	UMETA(DisplayName = "DirectX 12"),
    RHI_VULKAN	UMETA(DisplayName = "Vulkan")
};
