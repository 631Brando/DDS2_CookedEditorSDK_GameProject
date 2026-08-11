#pragma once
#include "CoreMinimal.h"
#include "SaleCalendarData.h"
#include "SortSaleCalendarDataPredicateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FSortSaleCalendarDataPredicate, const FSaleCalendarData&, A, const FSaleCalendarData&, B);

