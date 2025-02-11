// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AURA_EffectApplier.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAURA_EffectApplier : public AActor
{
	GENERATED_BODY()

	public:
		AAURA_EffectApplier();

	protected:
		virtual void BeginPlay() override;

		UFUNCTION(BlueprintCallable, Category = "Effects")
		void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

		UPROPERTY(EditDefaultsOnly, Category = "Effects")
		TSubclassOf<UGameplayEffect> InstantGameplayEffectClass = nullptr;
};
