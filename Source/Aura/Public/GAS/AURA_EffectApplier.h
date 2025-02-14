// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AURA_EffectApplier.generated.h"

class UGameplayEffect;

UENUM(BlueprintType)
enum class EAURA_EffectApplicationPolicy : uint8
{
	ApplyOnBeginOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EAURA_EffectRemovalPolicy : uint8
{
	RemoveOnBeginOverlap,
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAURA_EffectApplier : public AActor
{
	GENERATED_BODY()

	public:
		AAURA_EffectApplier();

	protected:
		virtual void BeginPlay() override;

		UFUNCTION(BlueprintCallable, Category = "Effects")
		void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

		UFUNCTION(BlueprintCallable, Category = "Effects")
		void OnBeginOverlap(AActor* TargetActor);

		UFUNCTION(BlueprintCallable, Category = "Effects")
		void OnEndOverlap(AActor* TargetActor);

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		bool bDestroyOnEffectRemoval = false;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		TSubclassOf<UGameplayEffect> InstantGameplayEffectClass = nullptr;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		EAURA_EffectApplicationPolicy InstantGameplayEffectApplicationPolicy = EAURA_EffectApplicationPolicy::DoNotApply;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		TSubclassOf<UGameplayEffect> DurationGameplayEffectClass = nullptr;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		EAURA_EffectApplicationPolicy DurationGameplayEffectApplicationPolicy = EAURA_EffectApplicationPolicy::DoNotApply;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass = nullptr;
	
		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		EAURA_EffectApplicationPolicy InfiniteGameplayEffectApplicationPolicy = EAURA_EffectApplicationPolicy::DoNotApply;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects")
		EAURA_EffectRemovalPolicy InfiniteGameplayEffectRemovalPolicy = EAURA_EffectRemovalPolicy::DoNotRemove;
};
