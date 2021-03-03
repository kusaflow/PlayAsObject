// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "laser_base.generated.h"
#define ECC_laserTrace ECC_GameTraceChannel1

UCLASS()
class PLAYASOBJECT_API Alaser_base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Alaser_base();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "meshes", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* laserBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "meshes", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* laserPoint;

	bool bShouldRef;

	float traceLaser;

	float laserBounce = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser", meta = (AllowPrivateAccess = "true"))
	float traceLen = 1000;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AlaserMesh> lm;

	TArray<class AlaserMesh*> lm_array;

	class AlaserGates_base* laserGate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
		void printV(FVector vec,float f);

};
