// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AURA_Character.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class AURA_API AAURA_Character : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	public:
		AAURA_Character();

	protected:
		virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, Category = "Combat")
		TObjectPtr<USkeletalMeshComponent> Weapon = nullptr;

	#pragma region GAS

		public:

			#pragma region IAbilitySystemInterface
	
				virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
				{
					return AbilitySystemComponent;
				}

			#pragma endregion IAbilitySystemInterface

			UAttributeSet* GetAttributeSet() const
			{
				return AttributeSet;	
			}
	
		protected:
			UPROPERTY()
			TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

			UPROPERTY()
			TObjectPtr<UAttributeSet> AttributeSet = nullptr;
	
	#pragma endregion GAS
};
