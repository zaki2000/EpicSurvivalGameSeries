#include "SurvivalGame.h"
#include "SurvivalGameTool.h"

void USurvivalGameTool::ClientTravelByCommandLine(UObject* WorldContextObject)
{
    FString URL("127.0.0.1:7777");
    if (WorldContextObject && FParse::Value(FCommandLine::Get(), TEXT("serverip="), URL))
    {
        UWorld* World = WorldContextObject->GetWorld();
        if (World)
        {
            auto PlayerController = World->GetFirstPlayerController();
            if (PlayerController)
            {
                PlayerController->ClientTravel(URL, ETravelType::TRAVEL_Relative);
            }            
        }
    }
}