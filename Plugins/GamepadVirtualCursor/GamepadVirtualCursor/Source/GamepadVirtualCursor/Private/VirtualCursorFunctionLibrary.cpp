#include "VirtualCursorFunctionLibrary.h"

UVirtualCursorFunctionLibrary::UVirtualCursorFunctionLibrary() {
}

bool UVirtualCursorFunctionLibrary::IsCursorOverInteractableWidget() {
    return false;
}

void UVirtualCursorFunctionLibrary::EnableGamepadCursor(APlayerController* PlayerController, bool UseLeftStick, bool ShowMouseCursor, bool InputModeUIOnly) {
}

void UVirtualCursorFunctionLibrary::DisableGamepadCursor(APlayerController* PlayerController, bool HideMouseCursor, bool InputModeGameOnly) {
}


