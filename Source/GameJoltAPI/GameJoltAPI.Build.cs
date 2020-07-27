// Copyright by Free2Play-Entertainment (2020)

using UnrealBuildTool;

public class GameJoltAPI : ModuleRules
{
    public GameJoltAPI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "HTTP",
                "JSONQuery"
            }
            );
            

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore"
            }
            );
    }
}
