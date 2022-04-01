// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Team_3_Project : ModuleRules
{
	public Team_3_Project(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
