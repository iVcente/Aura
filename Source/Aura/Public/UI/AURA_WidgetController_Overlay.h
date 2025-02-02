// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AURA_WidgetController.h"
#include "AURA_WidgetController_Overlay.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAURA_OnHealthChanged, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAURA_OnMaxHealthChanged, float, NewMaxHealth);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAURA_WidgetController_Overlay : public UAURA_WidgetController
{
	GENERATED_BODY()

	public:
		virtual void BroadcastInitialValues() override;

		virtual void BindCallbacksToDependencies() override;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes", DisplayName = "On Health Changed")
		FAURA_OnHealthChanged OnHealthChangedDelegate;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes", DisplayName = "On Max Health Changed")
		FAURA_OnMaxHealthChanged OnMaxHealthChangedDelegate;

	protected:
		void OnHealthChanged(const FOnAttributeChangeData& NewHealth) const;

		void OnMaxHealthChanged(const FOnAttributeChangeData& NewMaxHealth);
};
