// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/SWeapon.h"
#include "SWeaponBase_BP.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API ASWeaponBase_BP : public ASWeapon
{
	GENERATED_BODY()
	
public:
	virtual void FireWeapon() override;

	UPROPERTY(EditAnywhere, Replicated, Category = "Weapon")
	float DamagePreHit;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float GetDamagePreHit() const;

	UPROPERTY(EditAnywhere, Replicated, Category = "Weapon")
	float ShootRange;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	float GetShootRange() const;

	UPROPERTY(EditAnywhere, Replicated, Category = "Weapon")
	int32 ShootInterval;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	int32 GetShootInterval() const;

	UPROPERTY(EditAnywhere, Replicated, Category = "Weapon")
	TSubclassOf<AActor> ProjectileClass;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	TSubclassOf<AActor> GetProjectileClass() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Weapon")
	void BP_Fire(struct FVector const& FromLocation, struct FRotator const& Rotator, float Range, struct FVector const& TargetLocation);
};
