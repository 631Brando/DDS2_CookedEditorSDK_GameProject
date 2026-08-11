#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DdsSessionPropertyKeyPair.h"
#include "SaleCalendarData.h"
#include "SortSaleCalendarDataPredicateDelegate.h"
#include "BlueprintCPPHelperLibrary.generated.h"

UCLASS(Blueprintable)
class DRUGDEALERSIMULATOR2_API UBlueprintCPPHelperLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBlueprintCPPHelperLibrary();

private:
    UFUNCTION(BlueprintCallable)
    static TArray<FSaleCalendarData> SortSaleCalendarData(const TArray<FSaleCalendarData>& SaleCalendar, FSortSaleCalendarDataPredicate Predicate);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveArrayToFile(const TArray<FString>& StringArray, const FString& Filename);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> ReadPathFolders(const FString& DirectoryPath);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDdsSessionPropertyKeyPair MakeDdsLiteralSessionPropertyString(FName Key, const FString& Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDdsSessionPropertyKeyPair MakeDdsLiteralSessionPropertyInt(FName Key, int32 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsWithEditor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetGPUBrandName();
    
    UFUNCTION(BlueprintCallable)
    static FString GetAppVersion();
    
    UFUNCTION(BlueprintCallable)
    static FString GenerateSafeFileName(FText InputText);
    
    UFUNCTION(BlueprintCallable)
    static FString EncodeSessionPassword(FText Password);
    
    UFUNCTION(BlueprintCallable)
    static TArray<uint8> ConvertColorsToBytes(TArray<FColor> Colors, int32 Size);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 CompareFText(const FText& A, const FText& B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 CompareFString(const FString& A, const FString& B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 CompareFName(const FName& A, const FName& B);
    
};

