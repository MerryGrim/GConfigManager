// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GConfigData.h"
#include "Kismet/GameplayStatics.h"
#include "GConfigManagerBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UGConfigManagerBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "GConfigManager sample test testing"), Category = "GConfigManagerTesting")
	static float GConfigManagerSampleFunction(float Param);

	UFUNCTION(BlueprintCallable, Category="GConfig Render")
	static void SetGIMethod(EGlobalIllumination  GIMethod, bool SaveConfig);

	UFUNCTION(BlueprintCallable, Category = "GConfig Render")
	static void SetReflectionMethod(EReflection  ReflectionMethod, bool SaveConfig);

	UFUNCTION(BlueprintCallable, Category = "GConfig Render")
	static void SetShadowMethod(EShadowMap  ShadowMapMethod, bool SaveConfig);

	UFUNCTION(BlueprintCallable, Category = "GConfig Render")
	static void SetAAMethod(EAntialiasing AntialiasingMethod, bool SaveConfig);

	UFUNCTION(BlueprintCallable, Category = "GConfig Render")
	static void SetMSAAQuality(EMSAAQuality  MSAAQuality, bool SaveConfig);

	UFUNCTION(BlueprintCallable, Category = "GraphicsRHIManager")
    static void SetGraphicsRHI(EGraphicsRHI GraphicsRHI);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GraphicsRHIManager")
    static EGraphicsRHI GetCurrentGraphicsRHI();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Render Settings")
	static EGlobalIllumination GetGIMethod();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Render Settings")
	static EReflection GetReflectionMethod();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Render Settings")
	static EShadowMap GetShadowMethod();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Render Settings")
	static EAntialiasing GetAAMethod();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Render Settings")
	static int GetMSAAQuality();
	
};
