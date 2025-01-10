// Copyright Dancing Man Games. All Rights Reserved.


#include "Characters/AURA_Aura.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "HUDs/AURA_HUD.h"
#include "PlayerControllers/AURA_PlayerController.h"
#include "PlayerStates/AURA_PlayerState.h"


AAURA_Aura::AAURA_Aura()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 750.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void AAURA_Aura::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// GAS | Initialize it for the server
	InitializeGas();

	InitializeHUD();
}

void AAURA_Aura::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// GAS | Initialize it for the client
	InitializeGas();

	InitializeHUD();
}

void AAURA_Aura::InitializeGas()
{
	AAURA_PlayerState* AuraPlayerState = GetPlayerStateChecked<AAURA_PlayerState>();
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}

void AAURA_Aura::InitializeHUD()
{
	if (IsLocallyControlled())
	{
		APlayerController* PlayerController = Cast<APlayerController>(GetController());
		AAURA_HUD* HUD = Cast<AAURA_HUD>(PlayerController->GetHUD());
		AAURA_PlayerState* AuraPlayerState = Cast<AAURA_PlayerState>(GetPlayerState());

		HUD->InitOverlay(PlayerController, AuraPlayerState, AuraPlayerState->GetAbilitySystemComponent(), AuraPlayerState->GetAttributeSet());
	}
}
