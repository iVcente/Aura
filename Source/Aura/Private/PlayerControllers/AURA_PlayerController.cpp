// Copyright Dancing Man Games. All Rights Reserved.


#include "PlayerControllers/AURA_PlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interfaces/TargetInterface.h"

AAURA_PlayerController::AAURA_PlayerController()
{
	bReplicates = true;
}

void AAURA_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAURA_PlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (!HitResult.IsValidBlockingHit())
	{
		return;
	}
	
	LastActorHitByCursor = CurrentActorHitByCursor;
	CurrentActorHitByCursor = HitResult.GetActor();

	/*
	 * Line trace from cursor. There are several scenarios:
	 *	A. LastActorHitByCursor is null and CurrentActorHitByCursor is null:
	 *		- Do nothing.
     *  B. LastActorHitByCursor is null and CurrentActorHitByCursor is valid:
     *		- Highlight CurrentActorHitByCursor.
     *	C. LastActorHitByCursor is valid and CurrentHighlighted is null:
     *		- UnLight LastActorHitByCursor.
     *	D. Both actors are valid, but LastActorHitByCursor is not equal to CurrentActorHitByCursor:
     *		- UnHighlight LastActorHitByCursor and highlight CurrentActorHitByCursor.
     *	E. Both actors are valid, and are the same actor:
     *		- Do nothing.
	 */

	if (LastActorHitByCursor == nullptr)
	{
		if (CurrentActorHitByCursor != nullptr)
		{
			// Case B
			CurrentActorHitByCursor->HighlightActor();
		}
		else
		{
			// Case A
		}
	}
	else
	{
		if (CurrentActorHitByCursor == nullptr)
		{
			// Case C
			LastActorHitByCursor->UnHighlightActor();
		}
		else
		{
			if (LastActorHitByCursor != CurrentActorHitByCursor)
			{
				// Case D
				LastActorHitByCursor->UnHighlightActor();
				CurrentActorHitByCursor->HighlightActor();
			}
			else
			{
				// Case E
			}
		}
	}
}

void AAURA_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Setup mouse cursor
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Type::Default;

	/* Setup input */

	// Add mapping context
	checkf(InputMappingContext, TEXT("AURA_PlayerController | Invalid value for InputMappingContext variable."));
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	checkf(EnhancedInputLocalPlayerSubsystem, TEXT("AURA_PlayerController | Invalid EnhancedInputLocalPlayerSubsystem."));
	EnhancedInputLocalPlayerSubsystem->AddMappingContext(InputMappingContext, 0);

	// Set input mode
	FInputModeGameAndUI InputData;
	InputData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputData.SetHideCursorDuringCapture(false);
	SetInputMode(InputData);
}

void AAURA_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
}

void AAURA_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation = FRotator(0.0f, GetControlRotation().Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>(); IsValid(ControlledPawn))
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
