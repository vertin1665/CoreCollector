// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CoreCollector : ModuleRules
{
	public CoreCollector(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"CoreCollector",
			"CoreCollector/Variant_Platforming",
			"CoreCollector/Variant_Platforming/Animation",
			"CoreCollector/Variant_Combat",
			"CoreCollector/Variant_Combat/AI",
			"CoreCollector/Variant_Combat/Animation",
			"CoreCollector/Variant_Combat/Gameplay",
			"CoreCollector/Variant_Combat/Interfaces",
			"CoreCollector/Variant_Combat/UI",
			"CoreCollector/Variant_SideScrolling",
			"CoreCollector/Variant_SideScrolling/AI",
			"CoreCollector/Variant_SideScrolling/Gameplay",
			"CoreCollector/Variant_SideScrolling/Interfaces",
			"CoreCollector/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
