// Copyright Dancing Man Games. All Rights Reserved.


#include "UI/AURA_WidgetController_Overlay.h"

#include "GAS/AURA_AttributeSet.h"

void UAURA_WidgetController_Overlay::BroadcastInitialValues()
{
	const UAURA_AttributeSet* AttributeSet = CastChecked<UAURA_AttributeSet>(Config.AttributeSet);
	
	OnHealthChangedDelegate.Broadcast(AttributeSet->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(AttributeSet->GetMaxHealth());

	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute());
}

void UAURA_WidgetController_Overlay::BindCallbacksToDependencies()
{
	const UAURA_AttributeSet* AttributeSet = CastChecked<UAURA_AttributeSet>(Config.AttributeSet);

	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::OnMaxHealthChanged);
}

void UAURA_WidgetController_Overlay::OnHealthChanged(const FOnAttributeChangeData& NewHealth) const
{
	OnHealthChangedDelegate.Broadcast(NewHealth.NewValue);
}

void UAURA_WidgetController_Overlay::OnMaxHealthChanged(const FOnAttributeChangeData& NewMaxHealth)
{
	OnMaxHealthChangedDelegate.Broadcast(NewMaxHealth.NewValue);
}
