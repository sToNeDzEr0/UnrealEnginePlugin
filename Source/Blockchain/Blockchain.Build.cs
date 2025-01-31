// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Blockchain : ModuleRules
{
	public Blockchain(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;		
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Libbitcoin"			}
			);

		bUseRTTI = true;
		bEnableExceptions = true;
		bEnableUndefinedIdentifierWarnings = true;
	}
}
