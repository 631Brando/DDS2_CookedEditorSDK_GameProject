#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldTimeManager.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DRUGDEALERSIMULATOR2_API UWorldTimeManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurDayPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 CurDayInt;
    
    UWorldTimeManager(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void StartNewDay();
    
    UFUNCTION(BlueprintCallable)
    void SkipTime(int32 Days, int32 Hours, int32 Minutes);
    
    UFUNCTION(BlueprintCallable)
    void SetGlobalTimeMultiplier(float NewMultiplier);
    
    UFUNCTION(BlueprintCallable)
    void SetClockTime(int32 Hour, int32 Minute, int32 Day);
    
    UFUNCTION(BlueprintCallable)
    float GetCurTimePercent();
    
    UFUNCTION(BlueprintCallable)
    void GetCurClockTime(int32& CurHour, int32& CurMinute, int32& Day);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DayChanged(int32 NewDayIndex);
    
};

