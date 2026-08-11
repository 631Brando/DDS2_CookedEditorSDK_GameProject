#pragma once
#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "DDS2_GameViewportClient.generated.h"

UCLASS(Blueprintable, NonTransient)
class DRUGDEALERSIMULATOR2_API UDDS2_GameViewportClient : public UGameViewportClient {
    GENERATED_BODY()
public:
    UDDS2_GameViewportClient();

};

