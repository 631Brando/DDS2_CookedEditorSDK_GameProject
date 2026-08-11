#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VirtualCursorFunctionLibrary.generated.h"

class APlayerController;

UCLASS(Blueprintable)
class GAMEPADVIRTUALCURSOR_API UVirtualCursorFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UVirtualCursorFunctionLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCursorOverInteractableWidget();
    
    UFUNCTION(BlueprintCallable)
    static void EnableGamepadCursor(APlayerController* PlayerController, bool UseLeftStick, bool ShowMouseCursor, bool InputModeUIOnly);
    
    UFUNCTION(BlueprintCallable)
    static void DisableGamepadCursor(APlayerController* PlayerController, bool HideMouseCursor, bool InputModeGameOnly);
    
};

