#include "FGearSpline.h"
#include "Components/SplineComponent.h"

AFGearSpline::AFGearSpline(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline Component"));
    this->mSplineComp = (USplineComponent*)RootComponent;
    this->mDebug = false;
    this->mDebugThickness = 3.00f;
    this->mDebugIterator = 3.00f;
}

FVector AFGearSpline::moveParam(float& P, float Distance) {
    return FVector{};
}

FVector AFGearSpline::getTangent(float P) const {
    return FVector{};
}

USplineComponent* AFGearSpline::getSpline() const {
    return NULL;
}

FVector AFGearSpline::getPoint(float P) const {
    return FVector{};
}

FVector AFGearSpline::getDirection(float P) const {
    return FVector{};
}

float AFGearSpline::getClosestParam(FVector P) const {
    return 0.0f;
}


