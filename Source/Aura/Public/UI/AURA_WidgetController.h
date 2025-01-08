// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AURA_WidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API UAURA_WidgetController : public UObject
{
	GENERATED_BODY()

	protected:
		UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
		TObjectPtr<APlayerController> PlayerController = nullptr;

		UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
		TObjectPtr<APlayerState> PlayerState = nullptr;

		UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
		TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

		UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
		TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};
