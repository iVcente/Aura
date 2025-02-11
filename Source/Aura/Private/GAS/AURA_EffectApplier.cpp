// Copyright Dancing Man Games. All Rights Reserved.

#include "GAS/AURA_EffectApplier.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

AAURA_EffectApplier::AAURA_EffectApplier()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void AAURA_EffectApplier::BeginPlay()
{
	Super::BeginPlay();
}

void AAURA_EffectApplier::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	checkf(GameplayEffectClass != nullptr, TEXT("[%hs] Invalid Gameplay Effect class."), __FUNCTION__);
	
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

	if (TargetAbilitySystemComponent != nullptr)
	{
		FGameplayEffectContextHandle GameplayEffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
		GameplayEffectContextHandle.AddSourceObject(this);

		const FGameplayEffectSpecHandle GameplayEffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.0f, GameplayEffectContextHandle);

		TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GameplayEffectSpecHandle.Data.Get());
	}
}
