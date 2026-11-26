#pragma once

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"

namespace PieOrdinaryCraft
{
inline bool IsRequested()
{
#if WITH_EDITOR
    static const bool Enabled =
        FParse::Param(FCommandLine::Get(), TEXT("DDS2PIEInventoryTransfers")) &&
        FParse::Param(FCommandLine::Get(), TEXT("DDS2PIEOrdinaryCraft"));
    return Enabled;
#else
    return false;
#endif
}

inline bool IsEnabled(const AActor* Actor)
{
    const UWorld* World = Actor ? Actor->GetWorld() : nullptr;
    return IsRequested() && World && World->WorldType == EWorldType::PIE &&
        World->GetNetMode() == NM_Standalone && Actor->HasAuthority();
}
}
