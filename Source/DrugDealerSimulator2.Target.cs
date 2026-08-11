using UnrealBuildTool;

public class DrugDealerSimulator2Target : TargetRules {
	public DrugDealerSimulator2Target(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"DrugDealerSimulator2",
		});
	}
}
