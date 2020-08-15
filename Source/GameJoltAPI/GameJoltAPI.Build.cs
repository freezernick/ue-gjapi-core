// Copyright by Free2Play-Entertainment (2020)

using UnrealBuildTool;
using System.IO;

public class GameJoltAPI : ModuleRules
{
    public GameJoltAPI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private/AsyncActions"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core"
            }
            );
            

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "HTTP",
                "JSON"
            }
            );
    }
}
