#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Character.h"
#include "PlayerCharacterMaster.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API APlayerCharacterMaster : public ACharacter {
    GENERATED_BODY()
public:
    APlayerCharacterMaster(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static UTexture2D* CreateTextureFromBuffer(const TArray<uint8>& Buffer, int32 Width, int32 Height);
    
    UFUNCTION(BlueprintCallable)
    TArray<uint8> ConvertColorsToBytes(TArray<FColor> Colors, int32 Size);

    virtual void Tick(float DeltaSeconds) override;

    // modkit: DDS2's real mouse-look handling lives only in the shipped game's compiled binary - this
    // project's PlayerCharacterMaster.cpp is an SDK-dumped stub with no implementation, so look input does
    // nothing in this editor's PIE sessions. This restores basic mouse look for testing (see Tick()).
    // Tune to taste; not meant to match the real game's exact feel.
    //
    // Deliberately NOT a UPROPERTY: this class has cooked instances (e.g. BP_PlayerCharacter) with a fixed,
    // baked unversioned-property layout. Adding a reflected property here shifts that layout and desyncs it
    // from what's actually on disk - the loader reads the cooked data 4 bytes (this float) misaligned, which
    // showed up as "cooked asset schema mismatch" / "Serial size mismatch: Expected read size 626, Actual
    // read size 618" on BP_PlayerCharacter, cascading into a fatal crash reading garbage as a TArray size
    // while deserializing its CapsuleComponent. A plain (non-reflected) member doesn't affect serialization
    // at all, so it's safe to add here the same way BlockInventoryUpdate/PropertyConcealedSlots were added to
    // InventoryComponent without incident.
    float ModKitMouseSensitivity = 1.0f;

};

