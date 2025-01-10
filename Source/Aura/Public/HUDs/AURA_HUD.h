// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AURA_HUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UAURA_UserWidget;
class UAURA_WidgetController;
class UAURA_WidgetController_Overlay;
struct FAURA_WidgetControllerConfig;

/**
 * 
 */
UCLASS()
class AURA_API AAURA_HUD : public AHUD
{
	GENERATED_BODY()

	public:
		UPROPERTY()
		TObjectPtr<UAURA_UserWidget> OverlayWidget = nullptr;

		UAURA_WidgetController_Overlay* GetOverlayWidgetController(const FAURA_WidgetControllerConfig& WidgetControllerConfig);

		void InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState, UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet);

	protected:
		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UAURA_UserWidget> OverlayWidgetClass;

		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UAURA_WidgetController_Overlay> OverlayWidgetControllerClass;

	private:
		UPROPERTY()
		TObjectPtr<UAURA_WidgetController_Overlay> OverlayWidgetController = nullptr;
};
