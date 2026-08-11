#include "WorldTimeManager.h"
#include "Net/UnrealNetwork.h"

UWorldTimeManager::UWorldTimeManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurDayPercent = 0.00f;
    this->CurDayInt = 1;
}

void UWorldTimeManager::StartNewDay() {
}

void UWorldTimeManager::SkipTime(int32 Days, int32 Hours, int32 Minutes) {
}

void UWorldTimeManager::SetGlobalTimeMultiplier(float NewMultiplier) {
}

void UWorldTimeManager::SetClockTime(int32 Hour, int32 Minute, int32 Day) {
}

float UWorldTimeManager::GetCurTimePercent() {
    return 0.0f;
}

void UWorldTimeManager::GetCurClockTime(int32& CurHour, int32& CurMinute, int32& Day) {
}


void UWorldTimeManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UWorldTimeManager, CurDayPercent);
    DOREPLIFETIME(UWorldTimeManager, CurDayInt);
}


