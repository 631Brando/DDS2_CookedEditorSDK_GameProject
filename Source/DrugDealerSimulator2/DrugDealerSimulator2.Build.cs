using UnrealBuildTool;

public class DrugDealerSimulator2 : ModuleRules {
    public DrugDealerSimulator2(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "EnhancedInput",
            "GameFeatures",
            "Json",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "SlateCore",
            "UMG",
        });
    }
}
