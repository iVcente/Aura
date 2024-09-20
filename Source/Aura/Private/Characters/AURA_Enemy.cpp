// Copyright Dancing Man Games. All Rights Reserved.

#include "Characters/AURA_Enemy.h"

#include "Aura.h"
#include "GAS/AURA_AbilitySystemComponent.h"
#include "GAS/AURA_AttributeSet.h"

AAURA_Enemy::AAURA_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// Setup GAS
	AbilitySystemComponent = CreateDefaultSubobject<UAURA_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAURA_AttributeSet>(TEXT("AttributeSet"));
}

void AAURA_Enemy::HighlightActor()
{
	// Highlight enemy mesh
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	// Highlight enemy weapon mesh
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAURA_Enemy::UnHighlightActor()
{
	// UnHighlight enemy mesh
	GetMesh()->SetRenderCustomDepth(false);

	// UnHighlight enemy weapon mesh
	Weapon->SetRenderCustomDepth(false);
}
