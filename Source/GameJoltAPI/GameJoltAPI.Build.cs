// Copyright by Nick Lamprecht (2020-2023)

using UnrealBuildTool;
using System.IO;

public class GameJoltAPI : ModuleRules
{
    public GameJoltAPI(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public/AsyncActions"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "HTTP",
                "Json"
            }
            );
            

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine"
            }
            );
    }
}
