// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TeamProject : ModuleRules
{
	public TeamProject(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "AIModule",
			//"Slate",
			//"SlateCore",
			"Niagara",
            "UMG"		// not used the UMG module in unreal5?
		});

        PublicIncludePaths.Add(ModuleDirectory);

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
    }
}
