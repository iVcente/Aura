// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AURA_Character.generated.h"

UCLASS(Abstract)
class AURA_API AAURA_Character : public ACharacter
{
	GENERATED_BODY()

	public:
		AAURA_Character();

	protected:
		virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, Category = "Combat")
		TObjectPtr<USkeletalMeshComponent> Weapon = nullptr;
};
