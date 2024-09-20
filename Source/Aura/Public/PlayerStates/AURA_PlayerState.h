// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AURA_PlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS(Abstract)
class AURA_API AAURA_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

	public:
		AAURA_PlayerState();

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
