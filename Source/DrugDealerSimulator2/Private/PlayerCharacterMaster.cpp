#include "PlayerCharacterMaster.h"
#include "GameFramework/PlayerController.h"

APlayerCharacterMaster::APlayerCharacterMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UTexture2D* APlayerCharacterMaster::CreateTextureFromBuffer(const TArray<uint8>& Buffer, int32 Width, int32 Height) {
    return NULL;
}

TArray<uint8> APlayerCharacterMaster::ConvertColorsToBytes(TArray<FColor> Colors, int32 Size) {
    return TArray<uint8>();
}

// modkit: see header comment - restores basic mouse look for editor/PIE testing. Polls raw mouse delta
// directly off the controller rather than binding through an Input Action/Mapping Context, so it doesn't
// depend on this project's Enhanced Input setup being wired correctly (or at all) for this class.
void APlayerCharacterMaster::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        float MouseDeltaX = 0.0f;
        float MouseDeltaY = 0.0f;
        PC->GetInputMouseDelta(MouseDeltaX, MouseDeltaY);

        AddControllerYawInput(MouseDeltaX * ModKitMouseSensitivity);
        // modkit: raw mouse Y delta is positive moving the mouse UP, but pitch input needs to be negative to
        // look up (screen-space Y vs. rotation direction are opposite) - the stock templates handle this via
        // a -1.0 scale on their "LookUp" axis mapping; negate it directly here since this reads raw deltas.
        AddControllerPitchInput(-MouseDeltaY * ModKitMouseSensitivity);
    }
}


