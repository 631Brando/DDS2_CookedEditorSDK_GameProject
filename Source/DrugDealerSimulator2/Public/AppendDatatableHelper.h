#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AppendDatatableHelper.generated.h"

class UDataTable;

UCLASS()
class DRUGDEALERSIMULATOR2_API UAppendDatatableHelper : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Appends rows from the Source DataTable to the Target DataTable.
     * @param TargetDataTable - The DataTable to which rows will be added.
     * @param SourceDataTable - The DataTable from which rows will be copied.
     * @param bOverwriteExisting - Whether to overwrite existing rows in the Target DataTable if they have the same name.
     * @return The number of rows successfully appended.
     */
    UFUNCTION(BlueprintCallable, Category = "DataTable")
    static int32 AppendDataTables(UDataTable* TargetDataTable, UDataTable* SourceDataTable, bool bOverwriteExisting = false);
};
