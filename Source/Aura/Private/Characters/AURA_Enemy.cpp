// Copyright Dancing Man Games. All Rights Reserved.

#include "Characters/AURA_Enemy.h"

#include "Aura.h"

AAURA_Enemy::AAURA_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
