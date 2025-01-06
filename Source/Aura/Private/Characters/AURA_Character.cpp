// Copyright Dancing Man Games. All Rights Reserved.

#include "Characters/AURA_Character.h"

#include "AbilitySystemComponent.h"
#include "PlayerStates/AURA_PlayerState.h"


AAURA_Character::AAURA_Character()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}
