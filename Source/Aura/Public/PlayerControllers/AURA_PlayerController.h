// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AURA_PlayerController.generated.h"

class ITargetInterface;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/**
 * 
 */
UCLASS(Abstract)
class AURA_API AAURA_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
		AAURA_PlayerController();

		virtual void PlayerTick(float DeltaTime) override;

	protected:
		virtual void BeginPlay() override;
	
		virtual void SetupInputComponent() override;

	private:
		UPROPERTY(EditDefaultsOnly, Category = "Input")
		TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

		UPROPERTY(EditDefaultsOnly, Category = "Input")
		TObjectPtr<UInputAction> MoveAction = nullptr;

		void Move(const FInputActionValue& InputActionValue);

		void CursorTrace();

		TScriptInterface<ITargetInterface> LastActorHitByCursor = nullptr;
		TScriptInterface<ITargetInterface> CurrentActorHitByCursor = nullptr;
};
