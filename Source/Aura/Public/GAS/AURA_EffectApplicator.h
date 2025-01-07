// Copyright Dancing Man Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AURA_EffectApplicator.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AAURA_EffectApplicator : public AActor
{
	GENERATED_BODY()

	public:
		AAURA_EffectApplicator();

		UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

		UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	protected:
		virtual void BeginPlay() override;

	private:
		UPROPERTY(VisibleAnywhere)
		TObjectPtr<USphereComponent> Sphere;

		UPROPERTY(VisibleAnywhere)
		TObjectPtr<UStaticMeshComponent> Mesh;
};
