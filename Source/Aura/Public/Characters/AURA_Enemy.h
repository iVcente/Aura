// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AURA_Character.h"
#include "Interfaces/TargetInterface.h"
#include "AURA_Enemy.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class AURA_API AAURA_Enemy : public AAURA_Character, public ITargetInterface
{
	GENERATED_BODY()
	
	public:
		AAURA_Enemy();
	
		virtual void HighlightActor() override;

		virtual void UnHighlightActor() override;
};
