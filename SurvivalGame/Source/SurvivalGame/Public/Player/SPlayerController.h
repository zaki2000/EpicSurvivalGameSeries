// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/PlayerController.h"
#include "SHUD.h"
#include "SPlayerController.generated.h"

UENUM()
enum class EHUDMessage : uint8
{
	/* Weapons */
	Weapon_SlotTaken,

	/* Character */
	Character_EnergyRestored,

	/* Gamemode */
	Game_SurviveStart,
	Game_SurviveEnded,

	/* No category specified */
	None,
};

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

	ASPlayerController(const FObjectInitializer& ObjectInitializer);

	/* Flag to respawn or start spectating upon death */
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	bool bRespawnImmediately;
	
	/* Respawn or start spectating after dying */
	virtual void UnFreeze() override;

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerSuicide();

	void ServerSuicide_Implementation();

	bool ServerSuicide_Validate();

	virtual void Possess(class APawn* InPawn) override;

public:

	UFUNCTION(Reliable, Client)
	void ClientHUDStateChanged(EHUDState NewState);

	void ClientHUDStateChanged_Implementation(EHUDState NewState);

	/* Enum is remapped to localized text before sending it to the HUD */
	UFUNCTION(Reliable, Client)
	void ClientHUDMessage(EHUDMessage MessageID);

	void ClientHUDMessage_Implementation(EHUDMessage MessageID);

	FText GetText(EHUDMessage MsgID);

	/* Kill the current pawn */
	UFUNCTION(exec)
	virtual void Suicide();

	/* Start spectating. Should be called only on server */
	void StartSpectating();

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
	int32 GetForceID() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
	int32 SetForceID(int32 inForceID);

	UPROPERTY(EditDefaultsOnly, Category = "PlayerCondition", Replicated)
	int32 ForceID = 0;
};
