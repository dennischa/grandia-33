// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Grandia : ModuleRules
{
	public Grandia(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] {"Grandia"});

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "GameplayTasks" });
    }
}
