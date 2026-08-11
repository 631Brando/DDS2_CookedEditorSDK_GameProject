#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OceanologyWave_1.h"
#include "OceanologyWave_2.h"
#include "OceanologyWave_3.h"
#include "OceanologyWave_4.h"
#include "OceanologyWavesHelper.generated.h"

class UMaterialInstanceDynamic;
class UMaterialParameterCollectionInstance;
class UNiagaraComponent;

UCLASS(Blueprintable)
class UOceanologyWavesHelper : public UObject {
    GENERATED_BODY()
public:
    UOceanologyWavesHelper();

    UFUNCTION(BlueprintCallable)
    static void SetNiagaraVariablesWave_4(UNiagaraComponent* Niagara, const FOceanologyWave_4& Wave_4);
    
    UFUNCTION(BlueprintCallable)
    static void SetNiagaraVariablesWave_3(UNiagaraComponent* Niagara, const FOceanologyWave_3& Wave_3);
    
    UFUNCTION(BlueprintCallable)
    static void SetNiagaraVariablesWave_2(UNiagaraComponent* Niagara, const FOceanologyWave_2& Wave_2);
    
    UFUNCTION(BlueprintCallable)
    static void SetNiagaraVariablesWave_1(UNiagaraComponent* Niagara, const FOceanologyWave_1& Wave_1);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParametersWave_4(UMaterialInstanceDynamic* Mid, const FOceanologyWave_4& Wave_4);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParametersWave_3(UMaterialInstanceDynamic* Mid, const FOceanologyWave_3& Wave_3);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParametersWave_2(UMaterialInstanceDynamic* Mid, const FOceanologyWave_2& Wave_2);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParametersWave_1(UMaterialInstanceDynamic* Mid, const FOceanologyWave_1& Wave_1);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameterCollectionsWave_4(UMaterialParameterCollectionInstance* MPCI, const FOceanologyWave_4& Wave_4);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameterCollectionsWave_3(UMaterialParameterCollectionInstance* MPCI, const FOceanologyWave_3& Wave_3);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameterCollectionsWave_2(UMaterialParameterCollectionInstance* MPCI, const FOceanologyWave_2& Wave_2);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialParameterCollectionsWave_1(UMaterialParameterCollectionInstance* MPCI, const FOceanologyWave_1& Wave_1);
    
    UFUNCTION(BlueprintPure)
    static void LerpWave_4(const FOceanologyWave_4& A, const FOceanologyWave_4& B, const double Alpha, FOceanologyWave_4& OutResult);
    
    UFUNCTION(BlueprintPure)
    static void LerpWave_3(const FOceanologyWave_3& A, const FOceanologyWave_3& B, const double Alpha, FOceanologyWave_3& OutResult);
    
    UFUNCTION(BlueprintPure)
    static void LerpWave_2(const FOceanologyWave_2& A, const FOceanologyWave_2& B, const double Alpha, FOceanologyWave_2& OutResult);
    
    UFUNCTION(BlueprintPure)
    static void LerpWave_1(const FOceanologyWave_1& A, const FOceanologyWave_1& B, const double Alpha, FOceanologyWave_1& OutResult);
    
};

