// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GAS/AURA_AttributeSet.h"
#include "UObject/Object.h"
#include "AURA_WidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FAURA_WidgetControllerConfig
{
	GENERATED_BODY()

	FAURA_WidgetControllerConfig()
	{
		
	}

	FAURA_WidgetControllerConfig(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet):
		PlayerController(PlayerController), PlayerState(PlayerState), AbilitySystemComponent(AbilitySystemComponent), AttributeSet(AttributeSet)
	{
		
	}
	
	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

/**
 * 
 */
UCLASS()
class AURA_API UAURA_WidgetController : public UObject
{
	GENERATED_BODY()

	public:
		virtual void BroadcastInitialValues();

		virtual void BindCallbacksToDependencies();
	
		UFUNCTION(BlueprintCallable, Category = "Widget Controller")
		void SetConfig(const FAURA_WidgetControllerConfig& WidgetControllerConfig);
	
	protected:
		UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
		FAURA_WidgetControllerConfig Config;
};
