// Copyright Dancing Man Games. All Rights Reserved.

#include "GAS/AURA_EffectApplicator.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "GAS/AURA_AttributeSet.h"

AAURA_EffectApplicator::AAURA_EffectApplicator()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	SetRootComponent(Sphere);
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

void AAURA_EffectApplicator::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack to cast away the constness. Obviously, avoid this!
	if (OtherActor->Implements<UAbilitySystemInterface>())
	{
		const UAbilitySystemComponent* AbilitySystemComponent = Cast<IAbilitySystemInterface>(OtherActor)->GetAbilitySystemComponent();
		const UAURA_AttributeSet* AttributeSet = Cast<UAURA_AttributeSet>(AbilitySystemComponent->GetAttributeSet(UAURA_AttributeSet::StaticClass()));
		UAURA_AttributeSet* MutableAttributeSet = const_cast<UAURA_AttributeSet*>(AttributeSet);
		MutableAttributeSet->SetHealth(AttributeSet->GetHealth() + 25.0f);

		Destroy();
	}
}

void AAURA_EffectApplicator::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AAURA_EffectApplicator::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnOverlapEnd);
}
