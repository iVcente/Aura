// Copyright Dancing Man Games. All Rights Reserved.

#include "HUDs/AURA_HUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/AURA_UserWidget.h"
#include "UI/AURA_WidgetController_Overlay.h"

UAURA_WidgetController_Overlay* AAURA_HUD::GetOverlayWidgetController(const FAURA_WidgetControllerConfig& WidgetControllerConfig)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UAURA_WidgetController_Overlay>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetConfig(WidgetControllerConfig);
		OverlayWidgetController->BindCallbacksToDependencies();
	}

	return OverlayWidgetController;
}

void AAURA_HUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("[%hs] Overlay Widget class not selected. Fill out BP_HUD_Main."), __FUNCTION__);
	checkf(OverlayWidgetControllerClass, TEXT("[%hs] Overlay Widget Controller class not selected. Fill out BP_HUD_Main."), __FUNCTION__);
	
	OverlayWidgetController = GetOverlayWidgetController(FAURA_WidgetControllerConfig(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet));
	
	OverlayWidget = CreateWidget<UAURA_UserWidget>(GetOwningPlayerController(), OverlayWidgetClass);
	OverlayWidget->SetWidgetController(OverlayWidgetController);
	OverlayWidgetController->BroadcastInitialValues();
	OverlayWidget->AddToViewport();
}
