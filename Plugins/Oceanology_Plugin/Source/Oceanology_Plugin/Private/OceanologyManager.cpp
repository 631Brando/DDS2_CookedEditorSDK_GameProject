#include "OceanologyManager.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "OceanologyHeightmapComponent.h"
#include "OceanologyVirtualTextureComponent.h"

AOceanologyManager::AOceanologyManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bEnableAutoLODGeneration = false;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    this->DefaultSceneRoot = (USceneComponent*)RootComponent;
    this->HeightmapVirtualTextureComponent = CreateDefaultSubobject<UOceanologyVirtualTextureComponent>(TEXT("HeightmapVirtualTexture"));
    this->HeightmapComponent = CreateDefaultSubobject<UOceanologyHeightmapComponent>(TEXT("Heightmap"));
    this->bSetAllBoundsButton = false;
    this->Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Bounds"));
    this->Box->SetupAttachment(RootComponent);
    this->HeightmapVirtualTextureComponent->SetupAttachment(RootComponent);
}


