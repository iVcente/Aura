// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AURA_AttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAURA_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
	public:
		UAURA_AttributeSet();

		virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
		UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;

		UFUNCTION()
		void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

		UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_MaxHealth)
		FGameplayAttributeData MaxHealth;

		UFUNCTION()
		void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

		UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_Mana)
		FGameplayAttributeData Mana;

		UFUNCTION()
		void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

		UPROPERTY(BlueprintReadOnly, Category = "Vital Attributes", ReplicatedUsing = OnRep_MaxMana)
		FGameplayAttributeData MaxMana;

		UFUNCTION()
		void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
};
