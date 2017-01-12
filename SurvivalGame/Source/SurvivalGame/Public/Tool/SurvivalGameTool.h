#pragma once

#include "SurvivalGameTool.generated.h"


UCLASS()
class SURVIVALGAME_API USurvivalGameTool : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SurvivalGameTool", meta = (WorldContext = "WorldContextObject"))
    static void ClientTravelByCommandLine(UObject* WorldContextObject, const FString& CommandParam, const FString& DefaultURL);
};