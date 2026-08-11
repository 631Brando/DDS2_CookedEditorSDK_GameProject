#pragma once
#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "VGCursorLocalPlayerSubsystem.generated.h"

UCLASS(Blueprintable)
class GAMEPADVIRTUALCURSOR_API UVGCursorLocalPlayerSubsystem : public ULocalPlayerSubsystem {
    GENERATED_BODY()
public:
    UVGCursorLocalPlayerSubsystem();

};

