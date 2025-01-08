// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AURA_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAURA_UserWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable)
		void SetWidgetController(UObject* NewWidgetController);
	
		UObject* GetWidgetController() const
		{
			return WidgetController;
		}

	protected:
		UFUNCTION(BlueprintImplementableEvent)
		void OnWidgetControllerSet();

	private:
		TObjectPtr<UObject> WidgetController = nullptr;
};
