// Copyright Dancing Man Games. All Rights Reserved.


#include "UI/AURA_WidgetController_Overlay.h"

#include "GAS/AURA_AttributeSet.h"

void UAURA_WidgetController_Overlay::BroadcastInitialValues()
{
	const UAURA_AttributeSet* AttributeSet = CastChecked<UAURA_AttributeSet>(Config.AttributeSet);
	
	OnHealthChangedDelegate.Broadcast(AttributeSet->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(AttributeSet->GetMaxHealth());
}
