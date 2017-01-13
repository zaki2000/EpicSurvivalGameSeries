// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SurvivalGame.h"
#include "SWeaponBase_BP.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"


void ASWeaponBase_BP::FireWeapon()
{
	const FVector AimDir = GetAdjustedAim();
	const FVector CameraPos = GetCameraDamageStartLocation(AimDir);
	FVector EndPos = CameraPos + (AimDir * ShootRange);

	/* Check for impact by tracing from the camera position */
	FHitResult Impact = WeaponTrace(CameraPos, EndPos);
	FVector StartPos = CameraPos;
	const FVector MuzzleOrigin = GetMuzzleLocation();
	FVector AdjustedAimDir = AimDir;
	if (Impact.bBlockingHit)
	{
		/* Adjust the shoot direction to hit at the crosshair. */
		AdjustedAimDir = (Impact.ImpactPoint - MuzzleOrigin).GetSafeNormal();
		StartPos = MuzzleOrigin;
		EndPos = MuzzleOrigin + (AdjustedAimDir * ShootRange);
	}

	const FRotator rotator = UKismetMathLibrary::FindLookAtRotation(StartPos, EndPos);
	BP_Fire(StartPos, rotator, ShootRange, EndPos, Instigator);
}

float ASWeaponBase_BP::GetDamagePreHit() const
{
	return DamagePreHit;
}

float ASWeaponBase_BP::GetShootRange() const
{
	return ShootRange;
}

int32 ASWeaponBase_BP::GetShootInterval() const
{
	return ShootInterval;
}

TSubclassOf<AActor> ASWeaponBase_BP::GetProjectileClass() const
{
	return ProjectileClass;
}

void ASWeaponBase_BP::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASWeaponBase_BP, DamagePreHit);
	DOREPLIFETIME(ASWeaponBase_BP, ShootRange);
	DOREPLIFETIME(ASWeaponBase_BP, ShootInterval);
	DOREPLIFETIME(ASWeaponBase_BP, ProjectileClass);
}