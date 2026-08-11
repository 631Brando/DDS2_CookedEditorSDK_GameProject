#include "StreamlineLibraryDeepDVC.h"

UStreamlineLibraryDeepDVC::UStreamlineLibraryDeepDVC() {
}

void UStreamlineLibraryDeepDVC::SetDeepDVCSaturationBoost(float Intensity) {
}

void UStreamlineLibraryDeepDVC::SetDeepDVCMode(UStreamlineDeepDVCMode DeepDVCMode) {
}

void UStreamlineLibraryDeepDVC::SetDeepDVCIntensity(float Intensity) {
}

UStreamlineFeatureSupport UStreamlineLibraryDeepDVC::QueryDeepDVCSupport() {
    return UStreamlineFeatureSupport::Supported;
}

bool UStreamlineLibraryDeepDVC::IsDeepDVCSupported() {
    return false;
}

bool UStreamlineLibraryDeepDVC::IsDeepDVCModeSupported(UStreamlineDeepDVCMode DeepDVCMode) {
    return false;
}

TArray<UStreamlineDeepDVCMode> UStreamlineLibraryDeepDVC::GetSupportedDeepDVCModes() {
    return TArray<UStreamlineDeepDVCMode>();
}

UStreamlineDeepDVCMode UStreamlineLibraryDeepDVC::GetDefaultDeepDVCMode() {
    return UStreamlineDeepDVCMode::Off;
}

float UStreamlineLibraryDeepDVC::GetDeepDVCSaturationBoost() {
    return 0.0f;
}

UStreamlineDeepDVCMode UStreamlineLibraryDeepDVC::GetDeepDVCMode() {
    return UStreamlineDeepDVCMode::Off;
}

float UStreamlineLibraryDeepDVC::GetDeepDVCIntensity() {
    return 0.0f;
}


