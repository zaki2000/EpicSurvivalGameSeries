#include "SurvivalGame.h"
#include "SurvivalGameTool.h"

void USurvivalGameTool::ClientTravelByCommandLine(UObject* WorldContextObject, const FString& CommandParam, const FString& DefaultURL)
{
	FString URL;
	if (!FParse::Value(FCommandLine::Get(), *CommandParam, URL))
	{
		URL = DefaultURL;
	}

    if (WorldContextObject && URL.Len() > 0)
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