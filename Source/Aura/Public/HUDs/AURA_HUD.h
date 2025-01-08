// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AURA_HUD.generated.h"

class UAURA_UserWidget;

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

	protected:
		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UAURA_UserWidget> OverlayWidgetClass;

		virtual void BeginPlay() override;
};
