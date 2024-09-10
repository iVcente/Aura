// Copyright Dancing Man Games. All Rights Reserved.

#include "Characters/AURA_Character.h"


AAURA_Character::AAURA_Character()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

void AAURA_Character::BeginPlay()
{
	Super::BeginPlay();
}
