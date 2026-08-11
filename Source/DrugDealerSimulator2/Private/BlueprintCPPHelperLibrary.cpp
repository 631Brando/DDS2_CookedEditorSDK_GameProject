#include "BlueprintCPPHelperLibrary.h"

UBlueprintCPPHelperLibrary::UBlueprintCPPHelperLibrary() {
}

TArray<FSaleCalendarData> UBlueprintCPPHelperLibrary::SortSaleCalendarData(const TArray<FSaleCalendarData>& SaleCalendar, FSortSaleCalendarDataPredicate Predicate) {
    return TArray<FSaleCalendarData>();
}

bool UBlueprintCPPHelperLibrary::SaveArrayToFile(const TArray<FString>& StringArray, const FString& Filename) {
    return false;
}

TArray<FString> UBlueprintCPPHelperLibrary::ReadPathFolders(const FString& DirectoryPath) {
    return TArray<FString>();
}

FDdsSessionPropertyKeyPair UBlueprintCPPHelperLibrary::MakeDdsLiteralSessionPropertyString(FName Key, const FString& Value) {
    return FDdsSessionPropertyKeyPair{};
}

FDdsSessionPropertyKeyPair UBlueprintCPPHelperLibrary::MakeDdsLiteralSessionPropertyInt(FName Key, int32 Value) {
    return FDdsSessionPropertyKeyPair{};
}

bool UBlueprintCPPHelperLibrary::IsWithEditor() {
    return false;
}

FString UBlueprintCPPHelperLibrary::GetGPUBrandName() {
    return TEXT("");
}

FString UBlueprintCPPHelperLibrary::GetAppVersion() {
    return TEXT("");
}

FString UBlueprintCPPHelperLibrary::GenerateSafeFileName(FText InputText) {
    return TEXT("");
}

FString UBlueprintCPPHelperLibrary::EncodeSessionPassword(FText Password) {
    return TEXT("");
}

TArray<uint8> UBlueprintCPPHelperLibrary::ConvertColorsToBytes(TArray<FColor> Colors, int32 Size) {
    return TArray<uint8>();
}

int32 UBlueprintCPPHelperLibrary::CompareFText(const FText& A, const FText& B) {
    return 0;
}

int32 UBlueprintCPPHelperLibrary::CompareFString(const FString& A, const FString& B) {
    return 0;
}

int32 UBlueprintCPPHelperLibrary::CompareFName(const FName& A, const FName& B) {
    return 0;
}


