#if WITH_EDITOR && WITH_DEV_AUTOMATION_TESTS

#include "ContainerConfig.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "InventoryComponent.h"
#include "Misc/AutomationTest.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"
#include "Misc/ScopeExit.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FPieInventoryTransfersTest, "DDS2.SDK.PIE.OrdinaryInventoryTransfers",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPieInventoryTransfersTest::RunTest(const FString& Parameters)
{
    const bool Enabled = FParse::Param(FCommandLine::Get(), TEXT("DDS2PIEInventoryTransfers"));

    UWorld* World = UWorld::CreateWorld(EWorldType::PIE, false);
    if (!TestNotNull(TEXT("Transient PIE world"), World))
    {
        return false;
    }
    ON_SCOPE_EXIT { World->DestroyWorld(false); };

    AActor* Owner = World->SpawnActor<AActor>();
    if (!TestNotNull(TEXT("Authoritative fixture owner"), Owner))
    {
        return false;
    }

    UDataTable* Configs = NewObject<UDataTable>(Owner);
    Configs->RowStruct = FContainerConfig::StaticStruct();
    FContainerConfig Config;
    Config.BaseContainerSize = 2;
    Config.BaseConcealedSlots = 0;
    Configs->AddRow(TEXT("TEST"), Config);
    UDataTable* Items = NewObject<UDataTable>(Owner);
    Items->RowStruct = FItemData::StaticStruct();
    FItemData Row;
    Row.ItemCategory = EItemCategory::Miscellaneous;
    Row.InventoryMaxStack = 3;
    Items->AddRow(TEXT("FIXTURE"), Row);

    UInventoryComponent* Source = NewObject<UInventoryComponent>(Owner);
    UInventoryComponent* Target = NewObject<UInventoryComponent>(Owner);
    Target->IsPlayerInventory = true;
    for (UInventoryComponent* Inventory : {Source, Target})
    {
        Inventory->ItemDatabase = Items;
        Inventory->ConfigDatabase = Configs;
        Inventory->InventoryConfig = TEXT("TEST");
    }

    FInventoryObjectData Stack;
    Stack.ItemId = TEXT("FIXTURE");
    Stack.CurStack = 2;
    Stack.CurHealth = 37.5f;
    Stack.CurUsesLeft = 4;
    Stack.ItemTimeoutStatus = TEXT("fixture");
    int32 Left = INDEX_NONE;
    Source->AddSpecificItem(Stack, false, Left, Stack.CurStack, 0);
    if (!Enabled)
    {
        TestTrue(TEXT("The default SDK leaves inventory untouched"),
            Source->StoredItems.IsEmpty() && Source->AssignedIndexes.IsEmpty());
        TestEqual(TEXT("The default SDK keeps the stub grid"), Source->GetInventoryLenght(), 0);
        return true;
    }
    if (!TestEqual(TEXT("Seed one whole stack"), Left, 0))
    {
        return false;
    }
    const FGuid SourceGuid = Source->AssignedIndexes.FindRef(0);
    Stack = Source->StoredItems.FindRef(SourceGuid);
    TestFalse(TEXT("A split cannot pass the widget's source gate"),
        Source->CheckStackQuantityExists(SourceGuid, 1));
    TestFalse(TEXT("A split cannot debit the source"), Source->RemoveStackQuantity(SourceGuid, 1));
    TestTrue(TEXT("The full stack passes the source gate"), Source->CheckStackQuantityExists(SourceGuid, 2));

    Target->AddSpecificItem(Stack, true, Left, 2, 1);
    TestEqual(TEXT("Whole-stack preview"), Left, 0);
    TestTrue(TEXT("Preview leaves both destination maps empty"),
        Target->StoredItems.IsEmpty() && Target->AssignedIndexes.IsEmpty());
    Target->AddSpecificItem(Stack, false, Left, 2, 1);
    if (!TestEqual(TEXT("Whole-stack insertion"), Left, 0))
    {
        return false;
    }
    TestTrue(TEXT("Exact source debit"), Source->RemoveStackQuantity(SourceGuid, 2));
    TestTrue(TEXT("Source maps empty"), Source->StoredItems.IsEmpty() && Source->AssignedIndexes.IsEmpty());
    const FGuid ReceivedGuid = Target->AssignedIndexes.FindRef(1);
    const FInventoryObjectData Received = Target->StoredItems.FindRef(ReceivedGuid);
    TestTrue(TEXT("Insertion creates a different GUID"), ReceivedGuid.IsValid() && ReceivedGuid != SourceGuid);
    TestEqual(TEXT("Received quantity"), Received.CurStack, 2);
    TestEqual(TEXT("Health preserved"), Received.CurHealth, Stack.CurHealth);
    TestEqual(TEXT("Uses preserved"), Received.CurUsesLeft, Stack.CurUsesLeft);
    TestEqual(TEXT("Timeout preserved"), Received.ItemTimeoutStatus, Stack.ItemTimeoutStatus);

    Target->AddSpecificItem(Stack, false, Left, 2, 1);
    TestEqual(TEXT("A stack that cannot fit is refused in full"), Left, 2);
    TestEqual(TEXT("Refusal preserves the occupied cell"), Target->StoredItems.FindRef(ReceivedGuid).CurStack, 2);
    Stack.CurStack = 1;
    Target->AddSpecificItem(Stack, false, Left, 1, 1);
    TestEqual(TEXT("A compatible whole stack that fits is merged"), Left, 0);

    bool CanMove = false;
    Target->MoveItem(ReceivedGuid, 0, 3, CanMove, Left);
    TestTrue(TEXT("Move to a free slot"), CanMove);
    TArray<FInventoryGridData> Grid;
    Target->GetInventoryGrid(Grid);
    if (!TestEqual(TEXT("The grid projects both cells"), Grid.Num(), 2))
    {
        return false;
    }
    TestTrue(TEXT("The move preserves GUID and count"), Grid[0].Occupied &&
        Grid[0].ObjectData.StackGuid == ReceivedGuid && Grid[0].ObjectData.CurStack == 3);
    TestTrue(TEXT("The free cell retains its index"), !Grid[1].Occupied && Grid[1].ObjectData.IndexPlacement == 1);
    return true;
}

#endif
