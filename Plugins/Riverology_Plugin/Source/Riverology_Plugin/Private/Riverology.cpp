#include "Riverology.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"

ARiverology::ARiverology(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    this->SplineComponent->SetupAttachment(RootComponent);
}


