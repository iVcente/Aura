// Copyright Dancing Man Games. All Rights Reserved.


#include "PlayerStates/AURA_PlayerState.h"

#include "GAS/AURA_AbilitySystemComponent.h"
#include "GAS/AURA_AttributeSet.h"

AAURA_PlayerState::AAURA_PlayerState()
{
	// Setup GAS
	NetUpdateFrequency = 100.0f;

	AbilitySystemComponent = CreateDefaultSubobject<UAURA_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAURA_AttributeSet>(TEXT("AttributeSet"));
}
