#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FGearRewindReplayState.h"
#include "FGearRewindReplay.generated.h"

class AFGearVehicle;

UCLASS(Blueprintable)
class FGEARPLUGIN_API AFGearRewindReplay : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AFGearVehicle*> mVehicleList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mStateSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mRewindPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mReplayPause;
    
public:
    AFGearRewindReplay(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setReplayFrames(int32 Count);
    
    UFUNCTION(BlueprintCallable)
    void Rewind(bool resetIndex);
    
    UFUNCTION(BlueprintCallable)
    void replay(bool resetIndex);
    
    UFUNCTION(BlueprintCallable)
    void Play();
    
    UFUNCTION(BlueprintCallable)
    FGearRewindReplayState GetState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getProgressValue() const;
    
};

