using UnrealBuildTool;

public class DrugDealerSimulator2EditorTarget : TargetRules {
	public DrugDealerSimulator2EditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"DrugDealerSimulator2",
		});
	}
}
