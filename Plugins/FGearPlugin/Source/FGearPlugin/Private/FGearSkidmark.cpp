#include "FGearSkidmark.h"
#include "ProceduralMeshComponent.h"

AFGearSkidmark::AFGearSkidmark(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("SkidmarkMesh"));
}


