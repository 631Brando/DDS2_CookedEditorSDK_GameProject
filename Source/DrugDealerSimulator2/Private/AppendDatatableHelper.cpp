#include "AppendDatatableHelper.h"
#include "Engine/DataTable.h"

int32 UAppendDatatableHelper::AppendDataTables(UDataTable* TargetDataTable, UDataTable* SourceDataTable, bool bOverwriteExisting)
{
    if (!TargetDataTable || !SourceDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("AppendDataTables failed: Target or Source DataTable is null."));
        return 0;
    }

    // Check row structure compatibility
    const UScriptStruct* TargetRowStruct = TargetDataTable->GetRowStruct();
    const UScriptStruct* SourceRowStruct = SourceDataTable->GetRowStruct();

    if (!TargetRowStruct || !SourceRowStruct || TargetRowStruct != SourceRowStruct)
    {
        UE_LOG(LogTemp, Error, TEXT("AppendDataTables failed: Row structure mismatch between Target and Source DataTables."));
        return 0;
    }

    // Get all rows from the Source DataTable
    TArray<FName> SourceRowNames = SourceDataTable->GetRowNames();
    int32 RowsAppended = 0;

    for (const FName& RowName : SourceRowNames)
    {
        // Get the source row data
        const uint8* SourceRowData = SourceDataTable->FindRowUnchecked(RowName);
        if (!SourceRowData)
        {
            UE_LOG(LogTemp, Warning, TEXT("Source row '%s' could not be found in the Source DataTable."), *RowName.ToString());
            continue;
        }

        // Check if the row already exists in the target DataTable
        if (TargetDataTable->FindRowUnchecked(RowName))
        {
            if (bOverwriteExisting)
            {
                TargetDataTable->RemoveRow(RowName); // Remove the existing row
                UE_LOG(LogTemp, Warning, TEXT("Overwriting row '%s' in the Target DataTable."), *RowName.ToString());
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Row '%s' already exists in the Target DataTable and was skipped."), *RowName.ToString());
                continue;
            }
        }

        // Add the source row to the target DataTable
        TargetDataTable->AddRow(RowName, *(const FTableRowBase*)SourceRowData);
        RowsAppended++;
    }

    UE_LOG(LogTemp, Log, TEXT("AppendDataTables completed: %d rows appended."), RowsAppended);
    return RowsAppended;
}
