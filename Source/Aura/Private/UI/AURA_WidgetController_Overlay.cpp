// Copyright Dancing Man Games. All Rights Reserved.


#include "UI/AURA_WidgetController_Overlay.h"

#include "GAS/AURA_AttributeSet.h"

void UAURA_WidgetController_Overlay::BroadcastInitialValues()
{
	const UAURA_AttributeSet* AttributeSet = CastChecked<UAURA_AttributeSet>(Config.AttributeSet);
	
	OnHealthChangedDelegate.Broadcast(AttributeSet->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(AttributeSet->GetMaxHealth());

	OnManaChangedDelegate.Broadcast(AttributeSet->GetMana());
	OnMaxManaChangedDelegate.Broadcast(AttributeSet->GetMaxMana());
}

void UAURA_WidgetController_Overlay::BindCallbacksToDependencies()
{
	const UAURA_AttributeSet* AttributeSet = CastChecked<UAURA_AttributeSet>(Config.AttributeSet);

	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::OnMaxHealthChanged);

	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddUObject(this, &ThisClass::OnManaChanged);
	Config.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute()).AddUObject(this, &ThisClass::OnMaxManaChanged);
}

void UAURA_WidgetController_Overlay::OnHealthChanged(const FOnAttributeChangeData& NewHealth) const
{
	OnHealthChangedDelegate.Broadcast(NewHealth.NewValue);
}

void UAURA_WidgetController_Overlay::OnMaxHealthChanged(const FOnAttributeChangeData& NewMaxHealth) const
{
	OnMaxHealthChangedDelegate.Broadcast(NewMaxHealth.NewValue);
}

void UAURA_WidgetController_Overlay::OnManaChanged(const FOnAttributeChangeData& NewMana) const
{
	OnManaChangedDelegate.Broadcast(NewMana.NewValue);
}

void UAURA_WidgetController_Overlay::OnMaxManaChanged(const FOnAttributeChangeData& NewMaxMana) const
{
	OnMaxManaChangedDelegate.Broadcast(NewMaxMana.NewValue);
}
