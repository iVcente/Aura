// Copyright Dancing Man Games. All Rights Reserved.

#include "HUDs/AURA_HUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/AURA_UserWidget.h"

void AAURA_HUD::BeginPlay()
{
	Super::BeginPlay();

	OverlayWidget = CreateWidget<UAURA_UserWidget>(GetOwningPlayerController(), OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
