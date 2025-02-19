// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AURA_Character.h"
#include "AURA_Aura.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS(Abstract)
class AURA_API AAURA_Aura : public AAURA_Character
{
	GENERATED_BODY()

	public:
		AAURA_Aura();

		virtual void PossessedBy(AController* NewController) override;

		virtual void OnRep_PlayerState() override;

	protected:
		UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> SpringArm = nullptr;
	
		UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> Camera = nullptr;

	private:
		void InitializeGas();

		void InitializeHUD();
};
